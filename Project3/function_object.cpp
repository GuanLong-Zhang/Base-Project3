#include<iostream>
#include<string>
using namespace std;

//函数对象(仿函数)  仿函数本质是一个类，而不是一个函数,重载小括号
class MyAdd
{
public:
	int operator()(int a,int b)
	{
		return a + b;
	}
};

void test85(int a,int b)
{
	MyAdd m;
	cout<<"a + b = "<< m(a,b)<<endl;   //函数对象在使用时，可以像普通函数一样调用
}

class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	int count;                        //函数对象可以有自己的属性
	void operator()(string text)
	{
		cout << "message is :" << text << endl;
		count++;
	}
};

void test86(string text)
{
	MyPrint m;
	m(text);
	m(text);
	m(text);
	cout << "MyPrint被调用的次数：" << m.count << endl;
}

void doprint(MyPrint& m, string s)
{
	m(s);
}

void test87()
{
	MyPrint m;
	doprint(m, " hello c++ !");            //函数对象可以作为参数进行传递
}

int main()
{
	//test85(10,10);
	//test86(" hello world !");
	test87();

	system("pause");
	return 0;
}