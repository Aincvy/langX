# 数据类型



## 基本变量声明规则

- langX 是**弱类型的**脚本语言。
- 不需要指定类型， 直接赋值即可。
- 任何出现变量的位置都不需要声明类型。
- 如果一个变量直接赋值， 则会自动为其声明。

**其他需要注意的点。**

- 默认情况下， langX 使用的变量会穿越当前的 调用环境。（下面会详细举例）
- 可以使用关键字限制这个情况。



## 数值

langX 有两种数字类型， 整数和双精度浮点数。

整数： `1,2,3,500` 等

双精度浮点数：  `1.0,0.999,100.661115` 等

代码示例：

```
a = 1;
b = 2;

c = 0.55;
d = 15.66105;
```





## 字符串

使用双引号包围的内容叫字符串。

代码示例：

```
a = "hello";
b = "tom";

// 使用加号可以连接两个字符串
c = "this is a " + " string!";
```



## 函数 （lambda 表达式）

在langX 里， 使用符号`=>` 作为函数声明和 lambda 表达式声明的符号。

代码示例：

```
// 声明函数
func => (){
	println("this is in function.");
}

// 调用函数
func();

// 函数赋值给变量
varFunc = func;  

// 这里也是调用 func 
varFunc();


// 声明 lambda 表达式
noNameFunc = ( a, b ) => {
	println("arg a: " + a);
	println("arg b: " + b);
}

// 调用
noNameFunc(1,2); 
```

函数`func`赋值给变量`varFunc`之后，varFunc就保存了函数func的引用， 之后就可以通过变量varFunc对函数func进行调用。

而 变量`noNameFunc`保存的是对`lambda表达式`的引用。

### 引用穿透调用环境

在函数调用的默认情况下， 变量是会穿透的。

看下面的代码。

```
outerVar = "in the out";

func => (){
	println("func: " + outerVar);
}

func();    // 此时会输出 in the out


funcTemp => (){
  println("enter funcTemp");

	outerVar = "xx " ;
  func();

  println("leave funcTemp");
}

funcTemp();
println("out: " + outerVar);


// 下面是结果输出
// func: in the out
// enter funcTemp
// func: xx
// leave funcTemp
// out: xx
```

如果你不想他们穿透， 可以考虑使用 `local` 关键字声明变量， 或者使用`restrict` 关键字

下面简单介绍一下 `restrict` 关键字的使用。

```
funa => {
  print("in funa\n");
  a=b=c=1;
  funb();
}

funb => {
  // 当限定之后， 在funb 就看不到 funa 里面的变量了
  restrict ;
  print("in funb\n");
  d1 = a ;
  print("d1: " + d1 + "\n");
}

print("will start funa\n");
funa();

// 下面是输出
// will start funa
// in funa
// in funb
// d1: null
```

## 类

*函数不需要一定声明在类的内部。*

类是面向对象的基础把， langX的语法比较简单。

```
// 代码来自 scripts/class1.lx  脚本
// 声明一个 类
Student {
	// 声明变量
  name;
  age = 10 ;

	// 同名的方法 为构造方法 
  Student => (name,age){
    this.name = name;
		this.age = age;
		printInfo("in ctor.");
  }

  a => { print("hello,a!\n");}

  printInfo => (a3){ print("name: " + name + "\n");  print("age: " + age + "\n" ); print("a3: " + a3 + "\n");}

}

// 使用 new 关键字获取一个对象 
s2 = new Student("hideDragon",20);
b = s2.age;
c = s2.name;
print("b: " + b + "\n");
print("c: " + c + "\n");

s1 = s2;
s1.age = 10 ;
s1.name = "Mr.Ming";
s2.printInfo("wocao! keyile ? ");

Class2{

}

c1 = new Class2();

// 下面为输出的内容
// name: hideDragon
// age: 20
// a3: in ctor.
// b: 20
// c: hideDragon
// name: Mr.Ming
// age: 10
// a3: wocao! keyile ?
```

这里可能需要的注意的下面几点

- langX 中 没有 `private/public` 等类似的关键字， 可以简单的理解为 所有的类，类里的属性都是 `public的`
- 类的函数 也可以赋值给一个变量， 然后引用调用。 
- 可以使用 `extends` 关键字继承另外一个类 （更多信息可见`scripts/extends1.lx`)
- 可以使用`is` 关键字 来判断类型 （更多信息可见 `scripts/typejudge1.lx` )
- 可以对操作符(*加减乘除等*)进行重写。
- 可以使用 `auto` 关键字来扩充原类的内容  （更多信息可见 `scripts/classauto1.lx`）

