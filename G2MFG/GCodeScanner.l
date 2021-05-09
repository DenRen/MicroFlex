%option yyclass="gcode::GLexer"
%option noyywrap
%option c++

%{

#include "GCodeLexer.hpp"

%}

NL              \n+
WS              [ \t]+
DIGIT           [0-9]
DIGIT1          [1-9]
NUMBER          {DIGIT1}{DIGIT}*|0
FLOAT_NUMBER    ({NUMBER}?\.{DIGIT1}+)|{NUMBER}

GCODE   G{NUMBER}
MCODE   M{NUMBER}

COORD   [XYZ]{FLOAT_NUMBER}
SPEED   F{FLOAT_NUMBER}

%%

{WS}            /* Skip blanks and tabs */
{NL}            return process_new_line ();

{GCODE}         return process_Gcmd ();
{MCODE}         return process_Mcmd ();

{COORD}         return process_coord ();
{SPEED}         return process_speed ();

"%"             return process_percent ();
.               return procces_unexpected_cmd ();

%%