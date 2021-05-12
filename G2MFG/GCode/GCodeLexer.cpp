#include "GCodeLexer.hpp"

#include <fstream>
#include <stdexcept>

namespace gcode {

gcmd::gcmd (GCMD_ID cmd_id, int32_t value) :
    cmd_id_ (cmd_id)
{
    value_.uval = value;
}

gcmd::gcmd (GCMD_ID cmd_id, float value) :
    cmd_id_ (cmd_id)
{
    value_.fval = value;
}

GCMD_ID gcmd::GetId () const {
    return cmd_id_;
}

int32_t gcmd::GetUnsignedValue () const {
    return value_.uval;
}

float gcmd::GetFloatValue () const {
    return value_.fval;
}

void gcmd::dump (std::ostream& out) const {
    out << "id[" << static_cast <int> (cmd_id_) << "]: " 
        << "uint: " << value_.uval << ", float: " << value_.fval; 
}

// ---------------------------------------------------

GCMD_ID str2coord (std::string& str) {
    switch (str[0])
    {
    case 'X':
        return GCMD_ID::X;
    case 'Y':
        return GCMD_ID::Y;
    case 'Z':
        return GCMD_ID::Z;
    default:
        throw std::runtime_error ("Error to parce coord symbol");
    }
}

// ---------------------------------------------------

gprogram::gprogram () {
    add_new_line ();
}

void gprogram::add_command (const gcmd& comamnd) {
    cur_frame->push_back (comamnd);
}

void gprogram::add_new_line () {
    frames.push_back (frame_t (0));
    cur_frame = frames.end () - 1;
}

void gprogram::dump (std::ostream& output) {
    std::cout << "Number line: " << frames.size () << std::endl;

    for (auto frame : frames) {
        for (auto cmd : frame)
            cmd.dump ();

        output << std::endl;
    }
}


GLexer::GLexer (std::istream& input, std::ostream& output) :
    yyFlexLexer (input, output)
{}

static int32_t str2uint (const std::string& str) {
    return static_cast <unsigned> (std::stoi (str));
}
static float str2float (const std::string& str) {
    return static_cast <float> (std::stof (str));
}

void GLexer::add_uint_cmd  (GCMD_ID cmd_id, const std::string& str_val) {
    gprog->add_command (gcmd (cmd_id, str2uint (str_val)));
}

void GLexer::add_float_cmd (GCMD_ID cmd_id, const std::string& str_val) {
    gprog->add_command (gcmd (cmd_id, str2float (str_val)));
}

int GLexer::process_Gcmd () {
    const std::string str_num = &yytext[1];

    add_uint_cmd (GCMD_ID::G, str_num);

    return 1;
}

int GLexer::process_Mcmd () {
    const std::string str_num = &yytext[1];

    add_uint_cmd (GCMD_ID::M, str_num);

    return 1;
}

int GLexer::process_coord () {
    std::string cur_lexem = yytext;
    const std::string str_num = &yytext[1];

    GCMD_ID cmd_id = str2coord (cur_lexem);
    add_float_cmd (cmd_id, str_num);

    return 1;
}

int GLexer::process_speed () {
    const std::string str_num = &yytext[1];
    
    add_float_cmd (GCMD_ID::F, str_num);

    return 1;
}

int GLexer::process_percent () {
    prog_started = !prog_started;

    add_uint_cmd (GCMD_ID::PERCENT, "0");

    return 1;
}

int GLexer::procces_unexpected_cmd () {
    std::string cur_lexem = yytext;
    std::string str_err = std::string ("Unexpected command: ") + cur_lexem;

    throw std::runtime_error (str_err);

    return 1;
 }

int GLexer::process_new_line () {
    gprog->add_new_line ();

    return 1;
}

gprogram& GLexer::parse () {

    gprog = new gprogram;

    while (yylex ())
        {}

    return *gprog;
}

size_t gprogram::size () const {
    return frames.size ();
}

frames_t::const_iterator gprogram::begin () const {
    return frames.begin ();
}

frames_t::const_iterator gprogram::end () const {
    return frames.end ();
}


}