//Michael Smith
//CSE 570
//Spring 2018

%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdarg.h>
#include "proj.h"

/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);

void yyerror(char *s);
int sym[26];                    /* symbol table */

extern FILE *yyin;
extern FILE *yyout;
%}

%union {
    int iValue;                 /* integer value */
    char sIndex;                /* symbol table index */
    nodeType *nPtr;             /* node pointer */
};

%token <iValue> INTEGER
%token <sIndex> VARIABLE 
%token WHILE IF PRINT GOTO END
%nonassoc IFX
%nonassoc THEN

%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%type <nPtr> stmt expr term factor logic line block

%%

program:    block                         { exit(0); }
            | ;

block:      block line                   
            | line                                                  
            |;
                
line:
            INTEGER stmt   { ex($2); freeNode($2); } 
            |;

stmt:
          ';'                            { $$ = opr(';', 2, NULL, NULL); }
        | expr ';'                       { $$ = $1; }
        | PRINT expr ';'                 { $$ = opr(PRINT, 1, $2); }
        | VARIABLE '=' expr ';'          { $$ = opr('=', 2, id($1), $3); }
        | GOTO expr ';'                  { $$ = opr(GOTO, 1, $2); }
        | IF expr THEN stmt              { $$ = opr(IF, 2, $2, $4); }
        | END ';'                        { return 0; }
        ;

expr:
          expr '+' term                  { $$ = opr('+', 2, $1, $3); }
        | expr '-' term                  { $$ = opr('-', 2, $1, $3); }
        | logic                          { $$ = $1;}
        | term;
        
term:        
        | term '*' factor                { $$ = opr('*', 2, $1, $3); }
        | term '/' factor                { $$ = opr('/', 2, $1, $3); }
        | factor;

factor:    
        VARIABLE                         { $$ = id($1); }
        | INTEGER                        { $$ = con($1); }   
        | '('expr')'                     { $$ = $2; };
        
logic:         
         expr '<' expr                   { $$ = opr('<', 2, $1, $3); }
        | expr '>' expr                  { $$ = opr('>', 2, $1, $3); }
        | expr GE expr                   { $$ = opr(GE, 2, $1, $3); }
        | expr LE expr                   { $$ = opr(LE, 2, $1, $3); }
        | expr NE expr                   { $$ = opr(NE, 2, $1, $3); }
        | expr EQ expr                   { $$ = opr(EQ, 2, $1, $3); };
        
%%


nodeType *con(int value) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *id(int i) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = i;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

int main(int argc, char *argv[]) {

    yyin = fopen(argv[1], "r");
    char * temp = argv[1];
    char * filename = (char*)malloc(sizeof(char)*((sizeof(temp)/sizeof(char))-1));
    
    //create .c file
    int i = 0;
    while(temp[i] != '.'){
        filename[i] = temp[i];
        i++;
    }  
    filename[i] = '.';
    filename[i+1] = 'c';
    
    yyout = fopen(filename, "w");
    fprintf(yyout, "#include <stdio.h>\n\nint main(){\n");
    free(filename);
    /***/
    
    yyparse();
    fprintf(yyout, "}");
    fclose(yyout);
    fclose(yyin);
    return 0;
}
