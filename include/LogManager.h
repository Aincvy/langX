/*************************************************************************************//**
 *  @file       LogManager.h
 *
 *  @brief      Brief description of LogManager.h
 *
 *  @date       2018-02-27 15:35
 *         
 **************************************************************************************/


#ifndef LOGMANAGER_H
#define LOGMANAGER_H

#include <log4cpp/Category.hh>

namespace langX{

  class LogManager{

    public:

      LogManager();
      ~LogManager();

      // 初始化日志管理器
      void init();

    private:
      log4cpp::Layout* m_layout;
      log4cpp::Appender* m_appender;
      log4cpp::Category* m_category;

  };
  extern log4cpp::Category *logger;

};


#endif /* !LOGMANAGER_H */

