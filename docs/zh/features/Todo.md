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


// __extend [class] __with [method list] 
// 添加拓展方法给某个具体得类
__extend List __with filter printList;
getList().random().post( "no-extra!" ).workResult(1, $?, false);   
```

基本规则有：

- 当一个拓展方法和本对象的方法重名的时候， 会调用本对象的方法，而忽略扩展方法
- 声明一个拓展方法 并不需要什么特别的标识
- ~~任何非类内部的方法 都会视为拓展方法~~  笔者觉得这样似乎会产生巨大得性能消耗。。
- ~~寻找拓展方法会按照顺序查找， 当存在多个同名的方法的时候， 会使用最先找到的方法。~~ 当拓展方法重复得时候，会进行报错

参数的传递规则：

- 如果拓展方法只有一个参数， 则自动传入当前对象。
- 如果拓展方法有两个及以上的参数个数， 则对比传入参数的个数。
  -  当个数相同的时候， 则会忽略当前对象，直接传入具体的参数值。
  - 当个数不同的时候， 则会将方法的第一个参数 传入为当前对象，其他参数依次向后追加。



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



## 变量空间的封闭

目前变量可以穿透生命周期的限制， 如果不需要这个特性，则需要编写大量的 `local` 声明， 这违背了我想快速开发的原则。。

目前有两个标记 可以控制 变量，函数，类的访问。 

1. `restrict`  是否对当前环境限定， 在限定之后，则不会去父级环境查找
2. `close` 当前环境是否关闭， 如果关闭，则不允许别的环境引用当前环境的变量

在合适的时机需要对这部分代码进行重构， 附加函数返回值部分的代码。

**下面内容仍然需要考虑一下**

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



## local 声明的变量在环境解除的时候也删掉内存使用

