//
// Created by Yo Hello on 2020/9/28.
//

#include "../include/Program.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "../include/YLlangX.h"
#include <tclap/CmdLine.h>

#define YYDEBUG 1


extern int getParseLineNo();
extern int column;
extern char * yytext;

void yyerror(char *s) {
    fprintf(stderr, "%s on file %s line %d,column %d. near by '%s' \n", s , getParsingFilename() , getParseLineNo(),column , yytext );

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

    // 获取启动参数


    try {
        TCLAP::CmdLine cmdLine("langX - a simple script language.", ' ', LANGX_VERSION);

        // test name
        TCLAP::ValueArg<std::string> testArg("n","name", "name to print", false, "default", "string");
        cmdLine.add(testArg);

        cmdLine.parse(argc, argv);

        std::string name = testArg.getValue();
        if (testArg.isSet()){
            printf("test arg is set!\n");
        } else{
            printf("test arg is not set!\n");
        }

        printf("test arg: %s\n", name.c_str());
    } catch (TCLAP::ArgException &e) {
        // parse exception
        fprintf(stderr, "error pass arg: %s\n%s\n", e.argId().c_str(), e.error().c_str());
        return -1;
    }

    initLangX(argc, argv);

    doFile(argv[1]);

    closeLangX();

    return 0;
}