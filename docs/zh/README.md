# langX

解释型脚本语言， 创作的目的是快速开发。 

本项目正在开发中， 不要将本项目用于生产环境中。 

你可以用本项目来进行学习，和个人开发的批处理操作。 （简单来说，就是完成一些一次性行为。）

## 特点

- 弱类型， 解释型脚本语言。
- 随意的语法。
- 桥接别的语言的库。
- 使用者具有较大的权限 修改较多的内容。
- 没有 `private` 保护数据不被修改。



## 编辑器和文档

**编辑器**

使用 **Atom** 作为编辑器.

[langX-atom](https://github.com/Aincvy/langX-atom.git) 插件, 用于语法高亮（还在开发中）。 这个插件不支持自动完成。   

**文档**

[langX in Gitbook](https://aincvy.gitbook.io/langx/v/dev/langs)



## 简单的代码示例

```
// a.lx
// 注释

// 声明函数
funa => {
	a = 1 ;
	funb();

	// println是一个内置函数
	println("funa" + a);
}

funb => {
  println("funb: " + a);
  a = 101 ;
}

// 调用函数
funa();

```



```
// b.lx

// 声明类
Student {

  // 类的成员
  name;
  age = 20 ;

  // 类的函数
  a => { print("hello,a!\n");}

  printInfo => (a3){ print("name: " + name + "\n");  print("age: " + age + "\n" ); print("a3: " + a3 + "\n");}

}

// new 一个对象
s2 = new Student();
s1 = s2;

// 设置对象的属性
s1.age = 10 ;
s1.name = "Mr.Ming";
b = s2.age;
c = s2.name;
/*print("b: " + b + "\n");
//print("c: " + c + "\n");  */

s1.a();
s1.printInfo("ahahahah~");

```

### 截图

https://github.com/Aincvy/langX-atom#screenshot



## 目录

1. `3rd`
   1. 一个简单的notepad++ 的配置文件（语法高亮）
2. `cmake`
   1. `cmake` 的配置文件. (**.cmake*)
3. `docs`
   1. 文档. (中文和英文版本的.)
4. `extern`
   1. Lex 和 yacc 的文件.
   2. Lex 和 yacc 生成的文件.
5. `include`
   1. 头文件.
6. `source`
   1. 源代码文件.
7. `lib`
   1. 第三方库的源代码文件。
   2. 这个文件夹在不久的将来会被删除
8. `mod`
   1. 目前没意义。
9. `modProjects`
   1. langX mods
   2. core/mysql/python-bridge/redis/...
10. `rtlib`
    1. 运行时的库. (还在工作中)。
    2. 可能全部使用langX编写。
11. `scripts`
    1. 测试脚本。
    2. 示例脚本。
12. `notImplementation`
    1. 没有实现的一些想法。



## 编译和安装

1. 请先阅读`依赖库`小节。

2. 安装 `flex`,`bison`,`log4cpp`.  

   1. Mac
      1. `brew install flex`
      2. `brew install bison`
      3. `brew install log4cpp`
   2. Debian
      1. 待补充.

3. 安装 `cmake`.

4. ```shell
   mkdir build && cd build
   cmake ..
   make
   sudo make install 
   ```

5. 现在，最简单的启动程序已经好了，你可以使用 `langX [filename]` 来测试.

6. 注意: langX程序目前没有任何选项 (**包括 --version**)。

7. 你现在可以尝试编译 mod列表了。 



## 依赖库

### 简单的可运行程序

- flex
- yacc(bison)
- Log4cpp

### lib core

- Nothing



### lib mysql

- mysql-devel (mysql-connector-c)



### lib python

- python-devel



### lib redis

- hiredis



### lib zip

- zlib



### lib json

- cjson



## Others

**欢迎提交PR和Issue**

