//Michael Smith
//CSE 570
//Spring 2018

#include <stdio.h>
#include "proj.h"
#include "y.tab.h"

int temp1;
int temp2;

int ex(nodeType *p) {
       
    
    if (!p) return 0;
    switch(p->type) {
    case typeCon:       return p->con.value;
    case typeId:        return sym[p->id.i];
    case typeOpr:
        switch(p->opr.oper) {
        case GOTO:     
                        return ex(p->opr.op[0]);      
        case IF:        if (ex(p->opr.op[0]))
                        {    ex(p->opr.op[1]);
                           
                        temp1 = ex(p->opr.op[0]);
                        temp2 = ex(p->opr.op[1]);
                        fprintf(yyout, "if(%d){\n\t%d;\n}", temp1, temp2); 
                        }    
         //modified             
        case PRINT:     fprintf(yyout, "printf(\"%%d\",");
                        fprintf(yyout, "%d);", ex(p->opr.op[0]));
                        fprintf(yyout, "\n");
                        fprintf(yyout, "printf(\"\\n\");");
                        break;
        case ';':       ex(p->opr.op[0]); return ex(p->opr.op[1]);
        case '=':       return sym[p->opr.op[0]->id.i] = ex(p->opr.op[1]);
        case UMINUS:    return -ex(p->opr.op[0]);
        case '+':       return ex(p->opr.op[0]) + ex(p->opr.op[1]);
        case '-':       return ex(p->opr.op[0]) - ex(p->opr.op[1]);
        case '*':       return ex(p->opr.op[0]) * ex(p->opr.op[1]);
        case '/':       return ex(p->opr.op[0]) / ex(p->opr.op[1]);
        case '<':       return ex(p->opr.op[0]) < ex(p->opr.op[1]);
        case '>':       return ex(p->opr.op[0]) > ex(p->opr.op[1]);
        case GE:        return ex(p->opr.op[0]) >= ex(p->opr.op[1]);
        case LE:        return ex(p->opr.op[0]) <= ex(p->opr.op[1]);
        case NE:        return ex(p->opr.op[0]) != ex(p->opr.op[1]);
        case EQ:        return ex(p->opr.op[0]) == ex(p->opr.op[1]);
        }
    }
    fprintf(yyout, "\nreturn 0; \n}");
    return 0;
}
