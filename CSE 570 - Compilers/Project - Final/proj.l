
%{
#include <stdlib.h>
#include "proj.h"
#include "y.tab.h"

void yyerror(char *);
%}

%%

[A-Z]       { 
                yylval.sIndex = *yytext - 'A';
                return VARIABLE;
            }

0           {
                yylval.iValue = atoi(yytext);
                return INTEGER;
            }

[1-9][0-9]* {
                yylval.iValue = atoi(yytext);
                return INTEGER;
            }

[-()<>=+*/;{}.] {
                return *yytext;
             }

">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"WHILE"         return WHILE;
"IF"            return IF;
"PRINT"         return PRINT;
"GOTO"          return GOTO;
"END"           return END;
"THEN"          return THEN;

[ \t\n]+        ;       /* ignore whitespace */

.               yyerror("Unknown character");
%%
int yywrap(void) {
    return 1;
}
