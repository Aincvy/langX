//
// Created by Yo Hello on 2020/9/28.
//

#ifndef LANGX_PROGRAM_H
#define LANGX_PROGRAM_H

#define LANGX_VERSION "0.2.1"

extern "C" {
    extern int yylex(void);
    void yyerror(char *);
}

/**
 * 启动程序
 * @return
 */
int programRun(int argc, char **args);

/**
 * 拼接命名空间
 * @return
 */
char *namespaceNameCat(char *,char *);

#endif //LANGX_PROGRAM_H
