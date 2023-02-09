# C++

# 一、C++面向对象三大特性

## 1.1 封裝

把客观事物封装成抽象的类,并且类可以把自己的数据和方法只让可信的类或者对象操作,对不可信的信息进行隐藏

​    类将成员变量和成员函数封装在类的内部,根据需要设置访问权限,通过成员函数管理内部状态

## 1.2 继承

类直接的父子关系,子类可以继承基类对象的特征和能力

## 1.3 多态

"一个接口, 多种方法"。

## 1.4 C++ const修饰的全局变量具有内部链接属性

extern const int c = 300; //加上extern就变为外部链接属性

## 1.5 C++编译器不能优化的情况

1、不能优化自定义数据类型

2、如果用变量给const修饰的局部变量赋值,那么编译器就不能优化

3、编译器是在编译阶段来优化数据

## 1.6 尽量使用const代替define

1、define没有数据类型,const修饰的变量有数据类型,可以进行类型检查

2、const修饰的变量有作用域,define不重视作用域,不能限定常量的使用范围

# 二、C++ 命名空间

## 2.1 命名空间相关语法及注意事项

解决多人合作时取标识符重命名的问题。

```c++
namespace A{
   int a;
   void func()
   {
   
   }
}
```

命名空间注意事项

```C++
注意1:命名空间只能写在全局
注意2:命名空间可以嵌套命名空间
namespace Maker
{
	int a;
	namespace B
	{
		int b;
	}
}
注意3:命名空间是开放的,随时可以加入新成员,但是新成员只能在加入后使用
namespace Maker
{
	int a;
	namespace B
	{
		int b;
	}
}
namespace Maker
{
		int c;
}
注意4: 匿名命名空间
//类似于static int d = 50;
//只希望在本文件中使用,不希望别的文件访问
namespace
{
    int d = 50;
}
注意5:命名空间可以取别名
void test01()
{
    namespace nameMaker = Maker;
    cout << nameMaker::a << endl;
}
注意6:分文件编写代码时,如果.h有两个命名空间,但是里面的成员函数或者成员变量同名时,在.cpp中实现函数时,需要加上命名空间。
```

## 2.2 作用域运算符

用来访问某个作用域里的成员

```c++
namespace Maker
{
	int c=30;
}
int mya = 10;
int main()
{
    int mya = 20;
    cout << " mya = " << mya << endl;    mya = 20 //就近原則
    cout << " ::mya = "<< ::mya << endl;   mya = 10
	cout << Maker::c << endl;
  	//访问嵌套命名空间
    cout<< Maker::B::b << endl;
    return 0;
}
```

## 2.3 using声明和编译指令

### 2.31 using声明

using声明是让命名空间中某个标识符可以直接使用

```c++
namespace A
{
    int a = 10;
    int b = 20;
    int c = 30;
}
void test02()
{
    using A::a;       
    cout << a <<endl;
}
```

### 2.32 using编译指令

using编译指令,让某个命名空间中的标识符都可以直接被使用

```C++
void test03()
{
    using namespace A;
    cout << a <<endl;
    cout << b <<endl;
    cout << c <<endl;
}
```

# 三、C++引用

## 3.1 引用的概述及注意事项

引用的作用:给空间取别名。

- 引用创建时,必须初始化
- 引用初始化后不能改变它的方向
- 引用必须引用一块合法的内存空间

引用的基本语法:

```C++
void func(int &a)
{
    a = 200;
}
int main()
{
    int a = 2000;
    func(a);
    cout << a << endl; //a=200
}
```

## 3.2 数组引用

```c++
int arr[]={1,2,3,4,5};
第一种方法
定义数组类型
typedef int(MY_ARR)[5];
建立引用
MY_ARR &arref = arr;
------------------------------------
第二种方法
直接定义引用
int(&arref2)[5] = arr;
------------------------------------
第三种方法
typedef int(&MY_ARR3)[5];
建立引用数组类型
MY_ARR3 arref3 = arr;
------------------------------------
```

## 3.3 引用的本质

编译器在内部使用常量指针实现

int & a = b;  // int * const a = &b;

## 3.4 指针的引用

给指针变量空间取别名

```c++
{
    char * p = "牛子";
    char* &pp = p;
    cout << pp << endl; //pp = 牛子
}
```

## 3.5 引用使用的场景

1、引用作为函数参数传递

```c++
int func(int &a , int &b)
{
    int sum = a+b;
    return sum ;
}
int main()
{
    int a = 10;
    int b = 20;
    int sum = func(a,b);
    cout << sum << endl;
    return 0;
}
```

2、引用作为函数返回值

**不要返回局部变量的引用**

## 3.6 常量引用

```c++
const int &ret = 10; 修饰赋予引用的字面量
编译器优化: int tmp = 10; const int &ret = tmp;
```

# 四、函数重载

## 4.1 介绍

1.函数重载是：允许函数名相同，这种现象叫函数重载

2.函数重载的作用：是为了方便使用函数名

3.函数重载的条件：同一个作用域，参数的个数不同，参数的顺序不同，参数的类型不同

```c++
//参数的个数不同
void func()
{
	cout << "func()" << endl;
}
void func(int a)
{
	cout << "func(int a)" << endl;
}
//参数的类型不同
void func(char c)
{
	cout << "func(char c)" << endl;
}
//参数的顺序不同
void func(int a, double b)
{
	cout << "func(int a, double b)" << endl;
}
void func(double b, int a)
{
	cout << "func(double b, int a)" << endl;
}
```

4.调用重载函数的注意：

严格的类型匹配，如果类型不匹配，那么尝试转换，转换成功就掉用，失败就报错

```c++
void test01()
{
	int a = 10;
	double b = 3.14;

	func();
	//func(b);// err double转换不了成为int或char
	func(a, b);
	func(b, a);
	char c = 'c';
	func(c);//char转换int成功，调用int参数的函数
}
```

5.函数重载和函数的默认参数一起使用，需要注意二义性问题

```c++
//函数重载和函的默认参数一起使用
void myfunc(int a, int b = 0)
{
	cout << "myfunc(int a, int b = 0)" << endl;
}

void myfunc(int a)
{
	cout << "myfunc(int a)" << endl;
}

void test02()
{
	//myfunc(10); err,二义性问题，不知道调用哪个函数
}
```

6.函数的返回值不作为函数重载的条件

编译器是通过你调用函数时，传入的参数来判断调用重载的哪个函数，我们调研函数时不需要写返回值，所以返回值不能成为函数重载的条件

## 4.2 函数重载的原理

1.函数重载的原理是在汇编时，给各个函数取别名，C语言不能重载的原因是没有取别名

2.生成汇编文件:gcc -S test.c -o test.s         g++ -S test.cpp -o test2.s

3.查看内容:type 文件名

## 4.3 C++调用C语言的函数

1.C++的函数在汇编时，会给函数取别名，C语言的不会，这时，如果C++来调用C语言的函数，C++会去找取了别名的函数，但是C语言没有取别名，这时会出错

~~~c++
test.h文件中
//这是告诉C++编译器，找下面的函数，要以C语言的方式去寻找
#ifdef __cplusplus
extern "C"
{
#endif
	void func();//C语言的函数声明


#ifdef __cplusplus
}
#endif
```
~~~

# 五、类的封装

1.封装是把属性（变量）和方法（函数）封装到类内，然后给这些数据赋予权限

2.为什么要有封装

	1.防止乱调用函数和变量，出现错误
	
	2.维护代码更方便

3.权限

```c++
//封装：1,把属性和方法放到类中,2.给这些数据赋予权限
class Maker
{
public://公有权限
	void set(string Name,int Id)
	{
		id = Id;
		name = Name;
	}
	void printMaker()
	{
		cout << "id=" << id << " name=" << name << endl;
	}
private://私有
	int id;
	string name;

protected://保护
	int a;
};
//继承
class Son :public Maker
{
	void func()
	{
		a = 20;//子类的类内可以方法父类的保护权限的成员
	}
};
//类外不能访问私有权限的成员
//类外可以访问公有权限的成员
//类外不能访问保护权限的成员
//子类的类内可以方法父类的保护权限的成员
//类内是没有权限之分

void test()
{
	Maker m;
	m.set("小花",1);
	m.printMaker();
}
```

4.尽量把属性设置为私有权限

1.可以控制属性的读写权限

2.可赋予客户端访问数据的一致性

3.可以保护属性的合法性

结构体的默认权限是公有的，类的默认权限是私有的

# 六、构造函数和析构函数

**explicit只能放在构造函数前面，构造函数只有一个参数或其他参数有默认值时**

**防止编译器优化Maker m=10**

1.当对象产生时，必须初始化成员变量，当对象销毁前，必须清理对象

2.初始化用构造函数，清理用析构函数，这两个函数是编译器调用

## 6.1 作用

```c++
构造函数的作用
class Maker
{
public:
	//构造函数的作用是初始化成员变量，是编译器去调用的
	Maker()
	{
		a = 10;
		cout << "构造函数" << endl;
	}

	//析构函数，在对象销毁前，编译器调用析构函数
	~Maker()
	{
		cout << "析构函数" << endl;
	}
public:
	int a;
};

void test01()
{
	//实例化对象，内部做了两件事，1.分配空间，2.调用构造函数进行初始化
	Maker m;
	int b = m.a;
	cout << b << endl;

}

//析构函数的作用
class Maker2
{
public:
	//有参构造
	Maker2(const char *name,int age)
	{
		cout << "有参构造" << endl;
		//从堆区空间申请
		pName = (char*)malloc(strlen(name) + 1);
		strcpy(pName, name);
		mAge = age;
	}

	void printMaker2()
	{
		cout << "name:" << pName << " age:" << mAge << endl;
	}
	~Maker2()
	{
		cout << "析构函数" << endl;
		//释放堆区空间
		if (pName != NULL)
		{
			free(pName);
			pName = NULL;
		}
	}
private:
	char *pName;
	int mAge;
};

void test02()
{
	Maker2 m2("翠花",18);
	m2.printMaker2();

}
```

## 6.2 注意

1.构造函数和析构函数的权限必须是公有的

2.构造函数可以重载

3.构造函数没有返回值，不能用void,构造函数可以有参数，析构函数没有返回值，不能用void,没有参数

4.有对象产生必然会调用构造函数，有对象销毁必然会调用析构函数。有多少个对象产生就会调用多少次构造函数，有多少个对象销毁就会调用多少次析构函数

## 6.3 拷贝构造函数

**什么是拷贝构造**

```c++
class Maker
{
public:
	Maker()
	{
		cout << "无参构造函数" << endl;
		a = 20;
	}
	//拷贝构造函数
	Maker(const Maker &m)
	{
		cout << "拷贝构造函数" << endl;
		a = m.a;
		
	}
	//打印函数
	void printMaker()
	{
		cout << "a=" << a << endl;
	}
private:
	int a;
};



void test01()
{
	Maker m1;
	m1.printMaker();

	//用一个已有的对象去初始化另一个对象
	Maker m2(m1);
	m2.printMaker();
}
```

**编译器提供了默认的拷贝构造函数**

```c++
class Maker2
{
public:
	Maker2()
	{
		cout << "无参构造函数" << endl;
		a = 20;
	}
	//编译器提供了默认的拷贝构造函数
	//Maker2(const Maker2 &m)
	//{
	//	//默认拷贝构造函数进行了成员变量的简单拷贝
	//	a = m.a;
	//}

	//打印函数
	void printMaker()
	{
		cout << "a=" << a << endl;
	}
private:
	int a;
};


void test02()
{
	Maker2 m1;
	m1.printMaker();

	Maker2 m2(m1);
	m2.printMaker();
}
```

**拷贝构造函数中形参要用引用**

```c++
class Maker3
{
public:
	Maker3(int Ma)
	{
		cout << "有参构造函数" << endl;
		ma = Ma;
	}
	Maker3(const Maker3 &m)
	{
		cout << "拷贝构造函数" << endl;
	}
private:
	int ma;
};

void test03()
{
	Maker3 m1(10);//调用有参构造

	Maker3 m2(m1);

	//如果拷贝构造函数中的形参不是引用
	/*
	Maker3(const Maker3 m)//const Maker3 m=m1;   const Maker3 m(m1);
	{
		cout << "拷贝构造函数" << endl;
	}

	1.Maker3 m2(m1);
	2.const Maker3 m=m1;
	3.const Maker3 m(m1);
	4.const Maker3 m=m1;
	5.进入死循环
	*/
}
```

## 6.4 构造函数的分类及调用

```c++
1.构造函数的分类：无参构造函数，有参构造函数，拷贝构造函数

2.类默认提供了哪些函数：默认的构造函数，默认的析构函数，默认的拷贝构造函数，默认的赋值函数

3.构造函数的调用
   
void test01()
{
	Maker m;//调用无参构造函数
	Maker m1(10);//调用有参构造
	Maker m2(m1);//调用拷贝构造

	//不常用
	Maker m4 = Maker(10);//调用的是有参构造函数
	Maker m3 = m2;//调用拷贝构造
	cout << "=====" << endl;
	Maker m5 = 10;//Maker m5=Maker(10);
	cout << "=======" << endl;

	Maker m6;
	m6 = m5;//赋值操作

}    
```

## 6.5 匿名对象

匿名对象的生命周期在当前行

## 6.6 调用规则

1.如果程序员提供了有参构造，那么编译器不会提供默认构造函数，但是会提供默认的拷贝构造

2.如果程序员提供了拷贝构造函数，那么编译器不会提供默认的构造函数和默认的拷贝构造函数

## 6.7 多个对象的构造和析构

1.如果类有成员对象，那么先调用成员对象的构造函数，再调用本身的构造函数，析构函数的调用顺序反之
2.成员对象的构造函数调用和定义顺序一样
3.注意，如果有成员对象，那么实例化对象时，必须保证成员对象的构造和析构能被调用

**初始化列表**

1.初始化列表是干什么用的，指定调用成员对象的某个构造函数

2.初始化列表只能写在构造函数

3.如果使用了初始化列表，那么所有的构造函数都要写初始化列表

4.如果有多个对象需要指定调用某个构造函数，用逗号隔开

5.可以使用对象的构造函数传递数值给成员对象的变量

```c++
class BMW2
{
public:

	BMW2(int a)
	{
		cout << "BMW2有参构造" << a << endl;
	}

	~BMW2()
	{
		cout << "BMW2析构" << endl;
	}
};

class Buick2
{
public:
	Buick2(int b,int c)
	{
		cout << "Buick2构造" << endl;
	}

	~Buick2()
	{
		cout << "Buick2析构" << endl;
	}
};

class Maker2
{
public:
	//初始化列表
	//注意1：初始化列表只能写在构造函数
	/*Maker2() :bmw(10)
	{
		cout << "Maker2构造" << endl;
	}*/
	//如果有多个对象需要指定调用某个构造函数，用逗号隔开
	Maker2(int a,int b,int c) :bmw(a), bui(b,c)
	{
		cout << "Maker2构造" << endl;
	}
	//注意2:如果使用了初始化列表，那么所有的构造函数都要写初始化列表
	Maker2(const Maker &m2) :bmw(40), bui(10,20)
	{

	}
	/*void printMaker2() : bmw(10)
	{

	}*/

	~Maker2()
	{
		cout << "Maker2析构" << endl;
	}
private:

	Buick2 bui;//成员对象
	BMW2 bmw;//成员对象
};

//初始化列表是调用成员对象的指定构造函数
void test02()
{
	Maker2 m(30,10,20);
}
```

## 6.8 深拷贝问题

1.默认的拷贝构造函数进行了简单的赋值操作（浅拷贝）

2.浅拷贝的问题

同一块空间被释放两次

```C++
class Student
{
public:
	Student(const char *name, int Age)
	{
		pName = (char*)malloc(strlen(name) + 1);
		strcpy(pName, name);
		age = Age;
	}

	~Student()
	{
		cout << "析构函数" <<endl;
		if (pName != NULL)
		{
			free(pName);
			pName = NULL;
		}
	}
public:
	char *pName;
	int age;
};

void test02()
{
	Student s1("小花", 18);
	Student s2(s1);

	cout << "s1 Name=" << s1.pName << " s1 age=" << s1.age << endl;
	cout << "s2 Name=" << s2.pName << " s2 age=" << s2.age << endl;
}
```

3.深拷贝解决浅拷贝问题

自己写拷贝构造函数

```C++
	//深拷贝
	Student(const Student &stu)
	{
		cout << "自己的拷贝构造函数" << endl;
		//1.申请空间
		pName = (char*)malloc(strlen(stu.pName) + 1);
		//2.拷贝数据
		strcpy(pName, stu.pName);
		age = stu.age;
	}
```

## 6.9 静态成员

1.静态成员变量的生命周期是整个程序，作用域在类内

2.静态成员变量要在类内声明，类外初始化

3.静态成员变量属于类，不属于对象，是所有对象共享

4.静态成员变量可以用类访问，也可以用对象访问

```
class Maker
{
public:
	Maker()
	{
		
	}
public:
	//1.静态成员变量的生命周期是整个程序，作用域在类内
	static int a;
};
//2.静态成员变量要在类内声明，类外初始化
int Maker::a = 100;
void test01()
{
	//3.静态成员变量属于类，不属于对象，是所有对象共享
	cout << Maker::a << endl;
	Maker m;
	cout << m.a << endl;
	//4.静态成员变量可以用类访问，也可以用对象访问
}
```

5.静态成员函数只能访问静态成员变量

```
class Maker2
{
public:
	Maker2()
	{

	}
	//静态成员函数只能访问静态成员变量
	static void setA(int a)
	{
		a2 = a;
		cout << "a2=" << a2 << endl;
		//a1 = a;不能访问普通成员变量
	}
public:
	int a1;
	static int a2;
};
int Maker2::a2 = 200;
void test02()
{
	Maker2::setA(300);
}
```

6.静态成员也有权限，如果为私有，类外也不可以访问

```
class Maker3
{
private:
	static void func()
	{
		cout << "a3=" << a3 << endl;
	}
private:
	static int a3;
};
int Maker3::a3 = 300;
void test03()
{
	//Maker3::func();err
}
```

7.const修饰的静态成员变量，最好在类内初始化

```
//const修饰的静态成员变量最好在类内初始化
class Maker4
{
public:
	const static int a = 20;
	const static int b;
};
//类外也可以初始化
const int Maker4::b = 30;
```

8.普通成员函数可以访问静态成员变量

```
class Maker5
{
public:
	void func()
	{
		cout << "a=" << a << endl;
	}
public:
	static int a;
};

//类外也可以初始化
int Maker5::a = 30;

void test04()
{
	Maker5 m;
	m.func();
	
}
```

## **C++对象模型**

1.空类的大小是1.

2.类的成员函数不占用类的大小，静态成员变量不占用类的大小，静态成员函数不占用类的大小

3.普通成员变量占用类的大小

4.类的成员中，成员函数和成员变量是分开存储

## this指针

1.每个对象都有一个隐藏的this指针，但不属于对象，是编译器添加的

2.编译器会把this指针传入成员函数内

3.this指针指向对象的存储空间

4.this的作用:

```
class Maker2
{
public:
	//1.当形参名和成员变量名相同时，用this指针区分
	Maker2(int id)
	{
		this->id = id;
	}
	//2.返回对象的本身
	Maker2 &getMaker2()
	{
		return *this;//运算符重载时有用
	}
public:
	int id;
};
```

5.拓展

1.this指针指向的空间有没有存储静态成员变量？

没有

2.this指针的指向可以改变吗？

this指针的指向不能改变，也就是说this是Maker *const this;

6.防止空指针调用成员函数

```
class Maker
{
public:
	Maker()
	{
		a = 20;
	}

	void printMaker()
	{
		if (this == NULL)
		{
			cout << "this==NULL" << endl;
			return;
		}
		
		cout << this->a << endl;
	}
private:
	int a;
};

void test()
{
	Maker *m = NULL;
	m->printMaker();
}
```

## 常对象和常函数

1.常函数

1.在函数的()后面加上const，这个函数就是常函数

2.常函数内不能修改普通成员变量

3.const修饰的是this指针指向的空间中的变量不能改变

4.mutable修饰的成员变量在常函数中可以修改

```
class Maker
{
public:
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
		score = 100;
	}
	//常函数,1.函数的()后面添加const,该函数是常函数
	void printMaker()const
	{
		//id = 100;err//2.常函数内不能修改普通成员变量
		//3.const修饰的是this指针指向的空间中的变量不能改变
		//Maker *const this;
		//const Maker*const this;这是常函数修饰的
		score = 200;//4.mutable修饰的成员变量在常函数中可以修改
		cout << "score=" << score << endl;
	}
public:
	int id;
	int age;
	mutable int score;//mutable修饰的成员变量

};
void test01()
{
	Maker m(1, 18);
	m.printMaker();
}
```

2.常对象

1.在数据类型前面加上const，让对象成为常对象

2.常对象可以调用常函数

3.常对象可以修改mutable修饰的成员变量

```
class Maker
{
public:
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
		score = 100;
	}
	//常函数,1.函数的()后面添加const,该函数是常函数
	void printMaker()const
	{
		//id = 100;err//2.常函数内不能修改普通成员变量
		//3.const修饰的是this指针指向的空间中的变量不能改变
		//Maker *const this;
		//const Maker*const this;这是常函数修饰的
		score = 200;//4.mutable修饰的成员变量在常函数中可以修改
		cout << "score=" << score << endl;
	}
	void func()
	{
		cout << "func" << endl;
	}
public:
	int id;
	int age;
	mutable int score;//mutable修饰的成员变量

};

void test()
{
	//1.在数据类型前面加上const，让对象成为常对象
	const Maker m(1, 18);//常对象

	//m.id = 100;//常对象不能改变普通成员变量的值
	//m.func();//常对象不能调用普通成员函数
	m.printMaker();//2.常对象可以调用常函数
	m.score = 500;//常对象可以修改mutable修饰的成员变量

	Maker m2(2, 20);
	m2.printMaker();//普通对象也可以调用常函数

}
```

## 友元

1.友元的概念

友元是赋予全局函数，类的成员函数，类，访问别的类的私有成员权限

注意：友元函数不是类的成员函数

1.全局友元函数

```
class Building
{
	//声明这个全局函数为Building类的友元函数
	friend void GoodGay(Building &bd);
public:
	Building()
	{
		keting = "客厅";
		woshi = "卧室";
	}

public:
	string keting;
private:
	string woshi;
};

void GoodGay(Building &bd)
{
	cout << "好基友访问:" << bd.keting << endl;
	cout << "好基友访问:" << bd.woshi << endl;
}

void test01()
{
	Building my;

	GoodGay(my);
}
```

2.友元类

```
class Building
{
	//声明GoodF类为Building类的友元类
	friend class GoodF;
	friend class GoodF2;
public:
	Building()
	{
		keting = "客厅";
		woshi = "卧室";
	}

public:
	string keting;
private:
	string woshi;
};

class GoodF
{
public:
	void func(Building &bd)
	{
		cout << "访问:" << bd.keting << endl;
		cout << "访问:" << bd.woshi << endl;//通过参数访问私有成员
	}
};
//1.通过传入参数来访问类的私有成员
void test01()
{
	Building bd;
	GoodF f;
	f.func(bd);
}

//2.通过类内指针来访问类的私有成员
class GoodF2
{
public:
	GoodF2()
	{
		cout << "无参构造" << endl;
		pbu = new Building;
	}
	void func()
	{
		cout << "访问:" << pbu->keting << endl;
		cout << "访问:" << pbu->woshi << endl;//通过成员指针访问私有成员
		
	}
	//拷贝构造
	GoodF2(const GoodF2 &f2)
	{
		cout << "拷贝构造" << endl;
		//1.申请空间
		pbu = new Building;

	}
	~GoodF2()
	{
		cout << "析构函数" << endl;
		if (pbu != NULL)
		{
			cout << "pbu" << endl;
			delete pbu;
		}
	}
public:
	Building *pbu;
};

void test02()
{
	GoodF2 f;
	f.func();

	GoodF2 f2 = f;

}
```

3.类的友元成员函数（难点）

```
//1.编译器知道类的声明，不知道类的结构
class Building;//声明类
class GoodGay
{
public:
	void func(Building &bud);
};
class Building
{
	//声明GoodGay类的成员函数func成为Building类的友元函数
	friend void GoodGay::func(Building &bud);
public:
	Building()
	{
		keting = "客厅";
		woshi = "卧室";
	}

public:
	string keting;
private:
	string woshi;
};


void GoodGay::func(Building &bud)
{
	cout << "访问:" << bud.keting << endl;
	cout << "访问:" << bud.woshi << endl;
}

void test()
{
	Building bud;
	GoodGay GF;
	GF.func(bud);
}
```

4.友元的注意：

1．友元关系不能被继承。

2．友元关系是单向的，类A是类B的朋友，但类B不一定是类A的朋友。

3.友元关系不具有传递性。类B是类A的朋友，类C是类B的朋友，但类C不一定是类A的朋友。

## 单例模式

1.单例模式是一个类只能实例化一个对象

2.实现单例模式的思路

​	1.把无参构造函数和拷贝构造函数私有化

​	2.定义一个类内的静态成员指针

​	3.在类外初始化时，new一个对象

​	4.把指针的权限设置为私有，然后提供一个静态成员函数让外面获取这个指针

```
//单例模式是一个类只能实例化一个对象
class Maker
{
	//1.把构造函数私有化
private:
	Maker()
	{
	}
	Maker(const Maker &m)
	{

	}
public:
	//静态成员函数，访问静态成员变量
	//4.把指针的权限设置为私有，然后提供一个静态成员函数让外面获取这个指针
	static Maker* getMaker()
	{
		return pMaker;
	}
private:
	//2.定义一个类内的静态成员指针
	static Maker *pMaker;
};
//3.在类外初始化时，new一个对象
Maker *Maker::pMaker = new Maker;//这里可以new是因为在Maker::作用域，编译器把它当成在类内

void test()
{
	//Maker m;
	Maker *m = Maker::getMaker();
	Maker *m2 = Maker::getMaker();
	cout << "m=" << m << endl;
	cout << "m2=" << m2 << endl;

	//Maker m3 = *m;//调用拷贝构造，这里会产生新对象，所以要把拷贝构造也私有化
	//cout << "m3=" << &m3 << endl;
}
```

3.单例模式案例（需求：获取打印机打印次数）

	//需求，获取打印机使用的次数
	class Printer
	{
	private:
		//1.把无参构造和拷贝构造私有化
		Printer()
		{
			mcount = 0;
		}
		Printer(const Printer &p)
		{
	
		}
	public:
		static Printer *getPrinter()
		{
			return p;
		}
	
		void printPrinter(string name)
		{
			cout << name << ":打印" << endl;
			mcount++;
		}
		int getCount()
		{
			return mcount;
		}
	private:
		int mcount;//记录打印打印的次数
		//2.定义静态成员指针
		static Printer *p;
	};
	//3.类外进行初始化，new对象
	Printer *Printer::p = new Printer;
	
	void test()
	{
		//销售部
		Printer *p1 = Printer::getPrinter();
		p1->printPrinter("销售部");
	
		//技术部
		Printer *p2 = Printer::getPrinter();
		p2->printPrinter("技术部");
	
		//公关部
		Printer *p3 = Printer::getPrinter();
		p3->printPrinter("公关部");
	
		Printer *p4 = Printer::getPrinter();
		cout << "打印使用的次数:"<<p4->getCount() << endl;
	
	}

# 七、运算符重载

## 7.1 运算符重载概念

1.运算符重载，就是对已有的运算符重新进行定义，[赋予](http://baike.baidu.com/view/483609.htm)其另一种功能，以适应不同的数据类型。

2.**运算符重载的目的是让语法更加简洁**

3.**运算符重载不能改变本来寓意，不能改变基础类型寓意**

4.运算符重载的本质是另一种函数调用（是编译器去调用）

5.这个函数同一的名字叫operator

6.重载函数可以写成全局或成员函数

7.重载函数如果写成全局的，那么双目运算符左边的是第一个参数，右边是第二个参数

8.重载函数如果写成成员函数，那么双目运算符的左边是this,右边是第一个参数

9.不能改变运算符优先级，不能改变运算符的参数个数。

## 7.2 加号运算符重载

1.同类型的对象相加

```c++
class Maker
{
public:
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}
	//写成成员函数，那么只需要一个参数，这个参数是加号的右边
	Maker operator+(Maker &m2)
	{
		Maker temp(this->id + m2.id, this->age + m2.age);

		return temp;
	}
public:
	int id;
	int age;
};

//全局方式 //3.编译器调用这个函数
//Maker operator+(Maker &p1,Maker &p2)//2.编译器检查参数是否对应，第一个参数是加的左边，第二参数是加号的右边
//{
//	Maker temp(p1.id + p2.id, p1.age + p2.age);
//
//	return temp;
//}

void test01()
{
	Maker m1(1, 20);
	Maker m2(2, 22);
	//+也叫双目运算符
	Maker m3=m1 + m2;//1.编译器看到两个对象相加，那么编译器会去找有没有叫operator+的函数

	cout << "id:" << m3.id << " age:" << m3.age << endl;

	//复数加
	Maker m4 = m1 + m2 + m3;
	cout << "id:" << m4.id << " age:" << m4.age << endl;
}
```

2.不同类型的对象相加

```c++
class Maker
{
public:
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}
	
public:
	int id;
	int age;
};
class Student
{
public:
	Student()
	{
		mid = 0;
	}
	Student(int id)
	{
		mid = id;
	}
public:
	int mid;
};
Student operator+(Maker &m, Student &s)
{
	Student tmp(m.id + s.mid);

	return tmp;
	
}
Student operator+(Student &s, Maker &m)
{
	Student tmp(m.id + s.mid);

	return tmp;

}
void test()
{
	Maker m1(1, 18);
	Student s1(2);
	Student s2 = m1 + s1;

	s1 + m1;
}
```

## 7.3 减号运算符重载

```c++
class Maker
{
public:
	Maker(int id)
	{
		this->id = id;
	}
	Maker operator-(Maker &m2)
	{
		Maker tmp(this->id - m2.id);
		return tmp;
	}
public:
	int id;
};

int operator-(Maker &m,int b)
{
	return m.id-b;
}

void test()
{
	Maker m1(10);
	Maker m2(5);
	Maker m3 = m1 - m2;
	cout << m3.id << endl;

	int a = m3 - 5;
	cout << a << endl;
}
```

## 7.4 左移运算符和右移运算符重载

**1.左移运算符重载**

​	1.cout是对象，<<是左移运算符

​	2.重载左移运算符是为了直接打印对象

​	3.形参和实参是一个对象

​	4.不能改变库类中的代码

​	5.ostream中把拷贝构造函数私有化了

​	4.如果要和endl一起使用，那么必须返回ostream的对象.

```c++
class Maker
{
	//如果要访问类的私有成员，那么把<<重载函数声明为友元
	friend ostream& operator<<(ostream &out, Maker &m);
public:
	Maker(int id,string name)
	{
		this->id = id;
		this->name = name;
	}

private:
	int id;
	string name;
};
//1.形参和实参是一个对象
//2.不能改变库类中的代码
//3.ostream中把拷贝构造函数私有化了
//4.如果要和endl一起使用，那么必须返回ostream的对象
ostream& operator<<(ostream &out, Maker &m)
{
	cout << m.id <<" "<<m.name<< endl;

	return out;
}

void test01()
{
	Maker m(10,"小花");
	cout << m << endl;
	cout << endl;
	/*
	endl是一个函数
	operator<<(endl）
	*/

	cout << 10;//内部重载了基础数据类型
}
```

**2.右移运算符重载**

```c++
class Maker
{
	friend istream & operator>>(istream &in, Maker &m);
public:
	Maker(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	int getAge()
	{
		return age;
	}
private:
	string name;
	int age;
};

istream &operator>>(istream &in, Maker &m)
{
	in >> m.age;
	in >> m.name;

	return in;
}

void test02()
{
	Maker m("悟空", 15);
	Maker m2("悟空2", 25);

	cin >> m>>m2;

	cout << m.getAge() << endl;
	cout << m2.getAge() << endl;

}
```

## 7.5 赋值运算符重载

1.编译器默认给类提供了一个默认的赋值运算符重载函数

2.默认的赋值运算符重载函数进行了简单的赋值操作

```c++
class Maker
{
public:
	Maker()
	{
		id = 0;
		age = 0;
	}
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}
public:
	int id;
	int age;
};

void test()
{
	Maker m1(10, 20);
	Maker m2;

	m2 = m1;//赋值操作
	//默认的赋值运算符重载函数进行了简单的赋值操作
	cout << m2.id << " " << m2.age << endl;
}
```

3.当类有成员指针时，然后在构造函数中申请堆区空间，在析构函数中释放堆区空间，会出现同一块空间释放2次，然后内存泄漏，所以要重写赋值运算符重载函数

```c++
class Student
{
public:
	Student(const char *name)
	{
		pName = new char[strlen(name) + 1];
		strcpy(pName, name);
	}
	//防止浅拷贝
	Student(const Student &stu)
	{
		pName = new char[strlen(stu.pName) + 1];
		strcpy(pName, stu.pName);
	}
	//重写赋值运算符重载函数
	Student &operator=(const Student &stu)
	{
		//1.不能确定this->pName指向的空间是否能装下stu中的数据，所以先释放this->pName指向的空间
		if (this->pName != NULL)
		{
			delete[] this->pName;
			this->pName = NULL;
		}

		//2.申请堆区空间，大小由stu决定
		this->pName = new char[strlen(stu.pName) + 1];
		//3.拷贝数据
		strcpy(this->pName, stu.pName);

		//4.返回对象本身
		return *this;
	}	

	~Student()
	{
		if (pName != NULL)
		{
			delete[] pName;
			pName = NULL;
		}
	}

	void printStudent()
	{
		cout << "Name:" << pName << endl;
	}
public:
	char *pName;
};

void test02()
{
	Student s1("悟空");
	Student s2("小林");

	s1.printStudent();
	s2.printStudent();

	s1 = s2;//赋值操作

	s1.printStudent();
	s2.printStudent();
	
	//复数运算不会出错
	//s1 = s2 = s3;
}
```

4.赋值运算符重载函数中，为什么要返回引用

```c++
void test03()
{
	Student s1("a");
	Student s2("b");
	Student s3("c");

	s1 = s2 = s3;//s3赋值s2,s2赋值给s1

	cout << &(s2 = s3) << endl;
	cout << &s2 << endl;
	//如果返回的是值，s2=s3这个表达式会产生一个新的对象
	//s1=s2=s3,赋值运算符本来的寓意，是s3赋值s2,s2赋值给s1
	//也就是说s2=s3这个表达式要返回s2这个对象，所以要返回引用

}
```

## 7.6 关系运算符重载

```c++
class Maker
{
public:
	Maker()
	{
		id = 0;
		age = 0;
	}
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}

	bool operator==(Maker &m)
	{
		if (this->id == m.id && this->age == m.age)
		{
			return true;
		}
		return false;
	}


	bool operator!=(Maker &m)
	{
		if (this->id != m.id || this->age != m.age)
		{
			return true;
		}
		return false;
	}
public:
	int id;
	int age;
};

void test()
{
	Maker p1(1, 20);
	Maker p2;

	if (p1 == p2)
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}

	if (p1 != p2)
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}
}
```

## 7.7 前置加加和后置加加运算符重载

```c++
class Maker
{
	friend ostream &operator<<(ostream &out, Maker &m);
public:
	Maker(int a)
	{
		this->a = a;
	}
	//重载前置加加
	Maker &operator++()
	{
		++this->a;
		return *this;
	}

	//后置加加,
	Maker operator++(int)//占位参数，必须是int
	{
		//后置加加，先返回，后加加
		Maker tmp(*this);//1.*this里面的值a是等于2
		++this->a;//这个对象的a等3
		return tmp;
	}
private:
	int a;
};

ostream &operator<<(ostream &out, Maker &m)
{
	out << m.a << endl;
	return out;
}

void test02()
{
	Maker m1(1);
	cout << m1 << endl;//1
	cout << ++m1 << endl;//2
	//++(++m1);
	cout << m1++ << endl;//2  这里返回的拷贝的tmp对象
	cout << m1 << endl;//3 这里返回的是++this->a的对象

	//同等条件下，优先使用前置加加，不需要产生新的对象和调用拷贝构造

}
```

## 7.8 数组下标运算符重载

```c++
MyArray.h
class MyArray
{
public:
//重写赋值运算符重载函数
	MyArray&operator=(const MyArray &m);

	//要能当左右值
	int &operator[](int index);

};

MyArray.cpp
//重写赋值运算符重载函数
MyArray&MyArray::operator=(const MyArray &m)
{
	cout << "赋值函数" << endl;
	//1.释放原来的空间
	if (this->pArray != NULL)
	{
		delete[] this->pArray;
		this->pArray = NULL;
	}
	this->mCapacity = m.mCapacity;
	this->mSize = m.mSize;
	//2.申请空间，大小由m决定
	this->pArray = new int[m.mCapacity];
	//3.拷贝数据
	cout << "this->mSize:"<<this->mSize << endl;
	for (int i = 0; i < this->mCapacity; i++)
	{
		this->pArray[i] = m.pArray[i];
	}

	return *this;
}

//要能当左右值
int &MyArray::operator[](int index)
{
	/*
	for (int i = 0; i < 20; i++)
	{
		arr[i] = i + 10;
	}

	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	*/
	//赋值时，加加
	
	
	if (this->mSize <=index)
	{
		this->mSize++;
	}
	
	return this->pArray[index];
}

数组下标重载.cpp
void test02()
{
	MyArray arr;
	for (int i = 0; i < 20; i++)
	{
		arr[i] = i + 10;
	}

	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	MyArray arr2;
	arr2 = arr;
	for (int i = 0; i < 20; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	cout << arr2.Size() << endl;
}
```

## 智能指针类

1.智能指针类是管理另一个类的对象的释放

```c++
class Maker
{
public:
	Maker()
	{
		cout << "无参构造" << endl;
	}
	void printMaker()
	{
		cout << "hello Maker" << endl;
	}
	~Maker()
	{
		cout << "析构函数" << endl;
	}
};

class SmartPoint
{
public:
	SmartPoint(Maker *m)
	{
		this->pMaker = m;
	}

	~SmartPoint()
	{
		if (this->pMaker != NULL)
		{
			cout << "SmartPoint 析构函数" << endl;
			delete this->pMaker;
			this->pMaker = NULL;
		}
	}
private:
	Maker *pMaker;
};
void test01()
{
	Maker *p = new Maker;

	SmartPoint sm(p);//栈区，会调用析构函数
	//当test01()函数结束时，会调用SmartPoint的析构函数，
	//在这析构函数中delete了Maker的对象，会调用Maker的析构函数

}
```

2.指针运算符重载

```c++
	//重载指针运算符
	Maker *operator->()
	{
		return this->pMaker;
	}
	
	
void test02()
{
	Maker *p = new Maker;

	SmartPoint sm(p);
	//sm-> ==> pMaker->
	sm->printMaker();

}
```

3.重载*

```c++
//重载星花
	Maker &operator*()
	{
		return *pMaker;
	}
	
void test02()
{
	Maker *p = new Maker;

	SmartPoint sm(p);

	(*sm).printMaker();

}
```

## 重载函数调用符号

1.类里有重载函数调用符号的类实例化的对象也叫仿函数

2.仿函数的作用：1.方便代码维护 2.方便有权限的调用函数。3.作为算法的策略（后将）

```c++
//一个类如重载了函数调用符号，那么这个类实例化出的对象也叫仿函数
//仿函数的作用：1.方便代码维护 2.方便有权限的调用函数。3.作为算法的策略（后将）
class Maker
{
public:
	Maker()
	{
		name = "翠花";
	}
	void printMaker()
	{
		cout << name + "你好漂亮" << endl;
	}

	void operator()()
	{
		cout << "hello" << endl;
	}

	void operator()(int v1,int v2)
	{
		cout << v1+v2 << endl;
	}
public:
	string name;
};


void test()
{
	Maker func;

	func();//看起来像函数，其实func是对象

	func(10, 20);

	func.printMaker();
}
```

## 其他重载的重载

```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Maker
{
public:
	Maker()
	{
		a = 0;
	}

	void SetA(int val)
	{
		a = val;
	}
	//没有返回值，也没有void
	operator bool()
	{
		if (a <= 0)
		{
			return false;
		}

		return true;
	}

	bool operator!()
	{
		if (a <= 0)
		{
			return true;
		}

		return false;
	}

	operator int()
	{
		return 10;
	}
public:
	int a;
};

void test()
{
	Maker m;
	m.SetA(10);
	if (m)
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}

	if (!m)
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}

	int b = (int)m;
	cout << b << endl;
}
int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}
```

## 字符串类

1.目的：设置一个类，类似于string的效果

# 八、继承

## 8.1 继承的作用

1.代码复用，2.扩展类的功能

## 8.2 继承的方式

1.继承方式，公有继承，私有继承，保护继承

2.子类对从父类继承过来的成员的权限

1.公有继承

​	1.父类的公有属性成员，到子类还是公有
​	2.父类的私有属性成员，到子类不能访问
​	3.父类的保护属性成员，到子类还是保护	

2.保护继承

​	1.父类的公有属性成员，到子类是保护
​	2.父类的私有属性成员，到子类不能访问
​	3.父类的保护属性成员，到子类还是保护	

3.私有继承

​	1.父类的公有属性成员，到子类还是私有
​	2.父类的私有属性成员，到子类不能访问
​	3.父类的保护属性成员，到子类还是私有	

## 8.3 继承中的构造和析构

1.继承中的构造和析构调用顺序

先调用父类的构造函数，再调用本身的构造函数，析构函数调用顺序反之

2.继承和组合混搭

先调用父类的构造，然后调用成员对象的构造，最后调用本身的构造，析构函数调用顺序反之

## 8.4 继承中同名成员的处理方法

1.通过父类名加作用域来访问，当子类和父类有同名成员时，子类的同名成员会隐藏父类的同名成员

2.当子类有和父类同名函数时，父类的所有重载函数都会被隐藏

## 8.5 继承中静态成员特性

1.静态成员可以被继承

2.继承中的静态成员变量一样会被同名的子类成员变量隐藏

3.继承中的静态成员函数中，当子类有和父类同名静态函数时，父类的所有重载静态函数都会被隐藏

4.改变从基类继承过来的静态函数的某个特征，返回值或者参数个数，将会隐藏基类重载的函数

5.静态成员函数不能是虚函数

6.从父类继承过来的静态成员变量是父类的静态成员变量

## 8.6 非自动继承的函数

1.构造，析构，赋值函数都不能被继承

## 8.7 多继承

1.多继承是一个类有两个以上的父类

2.多继承的问题是，当父类中有同名成员时，子类中会产生二义性问题

## 8.8 菱形继承

1.虚基类

被虚继承的基类叫虚基类

2.菱形继承的问题

两个父类中有祖类中的数据，然后子类会继承两个父类的数据，会产生二义性问题

3.虚继承

父类虚继承祖类，用virtual关键字

4.虚继承的原理

​	1.编译给类添加了一个指针，指针指向类似于表的组织，该表记录了该指针距离变量的偏移量

​	2.当子类多继承两个父类，那么只有一份成员变量，然后有两个指针，只有一份成员变量，所以不会产生二义性

## 8.9 动态联编和静态联编

1.静态联编

编译器会根据函数调用的对象类型,在编译阶段就确定函数的调用地址，这就是静态联编（早绑定）

2.虚函数

在普通成员函数前面加virtual，该函数变为虚函数，是告诉编译器这个函数要晚绑定

3.动态联编

在运行阶段才确定调用哪个函数（晚绑定），

4.动态编译的作用，可以晚绑定函数调用地址，这样可以扩展功能，不修改前面的代码的基础上进行项目的扩充

5.类型转换问题

​	1.子类转换成父类（向上转换）：编译器认为指针的寻址范围缩小了，所以是安全的

​	2.父类转换成子类（向下转换）；编译器认为指针的寻址范围扩大了，不安全

# 九、多态

## 9.1 多态概念

### 9.1.1 什么是多态

同一个操作作用于不同的对象，可以有不同的解释，会产生不同的效果，这就是多态

### 9.1.2 多态的作用

1.可以解决项目中的紧耦合问题,提供程序的可扩展性

2.应用程序不必为每一个子类的功能调用编写代码，只需要对抽象的父类进行处理

### 9.1.3 多态发生的三个条件

1.有继承。2.重写父类的虚函数。3.父类指针指向子类对象

## 9.2 多态实现的原理

```c++
class Animal
{
public:
	virtual void speak()
	{
		cout << "Anima speak()" << endl;
	}
	
};
class Dog :public Animal
{
public:
	virtual void speak()
	{
		cout << "Dog speak()" << endl;
	}
};

void test()
{
	cout << sizeof(Animal) << endl;

	Animal *animal = new Dog;
	animal->speak();
}
```

## 9.3 纯虚函数和抽象类

1.依赖倒转

业务层依赖抽象层，实现层依赖抽象层

```c++
//抽象层
class rule
{
public:
	virtual int getnum(int a,int b)
	{
		return 0;
	}
};

//实现层
class plus_rule :public rule
{
public:
	virtual int getnum(int a, int b)//重写父类的虚函数，依赖抽象层
	{
		return a+b;
	}
};




//业务层
int doLogin(rule *cal)
{
	
	int a = 10;
	int b = 20;
	

	int ret=cal->getnum(a, b);//依赖抽象层

	return ret;

}

void test()
{
	rule *r = NULL;
	r = new plus_rule;
	cout << doLogin(r) << endl;
	delete r;

}
```

2.开闭原则

对修改源代码关闭，对扩展新功能开发

```c++
//抽象层
class rule
{
public:
	virtual int getnum(int a,int b)
	{
		return 0;
	}
};

//实现层
class plus_rule :public rule
{
public:
	virtual int getnum(int a, int b)//重写父类的虚函数，依赖抽象层
	{
		return a+b;
	}
};
//扩展新功能
class miux_rule :public rule
{
public:
	virtual int getnum(int a, int b)
	{
		return a - b;
	}
};


//业务层
int doLogin(rule *cal)
{
	
	int a = 10;
	int b = 20;
	

	int ret=cal->getnum(a, b);//依赖抽象层

	return ret;

}

void test()
{
	rule *r = NULL;
	r = new plus_rule;
	cout << doLogin(r) << endl;
	delete r;
	//增加的代码
	r = new miux_rule;
	cout << doLogin(r) << endl;
	delete r;

}
```

3.纯虚函数

```c++
.纯虚函数
```

4.抽象类

1.有纯虚函数的类叫抽象类，不能实例化对象

```c++
//有纯虚函数的类叫抽象类，不能实例化对象
class rule
{
public:
	//纯虚函数
	virtual int getnum(int a, int b) = 0;
};

void test02()
{
	//抽象类不能实例化对象
	//rule r;
}
```

2.如果子类继承抽象类，子类必须实现抽象类的所有纯虚函数，不然子类也变为抽象类

```c++
class Maker
{
public:
	virtual void func1() = 0;
	virtual void func2() = 0;
};

class Son :public Maker
{
public:
	virtual void func1()
	{

	}
	virtual void func2()
	{

	}
};

void test03()
{
	Son s;
}
```

## 9.4 接口的定义

1.所谓的接口，即将内部实现细节封装起来，外部用户用过预留的接口可以使用接口的功能而不需要知晓内部具体细节。C++中，通过类实现面向对象的编程，而在基类中只给出纯虚函数的声明，然后在派生类中实现纯虚函数的具体定义的方式实现接口，不同派生类实现接口的方式也不尽相同

```c++
//抽象类
class Father
{
public:
	virtual void func1() = 0;//接口的声明
	virtual void func2(int a) = 0;
	virtual void func3(int a,int b) = 0;
};

class Son :public Father
{
public:
	virtual void func1()//接口的实现
	{

	}
	virtual void func2(int a)
	{

	}
	virtual void func3(int a, int b)
	{

	}
};
```

## 9.5 模版方法模式

1.在抽象类中确定好函数的调用顺序

```c++
class Drink
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//导入杯中
	virtual void PourInCup() = 0;
	//加点辅料
	virtual void addSonm() = 0;

	//模版方法,把调用函数的顺序确定下来
	void func()
	{
		Boil();
		Brew();
		PourInCup();
		addSonm();
	}
};
```

## 9.6 虚析构函数和纯虚析构函数

1.虚析构函数是为了解决基类指针指向派生类对象，并用基类指针释放派生类对象

```C++
class Animal
{
public:
	Animal()
	{
		cout << "Animal的构造" << endl;
	}

	//虚析构函数会调用子类的析构函数
	virtual ~Animal()
	{
		cout << "Animal的析构" << endl;
	}
};

class Son :public Animal
{
public:
	Son()
	{
		cout << "Son的构造" << endl;
		pName = new char[64];
		memset(pName, 0, 64);
		strcpy(pName, "如花");
	}

	~Son()
	{
		cout << "Son的析构" << endl;
		if (pName != NULL)
		{
			delete[] pName;
			pName = NULL;
		}
	}

public:
	char *pName;
};

void test()
{
	Animal *animal = new Son;
	delete animal;
}
```

2.纯虚析构函数，有纯虚析构函数的类是抽象类，不能实例化对象

注意：纯虚析构函数需要在类外实现

```C++
class Animal
{
public:
	Animal()
	{
		cout << "Animal的构造" << endl;
	}

	//虚析构函数会调用子类的析构函数
	/*virtual ~Animal()
	{
		cout << "Animal的析构" << endl;
	}*/

	//纯虚析构函数，纯虚析构函数需要在类外实现
	virtual ~Animal() = 0;
};

//在类外实现纯虚析构函数
Animal::~Animal()
{
	cout << "Animal的纯虚析构" << endl;
}
```

3.虚析构函数和纯虚析构函数的区别：

1.有纯虚析构函数的类是抽象类，不能实例化对象，而且要在类外实现

2.虚析构函数不需要在类外实现

## 9.7 多态案例

1.创建动物基类

```c++
class Animal
{
public:
	virtual void speak() = 0;
};
```

2.创建动物

```c++
class Dog :public Animal
{
public:
	Dog(string name)
	{
		this->name = name;
	}
	virtual void speak()
	{
		cout << "小狗" << name << "汪汪汪" << endl;
	}
private:
	string name;
};

class Dark :public Animal
{
public:
	Dark(string name,string type)
	{
		this->name = name;
		this->type = type;
	}
	virtual void speak()
	{
		cout <<type<<"品牌的"<< "小鸭" << name << "嘎嘎嘎" << endl;
	}
private:
	string name;
	string type;
};

class Tiger :public Animal
{
public:
	Tiger(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
	virtual void speak()
	{
		cout << age << "岁" << "老虎" << name << "嗷嗷嗷" << endl;
	}
private:
	string name;
	int age;

};
```

3.创建动物园

```c++
class Zoo
{
public:
	Zoo()
	{
		mCapacity = 1024;
		mSize = 0;
		//申请空间，存储Animal*的空间，指针数组
		this->p = new Animal*[mCapacity];
	}

	//增加动物
	int AddAnimal(Animal* animal)
	{
		if (mCapacity == mSize)
		{
			return -1;
		}
		//把指针存储到指针数组
		this->p[mSize] = animal;
		mSize++;

		return 0;
	}

	void StartSpeak()
	{
		for (int i = 0; i < mSize; i++)
		{
			p[i]->speak();
		}
	}

	//析构函数
	~Zoo()
	{
		//先释放指针数组中指针指向的堆区空间
		for (int i = 0; i < mSize; i++)
		{
			if (p[i] != NULL)
			{
				delete p[i];
				p[i] = NULL;
			}
		}

		//释放指针数组
		delete[] p;
		p = NULL;
	}


private:
	Animal* *p;
	int mCapacity;//容量
	int mSize;

};
```

4.使用

```C++
void test()
{
	//创建动物园
	Zoo *zoo = new Zoo;

	//添加动物
	zoo->AddAnimal(new Dog("晋三"));
	zoo->AddAnimal(new Dark("黑鸭", "周黑鸭"));
	zoo->AddAnimal(new Tiger("三胖", 35));

	zoo->StartSpeak();

	//烧了动物园
	delete zoo;
}
```

## 9.8 父类引用子类对象

```C++
class Animal
{
public:
	virtual void speak()
	{
		cout << "Animal speak()" << endl;
	}
};

class Dog :public Animal
{
public:
	virtual void speak()
	{
		cout << "Dog speak()" << endl;
	}
};

void test()
{
	Animal &animal = Dog();
	animal.speak();

	Animal* dog = new Dog();
	Animal* &an = dog;
	an->speak();
	delete dog;
}
```

## 9.9 重写，重载，重定义

1.重载，同一作用域的同名函数

2.重写（覆盖）:

​	1. 有继承

​	2.子类（派生类）重写父类（基类）的virtual函数

​	3.函数返回值，函数名字，函数参数，必须和基类中的虚函数一致

3.重定义（隐藏）

​	1. 有继承

​	2.子类（派生类）重新定义父类（基类）的同名成员（非virtual函数）

# 十、模板

## 10.1 模板的概念

1.函数或类是通用，但是里面的数据类型的多种状态

2.模版有：函数和类

## 10.2 函数模板

1.什么是函数模版

函数模板，**实际上是建立一个通用函数，其函数类型和形参类型不具体制定，用一个虚拟的类型来代表。这个通用函数就成为函数模板**

2.怎么编写函数模版

```c++
//T代表泛型的数据类型，不是只能写T，
template<class T>//让编译器看到这句话后面紧跟着的函数里有T不要报错
void mySwap(T &a,T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}


//可以这样定义函数模版
template<typename T>
void func2(T a,T b)
{

}
```

3.怎么使用函数模版

```c++
//T代表泛型的数据类型，不是只能写T，
template<class T>//让编译器看到这句话后面紧跟着的函数里有T不要报错
void mySwap(T &a,T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T>
void mySwap2()
{

}

//使用函数模版
void test02()
{
	int a = 10;
	int b = 20;

	//1.编译器会根据实参来自动推导数据类型
	mySwap(a,b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	char c = 'c';
	//mySwap(a, c);err,数据类型要一致

	//2.显示的指定类型
	mySwap<int>(a, b);//<>用参数列表告诉编译器我只传int类
	//mySwap<double>(a, b);//注意：指定类型，传入时不能不一致

	mySwap<>(a,b);
	//mySwap2<>();//err 调用时，必须让编译器知道泛型T具体是什么类型
}
```

4.编译器会对函数模版和类模版进行二次编译

```c++
//T代表泛型的数据类型，不是只能写T，
template<class T>//让编译器看到这句话后面紧跟着的函数里有T不要报错
void mySwap(T &a,T &b)//第一次编译
{
	T tmp = a;
	a= b;
	b = tmp;
}

//使用函数模版
void test02()
{
	int a = 10;
	int b = 20;

	//1.编译器会根据实参来自动推导数据类型
	mySwap(a,b);//编译器在函数模版被调用时，进行第二次编译
	/*
	void mySwap(int &a,int &b)
	{
		int tmp = a;
		a= b;
		b = tmp;
	}
	*/
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}
```

5.隐式转换

```c++
template<class T>
T func(T a, T b)
{
	return a + b;
}
void test03()
{
	int a = 10;
	double b = 20.2;
	//如果使用参数列表指定数据类型，那么实参中可以隐式转换，
	//如果转换成功，就调用，转换不成功就报错
	cout << func<int>(10,20.2) << endl;
}
```

## 10.3 普通函数与函数模板区别

1.普通函数可以进行隐式转换,函数模版不能直接的进行隐式转换

```c++
//普通函数
int myPlus(int a, int b)
{
	return a + b;
}

template<class T>
int myPlus2(T a, T b)
{
	return a + b;
}

void test()
{
	int a = 10;
	int b = 20;
	char c = 'a';
	//普通函数可以进行隐式转换
	myPlus(a, c);
	//函数模版不能直接的进行隐式转换
	//myPlus2(a, c);
	myPlus2<int>(a, c);//如果要进行隐性转换，必须加上参数列表
}
```

## 10.4 普通函数与函数模板的调用规则

```c++
//普通函数
void myPlus(int a, int b)
{
	cout << "普通函数" << endl;
}

template<class T>
void myPlus(T a, T b)
{
	cout << "函数模版" << endl;
}

template<class T>
void myPlus(T a, T b, T c)
{
	cout << "函数模版 T c" << endl;

}
//1.函数模版和普通函数可以重载
void test()
{
	int a = 10;
	int b = 20;
	//2.如果普通函数和函数模版都可以实现的功能，普通函数优先调用
	myPlus(a, b);

	//3.可以使用<>空参数列表强制调用函数模版
	myPlus<>(a, b);

	//4.函数模版之间也可以进行重载


	//5.如果函数模版可以产生更好的匹配，那么优先使用函数模版
	char c1 = 'a';
	char c2 = 'b';
	myPlus(c1, c2);
}
```

## 10.5 模版实现机制

l  **编译器并不是把函数模板处理成能够处理任何类型的函数**

l  **函数模板通过具体类型产生不同的函数**

l  **编译器会对函数模板进行两次编译，在声明的地方对模板代码本身进行编译，在调用的地方对参数替换后的代码进行编译。**

## 10.6 模版的局限性及解决方法

1.模版的局限性

```c++
template<class T>
void func(T a, T b)
{
	if (a > b)
	{
		cout << "a>b" << endl;
	}
	else
	{
		cout << "a<=b" << endl;
	}
}
void test()
{
//如果传入的是数组名，那么函数模版中比较函数名的大小就没有意义
	int arr[20];
	int arr2[10];

	func(arr, arr2);
}
```

2.解决方法，使用函数模版具体化

```c++
//不建议具体化函数模版，因为没有通用性
class Maker
{
public:
	Maker(string name,int age)
	{
		this->age = age;
		this->name = name;
	}
public:
	string name;
	int age;
};
template<class T>
void myfunc(T &a, T &b)
{
	if (a > b)
	{
		cout << "a>b" << endl;
	}
	else
	{
		cout << "a<=b" << endl;
	}
}
//不建议具体化函数模版，因为没有通用性
//具体化函数模版，注意上面的函数模版要有，才能具体化
template<>void myfunc<Maker>(Maker &a, Maker &b)
{
	cout << "函数模版的具体化" << endl;
	if (a.age > b.age)
	{
		cout << "a>b" << endl;
	}
	else
	{
		cout << "a<=b" << endl;
	}
}

void test02()
{
	Maker m1("aaa", 10);
	Maker m2("bbb", 20);

	myfunc(m1, m2);
}
```

## 10.7 类模版

1.类模版是把类中的数据类型参数化

```c++
template<class NameType,class AgeType>
class Maekr
{
public:
	Maekr(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}
public:
	NameType name;
	AgeType age;
};
```

2.类模版的使用

```c++
void test()
{
	//1.类模版不会自动推导数据类型，要显示的告诉编译器是什么类型
	Maker<string,int> m("悟空",18);
	m.printMaker();

	//2.注意传入的参数,传入参数类型要程序员自己把握
	Maker<int, int> m2(18, 20);
	m2.printMaker();

	//Maker<> m3("aaa",18);err,必须通过参数列表告诉编译器是什么类型

}
```

3.类模版和函数模版的区别

类模版不会自动推导数据类型，要显示的告诉编译器是什么类型

函数模版可以根据实参来推导数据类型

4.类模版的默认参数

```c++
//类模版的默认类型
template<class NameType, class AgeType=int>
class Maker2
{
public:
	Maker2(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void printMaker()
	{
		cout << "Name:" << this->name << " Age:" << this->age << endl;
	}
public:
	NameType name;
	AgeType age;
};

void test02()
{
	//如果有默认类型，那么<>里可以少写类型
	Maker2<string> m("贝吉塔", 20);

	m.printMaker();
	//以传入的类型为准
	Maker2<string, double> m2("wukong", 20.22);
	m2.printMaker();
}
```

5.类模版的默认参数注意

```c++
//默认类型后面的泛型类型都必须有默认类型
template<class NameType, class AgeType = int,class T=int>
class Maker3
{
public:
	Maker3(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void printMaker()
	{
		cout << "Name:" << this->name << " Age:" << this->age << endl;
	}
public:
	NameType name;
	AgeType age;
};
```

## 10.8 复数的模板类

1.目的：对象c1(3,4) ，对象c2(5,-10) ，对象c3=c1.Maker_add(c2) ，c3里的两个成员变量会等于a=3+5,b=4+(-10)并且数据类型可以不同

2.通过成员函数实现

```c++
template<class T>
class Maker
{
public:
	Maker()
	{
		a = 0;
		b = 0;

	}
	Maker(T r,T i)
	{
		a = r;
		b = i;
	}
	Maker Maker_add(Maker &c2)
	{
		Maker<T> c;
		c.a = this->a + c2.a;
		c.b = this->b + c2.b;
		return c;
	}

	void printMaker()
	{
		cout << "(" << a << "," << b << ")" << endl;
	}
private:
	T a;
	T b;
};

void test()
{
	Maker<int> c1(3, 4);
	Maker<int> c2(5, -10);
	Maker<int> c3;
	c3 = c1.Maker_add(c2);

	cout << "c1+c2=";
	c3.printMaker();

	Maker<double> d1(3.3, 4.4);
	Maker<double> d2(5.5, -10.1);
	Maker<double> d3;
	d3 = d1.Maker_add(d2);

	cout << "d1+d2=";
	d3.printMaker();
}
```

3.通过重载运算符实现

```c++
	Maker operator+(Maker &c2)
	{
		Maker tmp(this->a + c2.a, this->b + c2.b);
		return tmp;
	}

void test02()
{
	Maker<int> c1(3, 4);
	Maker<int> c2(5, -10);
	Maker<int> c3;
	c3 = c1 + c2;

	cout << "c1+c2=";
	c3.printMaker();
}
```

## 10.9 类模版做函数参数

1.指定传入类型

```c++
//1.指定传入的数据类型
void func(Maker<string,int> &m)
{
	m.printMaker();
}
```

2.参数模板化

```c++
//2.参数模版化（常用）
template<class T1,class T2>
void func2(Maker<T1,T2> &m)
{
	m.printMaker();
}
```

3.整个类 模板化

```c++
//3.整个类 模版化
template<class T>
void func3(T &m)
{
	m.printMaker();
}
```

## 10.10 类模版的继承

1.普通类继承类模版

```c++
//普通类继承类模版
template<class T>
class Father
{
public:
	Father()
	{
		m = 20;
	}
public:
	T m;
};

//普通类 继承 类模版
class Son :public Father<int>//要告诉编译器父类的泛型数据类型具体是什么类型
{
public:
	
};
```

2.类模版 继承 类模版

```c++
//类模版 继承 类模版
template<class T1,class T2>
class Son2 :public Father<T2>//要告诉编译器父类的泛型数据类型具体是什么类型
{

};
```

3.必须告诉编译器父类的泛型类型是什么数据类型

## 10.11 类模版的成员函数类内类外实现

1.类内实现

```c++
template<class NameType, class AgeType>
class Maker
{
public:
	Maker(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void printMaker()
	{
		cout << "Name:" << this->name << " Age:" << this->age << endl;
	}
public:
	NameType name;
	AgeType age;
};
```

2.类外实现，成员函数必须写成函数模版，并且写上参数列表

```c++
template<class NameType, class AgeType>
class Maker
{
public:
	Maker(NameType name, AgeType age);


	void printMaker();
	
public:
	NameType name;
	AgeType age;
};

//类模版的成员函数类外实现
//要写成函数模版
template<class NameType, class AgeType>
Maker<NameType, AgeType>::Maker(NameType name, AgeType age)
{

	cout << "构造函数" << endl;
	this->name = name;
	this->age = age;
}


template<class NameType, class AgeType>
void Maker<NameType, AgeType>::printMaker()
{
	cout << "Name:" << this->name << " Age:" << this->age << endl;
}
```

## 10.12 类模版分文件编写问题及解决方法

1.调用类模版时，要进行第二次编译，要把泛型的数据类型替换为具体的类型，这时需要知道函数体，但是函数的实现在.cpp中，那么调用类模版的.cpp没有引入实现.cpp，只引入.h，所以报错

2.解决方法：把成员函数放到.h中，然后把.h改为.hpp,然后在调用成员函数的地方，引入.hpp

3.为什么.hpp中有成员的实现，然后在调用类模版的地方引入.hpp，不会报重定义

类的成员函数默认申请为内联函数，在链接时，链接器会对重复的成员函数进行处理，只保留一份成员函数，所以不会进行报错

## 10.13 类模版碰到友元

1.友元类内实现

```c++
template<class NameType, class AgeType>
class Maker
{
	friend void printMaker(Maker<NameType, AgeType> &p)
	{
		cout << "类内实现" << p.name << " " << p.age << endl;
	}
public:
	Maker(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	
private:
	NameType name;
	AgeType age;
};

void test01()
{
	Maker<string, int> m("悟空", 18);

	printMaker(m);
}
```

2.友元类外实现

```c++
//1.声类模版
template<class NameType, class AgeType>
class Maker2;
//2.声明函数模版
//告诉编译器下面有printMaker2的实现
template<class NameType, class AgeType>
void printMaker2(Maker2<NameType, AgeType> &p);

template<class NameType, class AgeType>
class Maker2
{
	//3.在函数名和()之间加上<>。
	friend void printMaker2<>(Maker2<NameType, AgeType> &p);
	//编译器不知道printMaker2下面有没有实现，需要知道函数的结构
public:
	Maker2(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}


private:
	NameType name;
	AgeType age;
};

//4.友元在类外实现要写成函数模版
template<class NameType, class AgeType>
void printMaker2(Maker2<NameType, AgeType> &p)
{
	cout << "类外实现的友元函数 " << p.name << " " << p.age << endl;
}

void test02()
{
	Maker2<string, int> m("贝吉塔", 18);

	printMaker2(m);
}
```

## 10.14 类模版实现数组

```c++
MyArray.hpp
#pragma once

template<class T>
class MyArray
{
public:
	MyArray(int capacity)
	{
		this->mCapacity = capacity;
		this->mSize = 0;
		//T如果是Maker,这里要调用什么构造函数，要调用无参构造
		p = new T[this->mCapacity];

	}

	//拷贝构造
	MyArray(const MyArray &arr)
	{
		this->mCapacity = arr.mCapacity;
		this->mSize = arr.mSize;
		p = new T[arr.mCapacity];

		for (int i = 0; i < this->mSize; i++)
		{
			p[i] = arr.p[i];
		}
	}
	//赋值函数
	MyArray &operator=(const MyArray &arr)
	{
		if (this->p != NULL)
		{
			delete[] this->p;
			this->p = NULL;
		}

		p = new T[arr.mCapacity];
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;
		for (int i = 0; i < this->mSize; i++)
		{
			p[i] = arr.p[i];

		}

		return *this;
	}

	//重载[]
	T &operator[](int index)
	{
		return this->p[index];
	}
	//尾插
	void Push_Back(const T &val)
	{
		if (this->mSize == this->mCapacity)
		{
			return;
		}

		this->p[this->mSize] = val;
		this->mSize++;
	}

	//尾删
	void Pop_Back()
	{
		if (this->mSize == 0)
		{
			return;
		}

		this->mSize--;
	}

	~MyArray()
	{
		if (this->p != NULL)
		{
			delete[] p;
			p = NULL;
		}
	}

	int getSize()
	{
		return this->mSize;
	}
private:
	T *p;
	int mCapacity;
	int mSize;
};

//类模版实现数组.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"MyArray.hpp"
#include<string>
class Maker
{
public:
	Maker(){}
	Maker(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
public:
	string name;
	int age;
};

void printMaker(MyArray<Maker> &arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名:" << arr[i].name << " 年龄:" << arr[i].age << endl;
	}
}
void test()
{
	MyArray<Maker> myarr(4);
	Maker m1("悟空", 18);
	Maker m2("贝吉塔", 30);
	Maker m3("短笛", 200);
	Maker m4("小林", 19);
	myarr.Push_Back(m1);
	myarr.Push_Back(m2);
	myarr.Push_Back(m3);
	myarr.Push_Back(m4);

	printMaker(myarr);

	MyArray<int> myint(10);
	for (int i = 0; i < 10; i++)
	{
		myint.Push_Back(i + 1);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << myint[i] <<" ";
	}
	cout << endl;
}

int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}
```

# 十一、异常和IO

## 11.1 C++类型转换

**静态转换**：

用于[类层次结构](http://baike.baidu.com/view/2405425.htm)中基类（父类）和[派生类](http://baike.baidu.com/view/535532.htm)（子类）之间指针或引用的转换

用于基本数据类型之间的转换，如把int转换成char，把char转换成int。这种转换的安全性也要开发人员来保证

**动态转换：**

l  ynamic_cast主要用于类层次间的上行转换和下行转换；

l  在类层次间进行上行转换时，dynamic_cast和static_cast的效果是一样的；

l  在进行下行转换时，dynamic_cast具有类型检查的功能，比static_cast更安全；

**常量转换**

l  常量指针被转化成非常量指针，并且仍然指向原来的对象；

l  常量引用被转换成非常量引用，并且仍然指向原来的对象；

**重新解释转换**

这是最不安全的一种转换机制，最有可能出问题。

主要用于将一种数据类型从一种类型转换为另一种类型。它可以将一个指针转换成一个整数，也可以将一个整数转换成一个指针.

## 11.2 异常基本概念

**异常处理就是处理程序中的错误。所谓错误是指在程序运行的过程中发生的一些异常事件**

## 11.3 异常的作用

//C语言处理异常的方法的缺陷：
//1.返回值意思不明确
//2.返回值只能返回一条信息
//3.返回值可以忽略

C++的异常可以解决上面的问题

## 11.4 异常的基本语法

```c++
int func(int a, int b)
{
	if (b == 0)
	{
		//2.抛出异常
		throw 10;//抛出一个int类型的异常，
	}

	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;
	//1.把有可能出现异常的代码块放到try中
	try
	{
		func(a, b);
	}
	catch (int)//3.接收一个int类型的异常
	{
		cout << "接收一个int类型的异常" << endl;
	}

}
```

## 11.5 异常代码的执行流程

```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int func(int a, int b)
{
	if (b == 0)
	{
		//第二步：
		throw 10;//抛出一个int类型的异常，
		cout << "throw后的代码" << endl;
	}

	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;
	
	try
	{
		func(a, b);//第一步：
		cout << "func后的代码" << endl;
	}
	catch (int)//第三步：
	{
		cout << "接收一个int类型的异常" << endl;
	}

}
int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

```

## 11.6 异常的优势

1.用户不知道返回值是什么意思，异常可以抛出对象，对象中可以包含很多成员函数，可以有很信息

```c++
class Maker
{
public:
	void printMaker()
	{
		cout << "除数不能为0" << endl;
	}
};

int func(int a, int b)
{
	if (b == 0)
	{
		Maker m;
		throw m;
		
	}

	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;

	try
	{
		func(a, b);
		
	}
	catch (int)
	{
		cout << "接收一个int类型的异常" << endl;
	}
	catch (Maker maker)
	{
		cout << "接收一个Maker类型的异常" << endl;
		maker.printMaker();
	}

}
```

2.返回值用户可以忽略，但异常不能忽略，如果忽略给你报错

3.返回值只能返回一条信息，但是对象有成员函数，可以包含多个信息

4.逐层依赖处理异常

```c++
int func(int a, int b)
{
	if (b == 0)
	{
		//Maker m;
		//throw m;//抛出一个Maker类型的异常
		throw 20.22;//抛出一个double类型的异常
		
	}

	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;

	try
	{
		func(a, b);
		
	}
	catch (int)
	{
		cout << "接收一个int类型的异常" << endl;
	}
	catch (Maker maker)
	{
		cout << "接收一个Maker类型的异常" << endl;
		maker.printMaker();
	}
	catch (double s)
	{
		//不想处理异常，可以往上抛出，抛给调用本函数的函数
		throw;
	}


}

int main()
{
	try
	{
		test();
	}
	catch (double d)
	{
		cout << "接收一个double类型的异常" << endl;
	}




	system("pause");
	return EXIT_SUCCESS;
}

```

## 11.7 异常的严格类型匹配

```c++
int func(int a, int b)
{
	if (b == 0)
	{
		//Maker m;
		//throw m;//抛出一个Maker类型的异常
		//throw 20.22;//抛出一个double类型的异常
		//throw 'c';
		throw 20.0f;

	}

	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;

	try
	{
		func(a, b);

	}
	catch (int)
	{
		cout << "接收一个int类型的异常" << endl;
	}
	catch (double s)
	{
		cout << "接收一个double类型的异常" << endl;
	}
	catch (char)
	{
		cout << "接收一个char类型的异常" << endl;
	}
	catch (...)//接收其他类型的异常
	{
		cout << "接收一个其他类型的异常" << endl;
	}


}
```

## 11.8 异常的接口声明

```c++
void func() throw(int,char) //只允许抛出 int 或者 char异常
{
    throw 10; //抛出一个double类型的异常，QT上程序会档
}
int main()
{
        try
        {
            func();
        }
        catch(int)
        {

            cout << "int";
        }
        catch(...)
        {
            cout << ".....";
        }
    return 0;
}
```

## 11.9 栈解旋

1在抛出异常的函数中，如果抛出异常之后，但函数没有结束，这时，栈上申请的对象都会被释放这就叫栈解旋

```c++
class Maker
{
public:
	Maker()
	{
		cout << "Maker的构造" << endl;
	}
	Maker(const Maker &m)
	{
		cout << "Maker的拷贝构造" << endl;
	}
	~Maker()
	{
		cout << "Maker的析构" << endl;
	}
};

void func()
{
	//在抛出异常的函数中，如果抛出异常之后，但函数没有结束，这时，栈上申请的对象都会被释放
	//这就叫栈解旋
	Maker m;
	throw m;//这个m是Maker m拷贝一份的

	cout << "func函数结束" << endl;
}

void test()
{
	try
	{
		func();
		cout << "func()代码后" << endl;
	}
	catch (Maker)
	{
		cout << "接收一个Maker类型的异常" << endl;
	}


}
```

## 11.10 异常变量的生命周期

1.产生三个对象

```c++
class Maker
{
public:
	Maker()
	{
		cout << "Maker的构造" << endl;
	}
	Maker(const Maker &m)
	{
		cout << "Maker的拷贝构造" << endl;
	}
	~Maker()
	{
		cout << "Maker的析构" << endl;
	}
};
//产生三个对象
void func1()
{
	Maker m;//第一个对象，在异常接收前被释放
	throw m;//第二个对象，是第一个对象拷贝过来的
}

void test01()
{
	try
	{
		func1();
	}
	catch (Maker m1)//第三个对象，是第二个对象拷贝过来的
	{
		cout << "接收一个Maker类型的异常" << endl;
		//第二个和第三个对象在catch结束时释放

	}
}
```

2.产生二个对象

```c++
void func2()
{
	//第一个对象
	throw Maker();//匿名对象
}

void test02()
{
	try
	{
		func2();
	}
	catch (Maker m1)//第二个对象
	{
		cout << "接收一个Maker类型的异常" << endl;
		//第一个和第二个对象在catch结束时释放

	}
}
```

3.产生一个对象

```c++
void func3()
{
	throw Maker();//匿名对象

}

void test03()
{
	try
	{
		func3();
	}
	catch (Maker &m1)
	{
		cout << "接收一个Maker类型的异常" << endl;


	}

}
```

4.注意：

```c++
void func4()
{
	//编译器不允许对栈中的匿名对象取地址操作
	//throw Maker();//匿名对象
	//编译器允许对堆区中的匿名对象取地址操作
	throw new Maker();
}

void test04()
{
	try
	{
		func4();
	}
	catch (Maker *m1)
	{
		cout << "接收一个Maker类型的异常" << endl;

		delete m1;
	}
}
```

## 11.11 异常的多态

```c++
//异常的基类
class Father
{
public:
	virtual void printM()
	{

	}
};
//1.有继承
class SonNULL :public Father
{
public:
	virtual void printM()//2.重写父类的虚函数
	{
		cout << "空指针异常" << endl;
	}
};

class SonOut :public Father
{
public:
	virtual void printM()
	{
		cout << "越位溢出" << endl;
	}
};

void func(int a,int b)
{
	if (a == 0)
	{
		throw SonNULL();
	}
	
	if (b == 0)
	{
		throw SonOut();
	}
	
}

void test()
{
	int a = 0;
	int b = 10;
	try
	{
		func(a,b);
	}
	catch (Father &f)//3.父类引用指向子类对象
	{
		f.printM();
	}
}
```

## 11.12 系统提供的标准异常

1.系统的标准异常类

```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdexcept>//2013Vs可以不用
#include<string>

class Maker
{
public:
	Maker(int age)
	{
		if (age<0 || age>150)
		{
			throw out_of_range("年龄不在范围内");
			
		}
		else
		{
			this->age = age;
		}
	}
public:
	int age;
};

void test()
{
	try
	{
		Maker m(200);
	}
	catch (out_of_range &ex)
	{
		cout << ex.what() << endl;
	}

}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}
```

2.自己编写的异常类

```c++
class MyOut_of :public exception
{
public:
	MyOut_of(const char *errorinfo)
	{
		//const char*转换string
		this->m_Info = string(errorinfo);
	}
	MyOut_of(const string errorinfo)
	{
		this->m_Info = errorinfo;
	}
	const char *  what() const
	{
		//把string转换const char*
		return this->m_Info.c_str();
	}
public:
	string m_Info;
};

class Maker
{
public:
	Maker(int age)
	{
		if (age<0 || age>150)
		{
			
			throw MyOut_of("自己的异常类，年龄不在范围内");
		}
		else
		{
			this->age = age;
		}
	}
public:
	int age;
};

void test()
{
	try
	{
		Maker m(200);
	}
	catch (MyOut_of &ex)
	{
		cout << ex.what() << endl;
	}
}
```

## 11.13 系统标准的输入流

1.流的概念和流类库的结构（了解）

标准IO:对系统的标准输入输出设备进行读写

文件IO：对磁盘进行输入输出读写

串IO:对内存进行读写

2.成员函数

```c++
cin.get() //一次只能读取一个字符
cin.get(一个参数) //读一个字符
cin.get(两个参数) //可以读字符串
cin.getline()//取一行，换行符丢弃
cin.ignore()//忽略
cin.peek()//偷窥
cin.putback()//放回
```

3.案例

```c++
//判断用户输入的是字符串还是数字
void test06()
{
	cout << "请输入一个字符串或数字" << endl;

	char c=cin.peek();

	if (c >= '0'&&c <= '9')
	{
		int num;
		cin >> num;
		cout << "输入的数字是:" << num << endl;
	}
	else
	{
		char buf[1024] = { 0 };
		cin >> buf;
		cout << "输入的字符串是:" <<buf << endl;
	}
}

//输入一个0到10的数字，直到输入正确为止
void test07()
{
	int num;

	while (1)
	{
		cin >> num;
		if (num >= 0 && num <= 10)
		{
			cout << "输入正确" << endl;
			break;
		}
		cout << "重新输入：" << endl;
		//重置标志位
		cin.clear();
		//清空缓冲区
		//cin.sync();
		//2015
		char buf[1024] = { 0 };
		cin.getline(buf, 1024);

		//打印标志位
		cout << cin.fail() << endl;

	}
}

```

## 11.14 系统标准的输出流

1.通过成员函数格式化输出

```c++
//通过流成员函数实现格式化的输出
void test03()
{
	int num = 99;
	cout.width(20);//设置宽度
	cout.fill('*');//填充
	cout.setf(ios::left);//让数据在左边
	cout.unsetf(ios::dec);//卸载十进制
	cout.setf(ios::hex);//安装十六进制
	cout.setf(ios::showbase);//显示基数
	cout.unsetf(ios::hex);//卸载十六进制
	cout.setf(ios::oct);//安装八进制
	cout << num << endl;
}
```

2.通过控制符格式化输出

```c++
//通过控制符来格式化输出，引入头文件iomanip
void test04()
{
	int num = 99;
	cout << setw(20);//设置宽度
	cout << setfill('~');//填充
	cout << setiosflags(ios::showbase);//显示基数
	cout << setiosflags(ios::left);//让数据在左边
	cout << hex;//六十进制
	cout << oct;//八进制
	cout << dec;//十进制
	cout << num << endl;
}
```

3.打印浮点数后面的小数点

```c++
void test05()
{
	double d = 20.22;
	cout << setiosflags(ios::fixed);//设置显示浮点数
	cout << setprecision(10);//显示小数点后10位
	cout << d << endl;
}
```

## 11.15 文件读写操作

1.回顾C语言的文件读写

```c++
1.按照字符读写文件fgetc、fputc
int fputc(int ch, FILE * stream);//写
int fgetc(FILE * stream);//读

2.按照行读写文件fgets、fputs
int fputs(const char * str, FILE * stream);//写
char * fgets(char * str, int size, FILE * stream);//读

3.按照格式化文件fprintf、fscanf
int fprintf(FILE * stream, const char * format, ...);//写
int fscanf(FILE * stream, const char * format, ...);//读

4.按照块读写文件fread、fwrite
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);//写
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);//读
```

2.C++的文件读写

```c++
姓名:悟空" << endl;
	ofs << "年龄:18" << endl;
	ofs << "身高:180cm" << endl;

	//6.关闭文件
	ofs.close();//关闭文件，并刷新缓冲区

}

//把磁盘信息输入到缓冲区，然后读到程序中（读文件）
void test02()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (ifs.is_open() == false)
	{
		cout << "打开失败" << endl;
	}
	//第一种方式读取文件
	//一行一行读取
	/*char buf[1024] = { 0 };
	while (ifs>>buf)
	{
		cout << buf << endl;
	}*/
	//第二种方式读文件
	//char buf[1024] = { 0 };
	//while (!ifs.eof())//判断是否读到文件尾部
	//{
	//	ifs.getline(buf, sizeof(buf));
	//	cout << buf << endl;

	//}
	//第三种方式读取文件
	//单个字符读取
	char c;
	while ((c=ifs.get())!=EOF)
	{
		cout << c;
	}

	//关闭文件
	ifs.close();
}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

```

## 11.16 二进制文件读写

1.二进制读写

```c++
class Maker
{
public:
	Maker(){}
	Maker(const char*name,int age)
	{
		this->age = age;
		strcpy(this->name, name);
	}
public:
	char name[64];
	int age;
};

//写文件
void test01()
{
	Maker m1("悟空",18);
	Maker m2("贝吉塔", 22);

	ofstream ofs;
	ofs.open("test.txt", ios::out | ios::trunc | ios::binary);
	if (!ofs.is_open())
	{
		cout << "打开失败" << endl;
	}
	//写
	ofs.write((const char *)&m1, sizeof(Maker));
	ofs.write((const char *)&m2, sizeof(Maker));

	ofs.close();
}
//读文件
void test02()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
	}

	//读
	Maker m1;
	Maker m2;

	ifs.read((char*)&m1, sizeof(Maker));
	ifs.read((char*)&m2, sizeof(Maker));

	cout << "Name:" << m1.name << " Age:" << m1.age << endl;
	cout << "Name:" << m2.name << " Age:" << m2.age << endl;

	ifs.close();
}
```

2.文件读写中类有成员变量是string时的问题

注意：当文件读写时，类中的成员变量不要有string类型

```c++
class Maker
{
public:
	Maker(){}
	/*Maker(const char*name,int age)
	{
		this->age = age;
		strcpy(this->name, name);
	}*/
	Maker(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
public:
	string name;
	//string类中有一个成员指针char*,该指针指向存储字符串的空间
	//当我们把string类的数据存储到文件中，再读出来时，不能保证指针有效

	//string 开辟的空间如果大于16个字节就在堆区，小于就在栈区
	int age;
};
```

# 十二、STL

## 12.1 STL的介绍

1.STL(Standard TemplateLibrary,标准模板库)

2.STL提供了六大组件:容器，算法，迭代器，仿函数，适配器，空间配置器

​	容器：各种数据结构

​	算法：各种常用的算法（冒泡，排序）

​	迭代器：扮演了容器与算法之间的胶合剂（类似于指针等）

​	仿函数：行为类似函数，可作为算法的某种策略

​	适配器：一种用来修饰容器或者仿函数或迭代器接口的东西

​	空间配置器：负责空间的配置与管理

STL六大组件的交互关系，容器通过空间配置器取得数据存储空间，算法通过迭代器存储容器中的内容，仿函数可以协助算法完成不同的策略的变化，适配器可以修饰仿函数。

## 12.2 三大组件

容器：**序列式容器**和**关联式容器**

序列式容器：序列式容器就是容器元素在容器中的位置是由元素进入容器的时间和地点来决定

关联式容器：关联式容器是指容器已经有了一定的规则，容器元素在容器中的位置由容器的规则来决定

算法分为:**质变算法**和**非质变算法**

质变算法：：是指运算过程中会更改区间内的元素的内容

非质变算法：是指运算过程中不会更改区间内的元素内容

迭代器：重点学习双向迭代器和随机访问迭代器

双向迭代器：++,--可以访问下一个元素和上一个元素

随机访问迭代器：+2，可以跳2个元素访问元素

三大组件的关系：容器存储数据，并且提供迭代器，算法使用迭代器来操作容器中的元素

## 12.3 STL的工作机制

```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//数组容器
template<class T>
class MyArray
{
public:

	//保护原生指针，给原生指针取别名
	typedef T* iterator;
	MyArray()
	{
		mCapacity = 10;
		mSize = 10;
		p = new T[mCapacity];
		for (int i = 0; i < mCapacity; i++)
		{
			p[i] = i + 1;
		}
	}

	//提供迭代器，开始位置的迭代器
	T* begin()
	{
		return p;
	}

	//返回结束位置的迭代器
	T* end()
	{
		return p + mSize;
	}


public:
	T* p;
	int mCapacity;
	int mSize;
};

//算法
template<class T>
void printArray(T begin,T end)
{
	for (; begin != end; ++begin)
	{
		cout << *begin << " ";
	}
	
}
void test01()
{
	MyArray<int> arr;

	//获取容器提供的开始位置迭代器
	MyArray<int>::iterator begin=arr.begin();
	//获取容器提供的结束位置迭代器
	MyArray<int>::iterator end = arr.end();

	printArray(begin, end);
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}
```

## 12.4 STL的hello world

```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>//容器
#include<algorithm>//算法的头文件
#include<string>
using namespace std;

//加入算法的回调函数
void MyPrint(int val)
{
	cout << val << " ";
}
//1.存储数据
void test01()
{
	//容器
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//获取开始位置的迭代器
	vector<int>::iterator begin = v.begin();
	//获取结束位置的迭代器
	vector<int>::iterator end = v.end();
	/*
	void _For_each(_InIt _First, _InIt _Last, _Fn1& _Func)
	{	
		for (; _First != _Last; ++_First)
			_Func(*_First);
	}
	*/
	//遍历算法
	for_each(begin, end, MyPrint);
	cout << endl;

}

//2.容器存储对象
class Maker
{
public:
	Maker(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
public:
	string name;
	int age;
};
ostream &operator<<(ostream &out, Maker &m)
{
	out << "Name:" << m.name << " Age:" << m.age << endl;
	return out;
}

void test02()
{
	vector<Maker> v;
	//往容器中存储对象
	v.push_back(Maker("悟空", 18));
	v.push_back(Maker("小林", 19));
	v.push_back(Maker("贝吉塔", 25));
	v.push_back(Maker("龟仙人", 200));
	v.push_back(Maker("短笛", 180));

	//获取开始和结束位置的迭代器
	vector<Maker>::iterator begin = v.begin();
	vector<Maker>::iterator end = v.end();

	while (begin!=end)
	{
		cout << (*begin);
		begin++;

	}
}
//3.存储对象的指针
void test03()
{
	vector<Maker*> v;
	//创建数据
	Maker *m1 = new Maker("悟空", 18);
	Maker *m2 = new Maker("小林", 19);
	Maker *m3 = new Maker("贝吉塔",200 );
	Maker *m4 = new Maker("龟仙人",180 );
	Maker *m5 = new Maker("短笛", 18);

	v.push_back(m1);
	v.push_back(m2);
	v.push_back(m3);
	v.push_back(m4);
	v.push_back(m5);

	vector<Maker*>::iterator begin = v.begin();
	vector<Maker*>::iterator end = v.end();

	while (begin!=end)
	{
		cout << (*begin)->name << " " << (*begin)->age << endl;
		++begin;

	}

	delete m1;
	delete m2;
	delete m3;
	delete m4;
	delete m5;
}

//4.容器嵌套容器
void test04()
{
	vector<vector<int>> vs;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 10);
		v2.push_back(i + 10);
		v3.push_back(i + 10);
		v4.push_back(i + 10);
		v5.push_back(i + 10);
	}

	vs.push_back(v1);
	vs.push_back(v2);
	vs.push_back(v3);
	vs.push_back(v4);
	vs.push_back(v5);

	vector<vector<int>>::iterator begin = vs.begin();
	vector<vector<int>>::iterator end = vs.end();

	while (begin!=end)
	{
		vector<int>::iterator sbegin = (*begin).begin();
		vector<int>::iterator send = (*begin).end();

		while (sbegin!=send)
		{
			cout << *sbegin << " ";
			++sbegin;
		}

		cout << endl;
		++begin;
	}
}

int main()
{
	test04();
	system("pause");
	return EXIT_SUCCESS;
}
```

## 12.5 string容器

1.数据结构：连续的存储空间，用一个char*指向这片空间

2.迭代器:随机访问迭代器

3.常用的api：

​	1.构造

​	2.基本赋值

​	3.存取字符

​	4.拼接

​	5.查找和替换

​	6.比较

​	7.子串

​	8.插入和删除

​	9.string和const char*转换

4.常用的api中的注意:

​	1.[]和at区别：[]如果越界，不抛异常，直接挂。at会抛异常

​	2.字符串内存重新分配，[]和at获取的字符引用，再次使用时，可以能会出错

​	3.string和char *的区别：string是一个类，char *是一个指针

```c++
void test10()
{
	string s = "abcde";
	char &a = s[2];
	char &b = s[3];

	a = '1';
	b = '2';
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << s << endl;
	cout << "字符串的原空间地址:" << (int*)s.c_str() << endl;

	s = "fdasfdasfdsafdasherewrkewhsaferew";
	cout << "字符串的空间地址:" << (int*)s.c_str() << endl;

	//原空间被释放，但是a还是被释放的s[2]空间的别名，如果操作非法的空间，会出错
	//a = '3';


}
```

## 12.6 vector容器

1.数据结构:连续存储空间

2.迭代器：随机迭代器

3.vector容器动态增长原理

​	1.当存储空不够时，会开辟另一块大的空间，然后把数据拷贝过去，最后在销毁原来的空间

​	2.申请的空间,会比用户需求大一点

​	3.重新分配空间，那么原来的迭代器就会失效

4.常用的api:

​	1.构造

​	2.赋值操作

​	3.大小操作

​	4.数据存取

​	5.插入和删除

5.常用的api中的注意:

​	1.resize开辟空间，并初始化。reserve开辟空间，但不初始化.没有初始化的空间不能访问

6.reserve作用：如果容器要存储大量数据时，要先开辟空间，避免多次申请空间

7.swap作用:缩小容器的容量

## 12.7 deque容器

1.数据结构:逻辑上是连续的存储空间，实际上的由很多块定量的块空间，通过中控制连接起来

2.迭代器:随机迭代器

3.常用的api：

​	1.构造

​	2.赋值

​	3.大小

​	4.双端插入和删除操作

​	5.插入和删除操作

## 12.8 stack容器

1.数据结构：连续的存储空间，只有一个出口，先进后出特性

2.迭代器:没有迭代器

3.常用的api:

​	1.构造函数

​	2.赋值

​	3.数据存取

​	3.大小操作

## 12.9 queue容器

1.数据结构：连续的存储空间，有两个口，一个是进入数据，一个是出数据，有先进先出的特性

2.迭代器：没有迭代器

3.常用的api:

​	1.构造函数

​	2.存取、插入和删除操作

​	3.赋值

​	4.大小操作

## 12.10 list容器

1.数据结构：双向循环链表

2.迭代器：双向迭代器

3.常用的api:

​	1.构造

​	2.数据元素的插入和删除

​	3.大小操作

​	4.赋值操作

​	5.数据的存取

​	6.反转和排序

4.注意：list容器不能使用常用的sort,只能使用自己的sort

## 12.11 pair对组

1.pair对组是一个类，类中有两个公有的成员变量

2.对组通常用来接收key-vluae这样的元素

## 12.12 set/multiset容器

1.set容器是关联式容器，容器自身有规则，通过键值排序，set容器中的元素是键值也是实值

2.set容器和multiset容器的区别是multiset允许有相同的元素

3.数据结构：平衡二叉树

4.迭代器：双向迭代器

5.常用的api:

​	1.构造

​	2.赋值

​	3.大小

​	4.插入和删除

​	5.查找操作

6.改变规则：默认是从小到大，改变规则，加入谓词到<>第二个参数中

7.注意：

​	1.set容器插入相同元素时，不会报错，但是不插入数据

​	2.set容器存储对象时，需要告诉set容器的规则

## 12.13 map/multimap容器

1.map/multimap也是关联式容器，容器自身有规则，通过键值排序，map容器中的元素是对组，对组的第一个元素是键值，不能改变，第二个元素是实值，可以改变

2.数据结构：平衡二叉树

3.迭代器：双向迭代器

4.map容器和multimap容器的区别是multimap允许有相同的元素

5.常用的api:

​	1.构造

​	2.赋值

​	3.大小

​	4.查找

​	5.插入

​	6.删除

## 12.14 STL的深浅拷贝问题

1.把对象放入容器，其实是拷贝一份对象到容器。

2.注意：

​	1.拷贝构造要能被调用
​	2.注意要浅拷贝问题	

## 12.15 函数对象

1.什么是函数对象

​	1.类中重载了()，这个类实例化的对象叫函数对象（仿函数）;

​	2.一元仿函数是operator()中只需要一个参数。二元仿函数是operator()中需要二个参数

2.有什么用

​	1.做为算法的策略

```c++
void test()
{
	vector<int> v;
	v.push_back(8);
	v.push_back(1);
	v.push_back(6);
	v.push_back(3);
	v.push_back(7);


	sort(v.begin(), v.end(), greater<int>());

	for_each(v.begin(), v.end(), [](int val){cout << val << " "; });
	//[](int val){cout << val << " "; }//匿名函数


}
```

3.函数对象和普通函数的区别

​	1.函数对象可以有自己的状态

​	2.普通函数没有类型，函数对象有类型

​	3.函数对象比普通函数执行效率有可能更高（成员函数自动申请为内联函数）

4.谓词

​	1.谓词是指普通函数或重载的operator()返回值是bool类型的函数对象(仿函数)。

​	2.谓词可以作为一个判断式

​	3.接受一个参数，那么叫做一元谓词,如果接受两个参数，那么叫做二元谓词

5.内建函数对象

​	1.使用内建的函数对象要加入头文件#include<functional>

## 12.16 函数对象适配

1.什么是函数对象适配：当函数对象的参数不够用，那么可以用适配器来配置函数对象。

2.函数适配器：bind1st,bind2nd,将二元函数对象配置为一元函数对象

```c++
//第一步:继承binary_function<参数1，参数2，返回类型>
struct Myfunc:public binary_function<int,int,void>
{
	void operator()(int v1,int v2)const //第二步：加上const成为常函数，参数变2个
	{
		//cout << v1 << " " << endl;
		cout << v1 + v2 << endl;//第三步：实现函数体
	}

};
//需求：打印时，每个元素加100然后打印出来
void test()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//for_each(v.begin(), v.end(), Myfunc());
	//第四步：用bind2nd来绑定函数对象
	for_each(v.begin(), v.end(), bind2nd(Myfunc(),100));
}
```

3.bind1st和bind2nd的区别
bind1st把100绑定给第一个参数，bind2nd把100绑定给第二个参数

4.函数对象适配器 not1 not2 取反

1.not1和not2的区别：not1针对一元函数对象，not2针对二元函数对象

2.使用not1和not2

```c++
//第一步：继承
struct MyNotfunc:public unary_function<int,bool>
{
	bool operator()(int v)const //第二步：变为常函数
	{
		return v >= 20;
	}
	 
};
//not1 和not2 
void myPrint(int val)
{
	cout << val << " ";
}

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//find_if()

	/*
	_InIt _Find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{	// find first satisfying _Pred
		for (; _First != _Last; ++_First)
		if (_Pred(*_First))
			break;
		return (_First);
	}
	*/
	//第三步：适配
	vector<int>::iterator it=find_if(v.begin(), v.end(), not1(MyNotfunc()));
	if (it == v.end())
	{
		cout << "查找失败" << endl;
	}
	else
	{
		cout << "查找成功=" << *it << endl;
	}

	//not2的使用
	//less 二元函数对象
	vector<int> v2;
	v2.push_back(10);
	v2.push_back(50);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);
	//release模式下可以
	sort(v2.begin(), v2.end(),not2(less<int>()));
	for_each(v2.begin(), v2.end(), myPrint);
}
```

5.普通函数进行适配

```c++
//普通函数进行适配 ptr_fun
//第一步:把一个参数变为二个参数
void myprint2(int val,int val2)
{
	cout << val+val2<< " ";
}
void test03()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//第二步：把普通函数变为函数对象 ptr_fun
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myprint2),100));
}

```

6.成员函数适配

```c++
1.mem_fun : 如果存储的是对象指针，需要使用mem_fun

2.mem_fun_ref : 如果存储的是对象，需要使用mem_fun_ref
```

```c++
class Maker
{
public:
	Maker(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
	//成员函数
	void MyprintMaker()
	{
		cout << "Name:" << this->name << " Age:" << this->age << endl;
	}
public:
	string name;
	int age;
};
//void MyprintMaker(Maker m)
//{
//	cout << "Name:" << m.name << " Age:" << m.age << endl;
//}
void test04()
{
	vector<Maker> v;
	v.push_back(Maker("aaa", 10));
	v.push_back(Maker("bbb", 20));
	v.push_back(Maker("ccc", 30));
	//当容器存储的是对象，用mem_fun_ref适配他的成员函数
	for_each(v.begin(), v.end(), mem_fun_ref(&Maker::MyprintMaker));
	cout << "-------------" << endl;
	vector<Maker*> vp;
	vp.push_back(new Maker("aaa", 10));
	vp.push_back(new Maker("bbb", 20));
	vp.push_back(new Maker("ccc", 30));
	//当容器存储的是对象指针，用mem_fun适配他的成员函数
	for_each(vp.begin(), vp.end(), mem_fun(&Maker::MyprintMaker));
}
```

## 12.17 空间配置器

如果申请的内存大小超过128，那么空间配置器就自动调用一级空间配置器。反之调用二级空间配置器。

## 12.18 算法概念

1.算法通过迭代器来操作容器中元素

2.算法的头文件:<algorithm><functional><numeric>

## 12.19 遍历算法

```c++
1.for_each：遍历打印

  for_each(开始迭代器，结束迭代器，函数对象)

2.transform:搬运

  transform（源开始迭代器，源结束迭代器，目标开始迭代器，函数对象）

  transform（源1开始迭代器，源1结束迭代器，源2开始迭代器，目标开始迭代器，函数对象）
```



## 12.20 查找算法

```c++
1.find:查找元素

  find(开始迭代器，结束迭代器，要查找的数值);

  find_if(开始迭代器，结束迭代器,谓词或函数对象);

2.adjacent_find算法 查找相邻重复元素

  adjacent_find(开始迭代器，结束迭代器)

  adjacent_find(开始迭代器，结束迭代器,谓词或函数对象);

3.binary_search算法 二分查找法,注意：数据必须要有序，返回值是bool

  binary_search(开始迭代器，结束迭代器,数值)；

  binary_search（开始迭代器，结束迭代器,对象，函数对象）；

注意：存储对象，如果使用less，那么数据要是升序,并且要重载<，greater这需要数据是降序，并且要重载>

4.count 统计元素个数

  count（开始迭代器，结束迭代器,数值）；

  count（开始迭代器，结束迭代器，谓词或函数对象）；
```

## 12.21 排序算法

```c++
1.merge算法 容器元素合并，并存储到另一容器中

	1.如果数据是升序，那么第六个参数就不用写

	merge(开始迭代器1，结束迭代器1，开始迭代器2，结束迭代器2，目标开始迭代器)；

	2.如果数据是降序，那么第六个参数就要写greater<int>()

	merge(开始迭代器1，结束迭代器1，开始迭代器2，结束迭代器2，目标开始迭代器，greater<int>())；

2.sort算法 容器元素排序

	1.sort(开始迭代器，结束迭代器)；

	2.存储的是对象时,sort(开始迭代器，结束迭代器,函数对象)；

3.random_shuffle：洗牌

	定义随机种子：srand((unsigned int)time(NULL));

	random_shuffle（开始迭代器，结束迭代器）

4.reverse算法 反转指定范围的元素

	reverse（开始迭代器，结束迭代器）
```

## 12.22 拷贝和替换算法

```c++
1.copy：拷贝

	copy(源开始迭代器，源结束迭代器，目标开始迭代器)；

2.replace算法 将容器内指定范围的旧元素修改为新元素，replace_if算法 将容器内指定范围满足条件的元素替换为新元素

	1.replace（开始迭代器，结束迭代器，旧值，新值）；

	2.replace_if(开始迭代器，结束迭代器,谓词,新值)；

3.swap，交换容器

	swap(容器1，容器2)；
```

## 12.23 算术生成算法

```c++
1.accumulate算法 计算容器元素累计总和

	1.int ret=accumulate（开始迭代器，结束迭代器，数值）；//第三个参数是在总和上再加上0

	2.int ret=accumulate(开始迭代器，结束迭代器，数值,函数对象)；//针对存储对象

2.fill算法 向容器中添加元素

	1.要开辟容器的空间.v.resize(10);

	2.fill(开始迭代器，结束迭代器,要填充的数值)
```

## 12.24 集合算法

```c++
1.注意:两个集合必须是有序序列

2.set_intersection算法 求两个集合的交集

	set_intersection（源开始迭代器1，源结束迭代器1，源开始迭代器2，源结束迭代器2，,目标开始迭代器）；

3.set_union算法 求两个set集合的并集

	set_union（源开始迭代器1，源结束迭代器1，源开始迭代器2，源结束迭代器2，,目标开始迭代器）；

4.set_difference算法 求两个set集合的差集
//假如A集合有1,2,3,4,5 B集合有2,3,4,5,6 A集合减B集合的结果就是1

	set_difference（源开始迭代器1，源结束迭代器1，源开始迭代器2，源结束迭代器2，,目标开始迭代器）；
```

