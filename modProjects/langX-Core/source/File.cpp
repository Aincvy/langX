#include <iostream>
#include <fstream>
#include <string.h>

#include "../include/RegCoreModule.h"
#include "../include/CoreFileStream.h"

#include "../../../include/ClassInfo.h"
#include "../../../include/YLlangX.h"
#include "../../../include/Object.h"
#include "../../../include/langXObject.h"
#include "../../../include/langXObjectRef.h"
#include "../../../include/Allocator.h"
#include "../../../include/Number.h"
#include "../../../include/StringType.h"

namespace langX {


  Object * langX_File_appendLines(X3rdFunction *func, const X3rdArgs &args) {
    if (args.object == nullptr)
    {
      printf("langX_File_appendLines error! NO OBJ!\n");
      return nullptr;
    }

    return nullptr;
  }



  Object * langX_File_appendText(X3rdFunction *func, const X3rdArgs &args) {

    Object * a = args.args[0];
    Object * b = args.args[1];
    if (a && a->getType() == STRING  && b && b->getType() == STRING)
    {
      const char * path = ((String*)a)->getValue();
      std::ofstream fout(path , std::ios::app );
      if (!fout)
      {
        // TODO 抛出文件未找到异常
        return Allocator::allocateNumber(-1);
      }

      int s = fout.tellp();
      fout << ((String*)b)->getValue();
      int e = fout.tellp();

      fout.flush();
      fout.close();

      return Allocator::allocateNumber( (e-s) );
    }

    return nullptr;
  }


  Object * langX_File_readLines(X3rdFunction *func, const X3rdArgs &args) {

    Object * a = args.args[0];
    if (a && a->getType() == STRING)
    {
      const char * path = ((String*)a)->getValue();
      std::ifstream fin(path);
      if (!fin)
      {
        // TODO 抛出文件未找到异常
        return Allocator::allocate(NULLOBJECT);
      }

      langXObject *ret = Allocator::newObject("langX.core.util.List",true);
      std::list<Object*> * list = (std::list<Object*> *)ret->get3rdObj();
      for( std::string line; getline( fin, line ); )
      {
        list->push_back(Allocator::allocateString(line.c_str()));
      }

      return ret->addRef();
    }

    return nullptr;
  }



  Object * langX_File_readText(X3rdFunction *func, const X3rdArgs &args) {

    Object * a = args.args[0];
    if (a && a->getType() == STRING)
    {
      const char * path = ((String*)a)->getValue();
      std::ifstream fin(path , std::ios::in | std::ios::binary | std::ios::ate);
      if (!fin)
      {
        // TODO 抛出文件未找到异常
        return Allocator::allocate(NULLOBJECT);
      }

      long size;
      size = fin.tellg();
      fin.seekg(0, std::ios::beg);

      char * buf = (char*)calloc(1, size);
      if (!buf)
      {
        //  抛出内存不够异常
        return Allocator::allocate(NULLOBJECT);
      }

      fin.read(buf, size);
      fin.close();

      String * str = Allocator::allocateString(buf);

      free(buf);

      return str;

    }

    return nullptr;
  }



  Object * langX_File_writeLines(X3rdFunction *func, const X3rdArgs &args) {
    if (args.object == nullptr)
    {
      printf("langX_File_writeLines error! NO OBJ!\n");
      return nullptr;
    }

    return nullptr;
  }


  //  写入成功返回 写入的字节数，  写入失败 返回-1   参数错误返回 null
  Object * langX_File_writeText(X3rdFunction *func, const X3rdArgs &args) {

    Object * a = args.args[0];
    Object * b = args.args[1];
    if (a && a->getType() == STRING  && b && b->getType() == STRING)
    {
      const char * path = ((String*)a)->getValue();
      std::ofstream fout(path );
      if (!fout)
      {
        // TODO 抛出文件未找到异常
        return Allocator::allocateNumber(-1);
      }

      String *str = ((String*)b);
      str->simpleEscape();

      fout << str->getValue();
      int size = fout.tellp();

      fout.flush();
      fout.close();

      return Allocator::allocateNumber(size);
    }

    return nullptr;
  }



  Object * langX_File_openAppend(X3rdFunction *func, const X3rdArgs &args) {
    Object * a = args.args[0];
    if (a && a->getType() == STRING)
    {
      const char * path = ((String*)a)->getValue();

      CoreFileStream *cfs = createCoreFileStream();
      cfs->cppFStream.open(path, std::ios::app);

      return createFileStreamObj(cfs)->addRef();
    }


    return Allocator::allocate(NULLOBJECT);
  }



  Object * langX_File_openWrite(X3rdFunction *func, const X3rdArgs &args) {
    Object * a = args.args[0];
    if (a && a->getType() == STRING)
    {
      const char * path = ((String*)a)->getValue();

      CoreFileStream *cfs = createCoreFileStream();
      cfs->cppFStream.open(path, std::ios::out);

      return createFileStreamObj(cfs)->addRef();
    }


    return Allocator::allocate(NULLOBJECT);
  }



  Object * langX_File_openRead(X3rdFunction *func, const X3rdArgs &args) {

    Object * a = args.args[0];
    if (a && a->getType() == STRING)
    {
      const char * path = ((String*)a)->getValue();

      CoreFileStream *cfs = createCoreFileStream();
      cfs->cppFStream.open(path, std::ios::in);

      return createFileStreamObj(cfs)->addRef();
    }


    return Allocator::allocate(NULLOBJECT);
  }



  int regFile(langXState *state, XNameSpace* space) {

    ClassInfo *info = new ClassInfo("File");
    info->addFunction("appendLines", create3rdFunc("appendLines", langX_File_appendLines));
    info->addFunction("appendText", create3rdFunc("appendText", langX_File_appendText));
    info->addFunction("readLines", create3rdFunc("readLines", langX_File_readLines));
    info->addFunction("readText", create3rdFunc("readText", langX_File_readText));
    info->addFunction("writeLines", create3rdFunc("writeLines", langX_File_writeLines));
    info->addFunction("writeText", create3rdFunc("writeText", langX_File_writeText));
    info->addFunction("openAppend", create3rdFunc("openAppend", langX_File_openAppend));
    info->addFunction("openWrite", create3rdFunc("openWrite", langX_File_openWrite));
    info->addFunction("openRead", create3rdFunc("openRead", langX_File_openRead));

    space->putClass(info);

    return 0;
  }
}


