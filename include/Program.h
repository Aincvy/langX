//
// Created by Yo Hello on 2020/9/28.
//

#ifndef LANGX_PROGRAM_H
#define LANGX_PROGRAM_H



extern "C" {
    extern int yylex(void);
    void yyerror(const char *);
}

/**
 * 启动程序
 * @return
 */
int programRun(int argc, char **args);

#endif //LANGX_PROGRAM_H
