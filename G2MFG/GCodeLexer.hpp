#pragma once

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#include <iostream>
#include <cstring>
#include <vector>

namespace gcode {

enum class CMD_ID {
    EMPTY = 0, G, M, X, Y, Z, F, PERCENT
};

class gcmd {
public:

private:

    CMD_ID cmd_id_;

    union {
        unsigned uval;
        float fval;
    } value_;

public:
    gcmd (CMD_ID cmd_id = CMD_ID::EMPTY, unsigned value = 0) :
        cmd_id_ (cmd_id)
    {
        value_.uval = value;
    }

    gcmd (CMD_ID cmd_id, float value = 0.0f) :
        cmd_id_ (cmd_id)
    {
        value_.fval = value;
    }

    CMD_ID GetId () const {
        return cmd_id_;
    }

    void dump (std::ostream& out = std::cout) const {
        out << "id[" << static_cast <int> (cmd_id_) << "]: " 
        << "uint: " << value_.uval << ", float: " << value_.fval; 
    }
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

    void add_uint_cmd  (CMD_ID cmd_id, const std::string& str_val);
    void add_float_cmd (CMD_ID cmd_id, const std::string& str_val);

public:

    GLexer (std::istream& input  = std::cin, std::ostream& output = std::cout);

    int yylex () override;
    gprogram& parse ();
};

} // namespace gcode