//
// Created by Aincvy on 2020/9/28.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tclap/CmdLine.h>

#include "Program.h"
#include "langXCommon.h"
#include "NodeCreator.h"
#include "langX.h"

extern int getParseLineNo();
extern int column;
extern char * yytext;

void yyerror(const char *s) {
    fprintf(stderr, "%s on file %s line %d,column %d. near by '%s' \n", s , getParsingFilename() , getParseLineNo(), column , yytext );

}


int programRun(int argc, char *argv[]){
    if(argc <= 1){
        printf("no input file.\n");
        return 1;
    }

    // 获取启动参数
    // 脚本文件和 给予脚本文件的参数
    std::vector<std::string> fileAndArgs;
    // 额外增加得 脚本 module
    std::vector<std::string> addModules;

    struct langX::langXStateConfig stateConfig;

    try {
        TCLAP::CmdLine cmdLine("langX - a simple script language.", ' ', LANGX_VERSION);

        TCLAP::SwitchArg disableAllModulesArg("","disable-all-modules","Disable all modules, do not load any modules.",false);
        cmdLine.add(disableAllModulesArg);

        TCLAP::SwitchArg disableLoadModulesArg("","disable-load-modules","Disable load modules from config file. ",false);
        cmdLine.add(disableLoadModulesArg);

        TCLAP::MultiArg<std::string> addModuleArg("A", "add-module", "Add a script module.", false,"string" );
        cmdLine.add(addModuleArg);

        // file name and args
        TCLAP::UnlabeledMultiArg<std::string> multiArg("file", "script file and file args", true, "string");
        cmdLine.add(multiArg);

        cmdLine.parse(argc, argv);


        fileAndArgs = multiArg.getValue();
        if (addModuleArg.isSet()) {
             addModules = addModuleArg.getValue();
        }
        if (disableAllModulesArg.isSet()) {
            stateConfig.disableAllModules = disableAllModulesArg.getValue();
        }
        if (disableLoadModulesArg.isSet()) {
            stateConfig.disableLoadModules = disableLoadModulesArg.getValue();
        }

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

    initLangX(langXArgc, langXArgv, stateConfig);

    // 加载 script module...
    for (auto i = addModules.begin(); i != addModules.end() ; ++i) {
        // printf("module: %s\n" , i->c_str());
        auto path = i->c_str();
        getState()->loadScriptModule(path);
    }

    // 执行脚本内容
    const char * scriptFile = fileAndArgs[0].c_str();
    doFile(scriptFile);

    closeLangX();

    // 释放 参数的内容
    for (int i = 0; i < langXArgc; ++i) {
        free(langXArgv[i]);
    }

    return 0;
}