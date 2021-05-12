#pragma once

#include "../GCode/GCodeLexer.hpp"
#include "../InverseKinematic/kinematic.hpp"

namespace mf {

enum class MFGCMD_ID {
    EMPTY = 0, G, M, PHI0, PHI1, PHI2, F, PERCENT
};

class mfgcmd {
public:

private:

    MFGCMD_ID cmd_id_;
public: // Hack
    int32_t value_;

public:
    mfgcmd (MFGCMD_ID cmd_id = MFGCMD_ID::EMPTY, int32_t value = 0);

    MFGCMD_ID GetId () const;
    int32_t GetValue () const;
    void dump (std::ostream& out = std::cout) const;
};


using frame_t  = std::vector <mfgcmd>;
using frames_t = std::vector <frame_t>;

class mfgprogram {
    frames_t frames;

public:
    mfgprogram (const gcode::gprogram& gprog, kinematic& kinem);

    void dump (std::ostream& output = std::cout);
    frames_t::const_iterator begin ();
    frames_t::const_iterator end ();
};

}