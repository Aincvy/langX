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
      void init(const char*);

    private:
      // 默认的日志输出
      log4cpp::Category* m_category;
      // 节点日志的内容
      log4cpp::Category* m_nodeCategory;

  };

  extern log4cpp::Category *logger;
  extern log4cpp::Category *nodeLogger;

};


#endif /* !LOGMANAGER_H */

