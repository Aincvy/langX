//
// Created by Yo Hello on 2020/9/28.
//

#include "../include/Program.h"
#include "../include/langXCommon.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "../include/NodeCreator.h"
#include <tclap/CmdLine.h>



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
    // 脚本文件和 给予脚本文件的参数
    std::vector<std::string> fileAndArgs;

    try {
        TCLAP::CmdLine cmdLine("langX - a simple script language.", ' ', LANGX_VERSION);

        // test name
        TCLAP::ValueArg<std::string> testArg("n","name", "name to print (test code, will delete)", false, "default", "string");
        cmdLine.add(testArg);

        // file name and args
        TCLAP::UnlabeledMultiArg<std::string> multiArg("file", "script file and file args", true, "string");
        cmdLine.add(multiArg);

        cmdLine.parse(argc, argv);

//        std::string name = testArg.getValue();

        fileAndArgs = multiArg.getValue();

    } catch (TCLAP::ArgException &e) {
        // parse exception
        fprintf(stderr, "error pass arg: %s\n%s\n", e.argId().c_str(), e.error().c_str());
        return -1;
    }

    // 使用 fileAndArgs 转换成langX 脚本的运行参数
    auto langXArgc = fileAndArgs.size() - 1;
    char* langXArgv[langXArgc];
    for (int i = 1; i <= langXArgc; ++i) {
        auto str = fileAndArgs[i];
        char* tmp = (char*)calloc(1, sizeof(char) * str.size());
        strcpy(tmp, str.c_str());
        langXArgv[i - 1] = tmp;
    }

    initLangX(langXArgc, langXArgv);

    const char * scriptFile = fileAndArgs[0].c_str();
    doFile(scriptFile);

    closeLangX();

    // 释放 参数的内容
    for (int i = 0; i < langXArgc; ++i) {
        free(langXArgv[i]);
    }

    return 0;
}