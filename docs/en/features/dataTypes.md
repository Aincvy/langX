# DataTypes

**Write in front: I am not a native English speaker, and my English is poor. Sorry for that, and if you want help me , just submit PR. Thank you!**



## Variable declaration

- langX is a weak-type script language.
- Do not need a specific type.
- 如果一个变量直接赋值， 则会自动为其声明。

**Attention**

- 默认情况下， langX 使用的变量会穿越当前的 调用环境。（下面会详细举例）
- 可以使用关键字限制这个情况。



## Numeric

langX has two numeric types: Integer and Double.

Integer:  `1,2,3,500,...` 

Double:  `1.0,0.999,100.661115,...` 

Code Example: 

```
a = 1;
b = 2;

c = 0.55;
d = 15.66105;
```





## String

What is enclosed in double quotation marks is called a string.

Code Example: 

```
a = "hello";
b = "tom";

// plus two or more strings
c = "this is a " + " string!";
```



## Function （lambda expr）

In langX ,  we use symbol `=>` as the function keyword and lambda keyword.

Code Example: 

```
// Function declaration
func => (){
	println("this is in function.");
}

// call function
func();

// 函数赋值给变量
varFunc = func;  

// this is also call function: func
varFunc();


// lambda expr declaration
noNameFunc = ( a, b ) => {
	println("arg a: " + a);
	println("arg b: " + b);
}

// call lambda 
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

## Class

Format: `ClassName {  classBody }`

Code Example: 

```
// code from scripts/class1.lx script
// Class declaration
Student {
	// member variable declaration
  name;
  age = 10 ;

	// Same name with class, this is a constructor.
	// The destructor function starts with a '~' symbol.
  Student => (name,age){
    this.name = name;
		this.age = age;
		printInfo("in ctor.");
  }

  a => { print("hello,a!\n");}

  printInfo => (a3){ print("name: " + name + "\n");  print("age: " + age + "\n" ); print("a3: " + a3 + "\n");}

}

// Use keywork 'new' to get a class instance.
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

// Print info below.
// name: hideDragon
// age: 20
// a3: in ctor.
// b: 20
// c: hideDragon
// name: Mr.Ming
// age: 10
// a3: wocao! keyile ?
```

**Attention**

- langX do not have `private` keyword, all class and all member in class is public.
- Keyword `extends` can let you extends other class. （More info:`scripts/extends1.lx`)
- Type check keyword: `is`  ( More info:  `scripts/typejudge1.lx` )
- Operators function override is supported. 
-  Keyword `auto` can extend the original class content. （More info: `scripts/classauto1.lx`）

