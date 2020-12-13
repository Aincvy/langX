//
// Created by Aincvy(aincvy@gmail.com) on 2020/12/12.
//

#include "langXCommon.h"
#include "ScriptModule.h"
#include "langX.h"
#include "ClassInfo.h"
#include "langXObject.h"
#include "XNameSpace.h"
#include "NullObject.h"
#include "StringType.h"
#include "Allocator.h"
#include "langXThread.h"
#include "Environment.h"
#include "TypeHelper.h"

namespace langX {

    ScriptModule::ScriptModule() {

    }

    ScriptModule::ScriptModule(const char *pkgPath, langXState *state)
            : m_packagePath(pkgPath) {
        this->m_state = state;
    }

    ScriptModule::~ScriptModule() {

        // 释放包秒数信息得对象
        if (this->m_packageObject) {
            // Allocator::freeObject(this->m_packageObject);
            this->m_packageObject = nullptr;
        }

        // 释放其他内容

    }

    const char *ScriptModule::getName() const {
        return getStringFromObject(this->m_packageObject, "name");
    }

    const char *ScriptModule::getDescription() const {
        return getStringFromObject(this->m_packageObject, "description");
    }

    const char *ScriptModule::getAuthor() const {
        return getStringFromObject(this->m_packageObject, "author");
    }

    const char *ScriptModule::getVersion() const {
        return getStringFromObject(this->m_packageObject, "version");
    }

    const char *ScriptModule::getRepository() const {
        return getStringFromObject(this->m_packageObject, "repository");
    }

    const char *ScriptModule::getEntrypoint() const {
        return getStringFromObject(this->m_packageObject, "entrypoint");
    }


    int ScriptModule::loadPackageScript() {
        if (this->m_packageObject) {
            return 1;
        }

        if (!this->m_packagePath) {
            return 2;
        }

        char buf[DEFAULT_CHAR_BUFFER_SIZE] = {0};
        sprintf(buf, "%s/package.lx", this->m_packagePath);

        //
        auto classInfo = m_state->getClassByFullName("langX.rt.ScriptModule");
        this->m_packageObject = Allocator::newObject(classInfo, false, true);

        // 给当前线程增加执行环境，  一层对象环境， 一层默认环境
        auto thread = m_state->curThread();
        thread->newEnvByBridge(m_packageObject->getObjectEnvironment());

        DefaultEnvironment env;
        thread->newEnv(&env);

        // 执行 脚本
        m_state->doFile(buf);

        // 先回退默认得环境， 之后再回退对象环境
        thread->backEnv(false);
        thread->backEnv();

        return 0;

    }

    int ScriptModule::executeEntrypoint() {
        auto entrypoint = getEntrypoint();
        if (entrypoint == nullptr) {
            return 1;
        }

        char buf[DEFAULT_CHAR_BUFFER_SIZE] = {0};
        sprintf(buf, "%s/%s", this->m_packagePath, entrypoint);

        this->m_state->doFile(buf);

        return 0;
    }

    const char *ScriptModule::getPackagePath() const {
        return this->m_packagePath;
    }

    void ScriptModule::setPackagePath(const char *path) {
        this->m_packagePath = path;
    }

    ModuleType ScriptModule::getModuleType() const {
        return Script;
    }

    int ScriptModule::unload(langXState *) {
        return 0;
    }

    int ScriptModule::init(langXState *) {
        return 0;
    }

    void *ScriptModule::getSoObj() const {
        return nullptr;
    }


    void initScriptModuleClassInfo(langXState *state) {

        // 命名空间， 以及类信息

        // 初始化类相关得信息
        auto classInfo = new ClassInfo("ScriptModule");

        NullObject nullObject;
        classInfo->addMember("name", &nullObject);
        classInfo->addMember("description", &nullObject);
        classInfo->addMember("author", &nullObject);
        classInfo->addMember("version", &nullObject);
        classInfo->addMember("repository", &nullObject);
        classInfo->addMember("entrypoint", Allocator::allocateString("main.lx"));

        // 把类放入 langX.rt 命名空间里面
        auto ns = state->getNameSpaceOrCreate("langX.rt");
        ns->putClass(classInfo);


    }


}