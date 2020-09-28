//
// Created by Yo Hello on 2020/9/28.
//

#include "../include/Program.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "../include/YLlangX.h"

#define YYDEBUG 1


extern int getParseLineNo();
extern int column;
extern char * yytext;

void yyerror(char *s) {
    fprintf(stderr, "%s on file %s line %d,column %d. near by '%s' \n", s , getParsingFilename() , getParseLineNo(),column , yytext  );
}

char *namespaceNameCat(char *arg1,char *arg2){
    int len = strlen(arg1) + strlen(arg2) + 1;
    char *p = (char*)calloc(1, len + 1);
    strcat(p,arg1);
    strcat(p,".");
    strcat(p,arg2);
    p[len] = '\0' ;

    free(arg1);
    free(arg2);
    return p;
}


int programRun(int argc, char *argv[]){
    if(argc <= 1){
        printf("no input file.\n");
        return 1;
    }

    initLangX(argc, argv);


    doFile(argv[1]);

    closeLangX();

    return 0;
}