#include <stdlib.h>
#include <string.h>

#include "X3rdModule.h"
#include "LogManager.h"
#include "langX.h"

namespace langX {

	X3rdModule::X3rdModule()
	{
		this->m_name = nullptr;
	}

	X3rdModule::~X3rdModule()
	{
	    // 清理 日志类 占用的内存
        if (this->m_logger) {
            delete this->m_logger;
            this->m_logger = nullptr;
        }


	}

	int X3rdModule::init(langXState *)
	{
		return 0;
	}

	int X3rdModule::unload(langXState *)
	{
		return 0;
	}
	const char * X3rdModule::getName() const
	{
		return this->m_name;
	}
	void X3rdModule::setName(const char *name)
	{
		if (!name)
		{
			return;
		}

        freeLastName();

		this->m_name = strdup(name);
	}
	void X3rdModule::setSoObj(void * soObj)
	{
		this->m_soObj = soObj;
	}
	void * X3rdModule::getSoObj() const
	{
		return this->m_soObj;
	}
	void X3rdModule::freeLastName()
	{
		if (m_name)
		{
			free(m_name);
			m_name = nullptr;
		}
	}

    Logger *X3rdModule::getLogger() {
        return this->m_logger;
    }

    void X3rdModule::initLogger(langXState *state) {
        if (this->m_logger == nullptr) {
            this->m_logger = state->getLogManager()->requireNewModuleLogger();
        }

        this->m_logger->setPrefix(this->m_name);
    }


}