# 计划中需要实现的特性

**已经实现的特性会从本文档中移出。**



## Extend Method    拓展方法

### 头脑风暴

```
random => ( l ) {
	index = Random.nextInt( l.size() );
	return l.get(index);
}

post => ( e ,extra ) {
	result = HttpClient.post( e.url, e.params, extra);
	return result;
}

workResult => ( type, result, printFlag ) {
	if (type == 1 ){
		// do something
		if( printFlag ) {
			print(result);
		}
	}
}

getList => () {
	l = new List();
	// 省略添加元素
	return l;
}

getList().random().post( "no-extra!" ).workResult(1, $?, false);   
```

基本规则有：

- 当一个拓展方法和本对象的方法重名的时候， 会调用本对象的方法，而忽略扩展方法
- 声明一个拓展方法 并不需要什么特别的标识
- 任何非类内部的方法 都会视为拓展方法
- 寻找拓展方法会按照顺序查找， 当存在多个同名的方法的时候， 会使用最先找到的方法。

参数的传递规则：

- 如果拓展方法只有一个参数， 则自动传入当前对象。
- 如果拓展方法有两个及以上的参数个数， 则对比传入参数的个数。
  -  当个数相同的时候， 则会忽略当前对象，直接传入具体的参数值。
  - 当个数不同的时候， 则会将方法的第一个参数 传入为当前对象，其他参数依次向后追加。



## 特殊符号定义

### $?  上一个函数的执行结果

```
fa => (){
	return 1;
}

fb => (){
	return 2;
}

fc => ( a ) {
	println("a: " + a );
	return 3;
}

fd => (num){
	println("num: " + num);
	println("$? in fd: " + $?);
}


fa();
println("last of fa:" + $? );    // 1
println("again of fa:" + $? );   // null, 因为 println 函数没有返回值

fa();
fb();
println("last of fb:" + $?);     // 2

fd( fa() );                     // fd 内部的值会是 1, 函数 fa() 的返回值

```



### \$#, $1,$2...,  $*,$@      可变参数

这里采用 bash的方法来使用。

- $#   可变参数的个数
- $1   第一个参数
- $2   第二个参数
- $n   第n个参数
- $*, $@  都表示 实参的数组   



## 闭包

虽然我也不知道闭包是啥。。 但是应该就是类似的这个东西把。。

目前函数内部能返回`lambda`表达式， 但是带有参数变化的闭包 没有办法实现。

```

// 创建一个 闭包
funcCreate => (){

  myVar = 2;
  return a => {
    println("myVar: " + myVar);

    tmp = a * myVar;
    println(" in close pkg, a.. : " + tmp
    );
  } ;

}


funcA = funcCreate();
// 如果这里没有给myVar赋值 则会报错
myVar = 5;
funcA( 5 );

```



## 变量默认为 local 模式

目前变量可以穿透， 如果不需要这个特性，则需要编写大量的 `local` 声明， 这违背了我想快速开发的原则。。

所以目前考虑将所有的变量 默认声明为 local 模式。 

并添加 `ref` 关键字的特性，使之能引用外部的变量。 或者使用 `*` 操作符来引用。 

```
outNumber = 10;
outString = "hello";

func => (){
	// 引用 外部的变量
	ref outNumber,outString;
	
	println(outNumber);     // 10
	println(outString);     // hello
	
	outNumber = 5;
	outString = "world";
}

func();

println(outNumber);     // 5
println(outString);     // world

```



## 变量声明和赋值一起来

其实，目前的话， 直接对一个变量进行赋值的时候会自动声明。 这里想做的其实是在这个行为的基础上添加修饰符 。

下面这种代码

```
local a = 1;
const MAX = 10;  
```



## 利用 tree-sitter 的配置文件来重构 a.y 文件





## 启动参数

- `-v`， `--version`  查看版本信息
- `-h`，`--help` 查看帮助
- 

