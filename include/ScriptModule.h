//
// Created by Aincvy(aincvy@gmail.com) on 2020/12/12.
//

#pragma once




//  下面内容是 思绪得草稿内容

// 注册一个类， 然后使用一个对象对象环境， 一个常规环境作为执行环境， 去加载 package.lx 得到脚本的描述信息
// 更新到cpp层面的类信息， 这样可能就得维护两套机制，  所以使用一个壳也行  cpp做一个壳
// 获取到 package.lx得信息之后， 就可以执行 entry 属性了
// 执行结束之后， 这个包里面得类应该都已经注册了， 命名空间也已经加入了
// 这里可能想做一个中间表示比如 ScriptModule  和 X3rdModule 区分。 以作为中间表示
// 只是这里可能还有一些问题， 即 这种结构下 执行包里得脚本之后，所有得信息都会直接写入 全局空间。
// 如果想先弄一个隔离空间得话， 似乎也可以。。  阻断掉？   但是线程得部分， 似乎没有进行阻断。
// 如果 到顶层空间还没有发现得话， 可能就会执行全局空间得内容。。   但是如果阻断得话，也很怪异。。 在脚本得顶层就无法执行全局空间得函数， 也无法和其他库进行交互。。
// 所以，我 不应该阻断他。。
// 让我们简单一些， 先做一个 ScriptModule 得中间表示。  关于阻断得事情，我们后面在考虑
// 可能在  langX 空间也需要访问 ScriptModule 得属性
// 其次， doFile, requireFile 之类得函数， 需不需要返回一个脚本空间得引用？  includeFile 不需要， 这个是在当前得脚本环境里面执行得
// 再其次， 我是否要先休息 doFile 之类得函数？
// 其他。  我可以在简单流程处理结束之后，增加一层中间层， 用于桥接 本体得空间内容， 和脚本包得内容。 不过这个可以等到考虑把脚本打包得时候使用。

// langXrtlib.cpp 里面也没多少内容， 删掉重新写把。。


// todo 尽量将脚本都加载到 ScriptModule 里面。。
//


#include "langX.h"

namespace langX{

    class langXObject;

    /**
     * 脚本模块，  使用一个文件夹， 或者一个
     */
    class ScriptModule : public langXModule {

    public:

        ScriptModule();
        ~ScriptModule();

        ScriptModule(const char* pkgPath, langXState* state);


        ModuleType getModuleType() const override;

        /**
         * 获取当前模块得名字
         * @return
         */
        const char* getName() const override;

        /**
         * 获取当前模块得 描述内容
         * @return
         */
        const char* getDescription() const override;

        /**
         * 获取当前模块得 作者
         * @return
         */
        const char* getAuthor() const override;

        /**
         * 获取当前模块得版本字符串
         * @return
         */
        const char* getVersion() const override;

        /**
         * 获取当前模块得 源代码仓库位置
         * @return
         */
        const char* getRepository() const override;

        /**
         * 获取当前模块得入口点
         * @return
         */
        const char* getEntrypoint() const override;

        /**
         * 加载脚本包得  package.lx 脚本
         * @param path
         * @return   0 成功加载， 1 已经加载过了，  2没有设置包得路径
         */
        int loadPackageScript() ;

        /**
         * 执行 入口点得 脚本
         * @return  0 成功执行
         */
        int executeEntrypoint();

        /**
         * 获取 脚本包所在得路径
         * @return
         */
        const char* getPackagePath() const;

        /**
         * 设置脚本包所在得路径
         * @param path
         */
        void setPackagePath(const char *path);


        void * getSoObj() const override;

        int unload(langXState *) override;

        int init(langXState *) override;


    private:

        // package.lx 脚本对应得内容
        langXObject* m_packageObject = nullptr;
        // 脚本所在得目录
        const char* m_packagePath = nullptr;

    };


    /**
     * 初始化 scriptModule 需要得类信息
     * @param state
     */
    void initScriptModuleClassInfo(langXState *state);


}