%option noyywrap
%option c++

%{

#include "GCodeGrammar.tab.hh"

%}


WS              [ \n\t\v\r]+
DIGIT           [0-9]
DIGIT1          [1-9]
NUMBER          {DIGIT1}{DIGIT}*|0
FLOAT_NUMBER    {NUMBER}?\.{DIGIT1}+

GCODE   G{NUMBER}{COORDS}
MCODE   M{NUMBER}

%%

{WS}            /* Skip blanks and tabs */
"G"             return yy::parser::token_type::GCODE;
{NUMBER}        return yy::parser::token_type::NUMBER;
.               return yy::parser::token_type::ERR;

%%