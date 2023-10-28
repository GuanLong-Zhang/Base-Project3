# include<iostream>
using namespace std;
# include"person11.h"
# include"person12.hpp"

//普通函数与函数模板的区别：
//是否可以进行隐式类型转换
//普通函数调用可以实现隐式类型转换
//函数模板采用显式指定类型调用的时候可以

//普通函数和函数模板的调用规制：
// 都可以调用时，优先调用普通函数
// 通过空模板函数列表，强制调用函数模板
// 函数模板可以发生重载
// 当函数模板有更好的匹配效果时，优先调用函数模板

//普通函数
int add(int a, int b)
{
	cout << "普通函数调用" << endl;
	return a + b;
}

//函数模板
template<typename T>
T add(T a, T b)  
{
	cout << "函数模板调用" << endl;
	return a + b;
}

//函数模板重载
template<typename T>
T add(T a, T b, T c)
{
	cout << "函数模板重载调用" << endl;
	return a + b + c;
}

void test20()
{
	int a = 10;
	int b = 20;
	char ch = 'c';  //'c'对应的ascii码为99
	int d = 100;
	cout << "a+b = " << add(a, b) << endl;
	cout << "a+c = " << add(a, ch) << endl;   //隐式类型转换 将字符c转换为整型99
	cout << "a+b = " << add<>(a, b) << endl;   //空模板参数列表强制调用函数模板
	//cout << "a+c = " << add<>(a, ch) << endl;   //报错 自动类型推导数据类型需要一致  不会进行隐式类型转换
	cout << "a+c = " << add<int>(a, ch) << endl;   //显示指定类型可以进行隐式类型转换
	cout << "a+c+d = " << add(a, b, d) << endl;

	char ch1 = 'a';   //97
	char ch2 = 'b';   //98
	cout << "a+b = " << (int)add(ch1, ch2) << endl;
}

//模板的局限性
//模板并不是万能的,对于特定的数据类型，需要特殊处理

class person
{
public:
	string name;
	int age;
	person(string n, int a)  //构造函数初始化
	{
		name = n;
		age = a;
	}
};


//对于自定义的数据类型进行比较有俩种方式解决：
//方式一:等号重载
//方式二：具体化person版本

//方式一 等号重载
bool operator==(person& p1, person& p2)
{
	if (p1.name == p2.name && p1.age == p2.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//比较模板
template<typename T>
bool compare(T& a, T& b)   //对于内置数据类型可以进行比较，对于自定义的类型就不可以了
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//方式二 具体化person模板
template<>bool compare(person& p1, person& p2)
{
	if (p1.name == p2.name && p1.age == p2.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//内置数据比较
void test21()
{
	int a = 10;
	int b = 20;
	bool bl = compare(a, b);
	if (bl)
	{
		cout << "两者相同" << endl;
	}
	else
	{
		cout << "两者不同" << endl;
	}
}

//自定义数据比较
void test22()
{
	person p1("nike", 18);
	person p2("nike", 28);
	bool b2 = compare(p1, p2);
	if (b2)
	{
		cout << "两者相同" << endl;
	}
	else
	{
		cout << "两者不同" << endl;
	}
}

//类模板
template<class NT,class AT=int>    //类模板可以在参数列表中有默认参数
class person1
{
public:
	NT name;
	AT age;
	person1(NT n, AT a)   //构造函数初始化
	{
		name = n;
		age = a;
	}
	void show()
	{
		cout << "name:" << name << endl;
		cout << "age:" << age << endl;
	}
};

void test23()
{
	//person1 p1("tom", 18);   //报错 类模板没有自动类型推导
	person1<string, int> p1("tom", 18);   //调用只能采用显式指定类型
	p1.show();
	person1<string>p2("jack", 28);
	p2.show();

}

class person2
{
public:
	void showperson2()
	{
		cout << "showperson2" << endl;
	}
};

class person3
{
public:
	void showperson3()
	{
		cout << "showperson3" << endl;
	}
};

template<class T>
class person4
{
public:
	T obj;
	void func1()
	{
		obj.showperson2();
	}
	void func2()
	{
		obj.showperson3();
	}
};

void test24()
{
	person4<person3> p;
	//p.func1();    //类模板中的成员函数只有在被调用的时候才会创建
	p.func2();
}

//类模板对象做函数参数
template<class T1,class T2>
class person5
{
public:
	T1 name;
	T2 age;
	person5(T1 n, T2 a)
	{
		name = n;
		age = a;
	}
	void showperson5()
	{
		cout << "姓名：" << name << endl;
		cout << "年龄：" << age << endl;
	}
};

//1.指定传入类型
void printperson1(person5<string, int>&p)
{
	p.showperson5();
}

void test25()
{
	person5<string, int>p("小明", 28);
	printperson1(p);
}

//2.参数模板化   函数模板
template<typename T1,typename T2>
void printperson2(person5<T1, T2>& p)
{
	p.showperson5();
	cout << "T1的类型" <<typeid(T1).name() << endl;
	cout << "T2的类型" <<typeid(T2).name() << endl;
}

void test26()
{
	person5<string, int>p("小红", 38);
	printperson2(p);
}

//3.整个类模板化    函数模板
template<typename T>
void printperson3(T &p)
{
	p.showperson5();
}

void test27()
{
	person5<string, int>p("小张", 48);
	printperson3(p);
}

//类模板和继承
template<class T>
class base1    //父类 模板类
{
public:
	T m;
};

class son1 :public base1<int>    //必须<>指定父类中的T的数据类型 ，不然会报错
{

};

template<class T,class T1>
class son2 :public base1<T>   //子类 模板类   灵活指定父类中的T需要将子类也变为类模板
{
public:
	T1 m1;
};

void test79()
{ 
	son1 s1;   //实例化对象
	cout << "son1大小为：" << sizeof(s1) << endl;
	son2<int,char> s2;     //显示指定类型
	cout << "son2大小为：" << sizeof(s2) << endl;

}

//类模板成员函数类外实现
template<class T1, class T2>
class person10
{
public:
	T1 m1;
	T2 m2;
	//person10(T1 a, T2 b)    //类内实现
	//{
	//	m1 = a;
	//	m2 = b;
	//}
	//void showperson10()
	//{
	//	cout << "姓名：" << m1 << endl;
	//	cout << "年龄：" << m2 << endl;
	//}
	person10(T1 a, T2 b);   //类内声明 类外实现
	void showperson10();
};

template<class T1,class T2>
person10<T1,T2>::person10(T1 a, T2 b)
{
	m1 = a;
	m2 = b;
}

template<class T1, class T2>
void person10<T1, T2>::showperson10()
{
	cout << "姓名：" << m1 << endl;
	cout << "年龄：" << m2 << endl;
}


void test80()
{
	person10<string, int> p1("小明",18);
	p1.showperson10();

}

//类模板分文件编写
//方式一   .h 和 .cpp
template<class T1, class T2>
person11<T1, T2>::person11(T1 a, T2 b)
{
	m1 = a;
	m2 = b;
}

template<class T1, class T2>
void person11<T1, T2>::showperson11()
{
	cout << "姓名：" << m1 << endl;
	cout << "年龄：" << m2 << endl;
}

void test81()
{
	person11<string, int> p2("小红", 28);
	p2.showperson11();

}

//方式二    .hpp 直接将声明和实现写到一个文件中
void test82()
{
	person12<string, int> p3("小李", 38);
	p3.showperson12();
}

//类模板和友元
template<class T1, class T2>    //person13声明
class person13;

template<class T1, class T2>
void printperson13(person13<T1, T2>& p)
{
	cout << "类外实现" << endl;
	cout << "姓名：" << p.name << endl;
	cout << "年龄：" << p.age << endl;
}

template<class T1,class T2>
class person13
{
	//全局函数类内实现
	//friend void printperson13(person13<T1, T2>& p)    //加上friend 才可以访问私有属性 不加会报错  
	//{
	// 	cout << "类内实现" << endl;
	//	cout << "姓名：" << p.name << endl;
	//	cout << "年龄：" << p.age << endl;
	//}

	//全局函数类外实现
	friend void printperson13<>(person13<T1, T2>& p);   //类内声明 类外实现   需要加上<>用于说明是一个模板函数

public:
	person13(T1 a, T2 b)  //构造函数初始化
	{
		name = a;
		age = b;
	}
private:
	T1 name;
	T2 age;
};

void test83()
{
	person13<string, int> p("小芳", 48);
	printperson13(p);
}

//int main()
//{
//	//test20();
//	//test21();
//	//test22();
//	//test23();
//	//test24();
//	//test25();
//	//test26();
//	//test27();
//   //学习完容器后，又返回来学习类模板和继承，所以从79开始
//	//test79();
//	//test80();
//	//test81();
//	//test82();
//	test83();
//
//	system("pause");
//	return 0;
//}
