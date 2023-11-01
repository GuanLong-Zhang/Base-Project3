#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

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

//谓词 返回bool类型的仿函数称为谓词
class greater_five
{
public:
	bool operator()(int a)    //一元谓词
	{
		return a > 5;
	}
};

void test88()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);   //尾插法
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), greater_five());   //查找第一个满足一元谓词条件的元素,greater_five()为匿名函数对象
	if (it == v.end())
	{
		cout << "未查找到大于5的元素" << endl;
	}
	else
	{
		cout << "找到大于5的第一个元素为：" << *it << endl;
	}
}

void print_vector_result(vector<int> v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
}

class MyCompare
{
public:
	bool operator()(int a, int b)    //二元谓词
	{
		return a > b;
	}
};

void test89()
{
	vector<int> v;
	v.push_back(30);
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	sort(v.begin(), v.end());    //默认升序
	print_vector_result(v);
	cout << "-----------------------------" << endl;
	sort(v.begin(), v.end(), MyCompare());   //降序
	print_vector_result(v);
}

//内建函数对象  STL自带的函数对象(仿函数)   需要包含头文件 #include<functional>
//算数仿函数   一元和二元
//negate   取反  一元算数仿函数   正数变负数，负数变正数
void test90()
{
	negate<int>v;
	int a = 10;
	cout << "初始 a = " << a << endl;
	int b = v(a);
	cout << "取反 a = " << b << endl;

}

//plus  加法   二元算数仿函数
void test91()
{
	plus<int>p;
	int a = 10;
	int b = 20;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout<< "a + b ="<< p(a, b) << endl;
	//plus<int>p;     //加 减 乘 除 取模
	//minus<int>m;      
	//multiplies<int>m;
	//divides<int>d;
	//modulus<int>m;

}

//关系仿函数    等于  不等于  大于  大于等于 小于 小于等于
void test92()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	print_vector_result(v);
	sort(v.begin(), v.end(), greater<int>());   //降序
	print_vector_result(v);

}

//逻辑仿函数  与 或 非
void test93()
{
	vector<int>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	print_vector_result(v);
	vector<int>v1;
	v1.resize(v.size());   //在数据搬运之前，需要将目的容器的大小进行指定
	transform(v.begin(), v.end(), v1.begin(), logical_not<bool>());   //数据搬运
	print_vector_result(v1);
}

//int main()
//{
//	//test85(10,10);
//	//test86(" hello world !");
//	//test87();
//	//test88();
//	//test89();
//	//test90();
//	//test91();
//	//test92();
//	test93();
//
//	system("pause");
//	return 0;
//}