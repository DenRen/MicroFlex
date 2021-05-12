#pragma once

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#include <iostream>
#include <cstring>
#include <vector>

namespace gcode {

enum class GCMD_ID {
    EMPTY = 0, G, M, X, Y, Z, F, PERCENT
};

class gcmd {
public:

private:
    GCMD_ID cmd_id_;

    union {
        int32_t uval;
        float fval;
    } value_;

public:
    gcmd (GCMD_ID cmd_id = GCMD_ID::EMPTY, int32_t value = 0);
    gcmd (GCMD_ID cmd_id, float value = 0.0f);

    GCMD_ID GetId () const;
    int32_t GetUnsignedValue () const;
    float GetFloatValue () const;

    void dump (std::ostream& out = std::cout) const;
};

using frame_t  = std::vector <gcmd>;
using frames_t = std::vector <frame_t>;

class gprogram {
    frames_t frames;
    frames_t::iterator cur_frame;

public:
    gprogram ();

    void add_command (const gcmd& comamnd);
    void add_new_line ();
    void dump (std::ostream& output = std::cout);

    size_t size () const;
    frames_t::const_iterator begin () const;
    frames_t::const_iterator end () const;
};

class GLexer : public yyFlexLexer {

    gprogram* gprog = nullptr;

    bool prog_started = false;

    int process_Gcmd ();
    int process_Mcmd ();

    int process_coord ();
    int process_speed ();

    int process_percent ();
    int process_new_line ();
    int procces_unexpected_cmd ();

    void add_uint_cmd  (GCMD_ID cmd_id, const std::string& str_val);
    void add_float_cmd (GCMD_ID cmd_id, const std::string& str_val);

public:

    GLexer (std::istream& input  = std::cin, std::ostream& output = std::cout);

    int yylex () override;
    gprogram& parse ();
};

} // namespace gcode