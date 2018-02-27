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

namespace langX{

  log4cpp::Category *logger = NULL;

  LogManager::LogManager(){
    this->m_layout = NULL;
    this->m_appender = NULL;
    this->m_category = NULL;
  }; 

  LogManager::~LogManager(){
    // 析构函数
    
  };

  void LogManager::init(){
    log4cpp::PropertyConfigurator::configure("log4cpp.properties");
    log4cpp::Category& root = log4cpp::Category::getRoot();
    this->m_category = &root;
    langX::logger = this->m_category;
  }

}


