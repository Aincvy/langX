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

	log4cpp::Category *logger = nullptr;
	log4cpp::Category *nodeLogger = nullptr;

	LogManager::LogManager() {
		this->m_category = nullptr;
	};

	LogManager::~LogManager() {
		// 析构函数

	};

	void LogManager::init(const char *path) {
		log4cpp::PropertyConfigurator::configure(path);
		log4cpp::Category& root = log4cpp::Category::getInstance("console");
		this->m_category = &root;
		langX::logger = this->m_category;

		// node
		auto & tmp = log4cpp::Category::getInstance("node");
		this->m_nodeCategory = &tmp;
        langX::nodeLogger = m_nodeCategory;
	}

}