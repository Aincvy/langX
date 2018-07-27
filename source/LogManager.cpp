/************************************************************************************//**
 *  @file       LogManager.cpp
 *
 *  @brief      Brief descriptinon of LogManager.cpp
 *
 *  @date       2018-02-27 15:42
 *
 ***************************************************************************************/

#include "../include/LogManager.h"
#include <log4cpp/PropertyConfigurator.hh>

namespace langX {
	log4cpp::Category *logger = NULL;

	LogManager::LogManager() {
		this->m_category = NULL;
	};

	LogManager::~LogManager() {
		// 析构函数
	};

	void LogManager::init(const char *path) {
		log4cpp::PropertyConfigurator::configure(path);
		log4cpp::Category& root = log4cpp::Category::getRoot();
		this->m_category = &root;
		langX::logger = this->m_category;
	}
}