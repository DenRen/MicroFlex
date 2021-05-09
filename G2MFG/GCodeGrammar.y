%language "c++"

%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%param {yy::GCodeDriver* driver}

%code requires
{
#include <iostream>
#include <string>
#include <vector>

#include "GCodeDriver.hpp"

// forward decl of argument to parser
namespace yy { class GCodeDriver; }
}

%code
{
    
namespace yy {
    parser::token_type yylex(parser::semantic_type* yylval,                         
                             GCodeDriver* driver);
}
}
    
%token
    NEWLINE "\n"
;

%token <int>   NUMBER
%token <float> FLOAT_NUMBER
%token <int>   GCODE
%nterm <Igcode*> cmd_id
%nterm <std::vector <Igcode*>> frame
%nterm <std::vector<std::vector<Igcode*>>> commands

%start program

%%

program: commands                { driver->insert ($1); }
;

commands: frame NEWLINE commands { $$ = $3; $3.push_back ($1); }
        | frame NEWLINE { $$.push_back ($1); }
        ;

frame:      cmd_id               { $$.push_back ($1); }
;

cmd_id:     GCODE NUMBER         { $$ = new gcode <int>   (CMD_ID::G, $2); }
        |   GCODE FLOAT_NUMBER   { $$ = new gcode <float> (CMD_ID::G, $2); }
;

%%

namespace yy {

parser::token_type yylex (parser::semantoc_type* yylval,
                          GCodeDriver* driver) {
    return driver->yylex (yylval);
}

void parser::error (const std::string& str_err) {
    std::cerr << "I get error! " << str_err << std::endl;
}

}