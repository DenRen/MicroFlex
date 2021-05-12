#include "MFGCode.hpp"

namespace mf {

mfgcmd::mfgcmd (MFGCMD_ID cmd_id, int32_t value) :
    cmd_id_ (cmd_id)
{
    value_ = value;
}

MFGCMD_ID mfgcmd::GetId () const {
    return cmd_id_;
}

void mfgcmd::dump (std::ostream& out) const {
    out << "id[" << static_cast <int> (cmd_id_) << "]: " << value_ << std::endl; 
}

static frame_t _convert_G28_g2mfg (const gcode::frame_t& gframe) {
    frame_t frame (1);
    frame[0] = mfgcmd (MFGCMD_ID::G, 28);

    return frame;
}

static bool _is_correct_G1 (const gcode::frame_t& gframe) {
    return gframe.size () == 4 && 
           gframe[1].GetId () == gcode::GCMD_ID::X,
           gframe[2].GetId () == gcode::GCMD_ID::Y,
           gframe[3].GetId () == gcode::GCMD_ID::Z;
}

static int32_t _convert_coord (float coord) {
    return static_cast <int32_t> (1000000 * coord);
}

static frame_t _convert_G1_g2mfg (const gcode::frame_t& gframe, kinematic& kinem) {
    if (_is_correct_G1 (gframe) == false)
        throw std::invalid_argument ("Invalid G1 command format");

    const float x = gframe[1].GetFloatValue ();
    const float y = gframe[2].GetFloatValue ();
    const float z = gframe[3].GetFloatValue ();

    vect_t vect_phi = kinem.calc_angle (x, y, z);

    frame_t frame (4);
    frame[0] = mfgcmd (MFGCMD_ID::G, 1);

    frame[1] = mfgcmd (MFGCMD_ID::PHI0, _convert_coord (vect_phi(0)));
    frame[2] = mfgcmd (MFGCMD_ID::PHI1, _convert_coord (vect_phi(1)));
    frame[3] = mfgcmd (MFGCMD_ID::PHI2, _convert_coord (vect_phi(2)));

    return frame;
}

static frame_t _convert_g2mfg (const gcode::frame_t& gframe, kinematic& kinem) {
    gcode::GCMD_ID cmd_id = gframe[0].GetId ();
    switch (cmd_id)
    {
        case gcode::GCMD_ID::G: {
            const int32_t value = gframe[0].GetUnsignedValue ();
            switch (value) {
                case 1:
                    return _convert_G1_g2mfg (gframe, kinem);
                case 28:
                    return _convert_G28_g2mfg (gframe);
                default:
                    throw std::invalid_argument ("Incorrect G value");   
            }
        }
        default:
            throw std::invalid_argument ("Incorrect GCode");
    }
}

mfgprogram::mfgprogram (const gcode::gprogram& gprog, kinematic& kinem) :
    frames (gprog.size ())
{
    for (auto it_gframe = gprog.begin (); it_gframe != gprog.end (); ++it_gframe)
        frames.push_back (_convert_g2mfg (*it_gframe, kinem));
}

void mfgprogram::dump (std::ostream& output) {
    std::cout << "Number line: " << frames.size () << std::endl;

    for (auto frame : frames) {
        for (auto cmd : frame)
            cmd.dump ();

        output << std::endl;
    }
}

int32_t mfgcmd::GetValue () const {
    return value_;
}

frames_t::const_iterator mfgprogram::begin () {
    return frames.begin ();
}

frames_t::const_iterator mfgprogram::end () {
    return frames.end ();
}

}