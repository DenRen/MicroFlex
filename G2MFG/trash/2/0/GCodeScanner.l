%option noyywrap
%option c++

%{

#include "GCodeGrammar.tab.hh"

%}

NL              \n+
WS              [ \t\v\r]+
DIGIT           [0-9]
DIGIT1          [1-9]
NUMBER          {DIGIT1}{DIGIT}*|0
FLOAT_NUMBER    {NUMBER}?\.{DIGIT1}+

GCODE   G{NUMBER}{COORDS}
MCODE   M{NUMBER}

%%

{WS}        /* Skip blanks and tabs */
{NL}            return yy::parser::token_type::NEWLINE;
"G"             return yy::parser::token_type::GCODE;
"M"             return yy::parser::topke_type::MCODE;
[XYZ]           return yy::parser::topke_type::COORD;
F               return yy::parser::topke_type::OPTF;
{NUMBER}        return yy::parser::topke_type::NUMBER;
{FLOAT_NUMBER}  return yy::parser::topke_type::FLOAT_NUMBER;
"%"             return yy::parser::topke_type::PERCENT;
.               return yy::parser::topke_type::ERR;

%%