#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//STL常用算法
//遍历算法

//普通函数
void print_vector(int val)   
{
	cout << val << " ";
}

//仿函数
class MyPrint
{
public:
	void operator()(int a)
	{
		cout << a << " ";
	}
};

//for_each()   遍历容器
void test94()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(),print_vector);   //传入普通函数
	cout << endl;
	for_each(v.begin(), v.end(), MyPrint());     //传入仿函数
	cout << endl;
}

//仿函数
class Transform
{
public:
	int operator()(int v)    
	{
		return v + 100;
	}
};

//transform()   将一个容器的内容搬运到另外一个容器
void test95()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>v1;
	v1.resize(v.size());   //给目标容器开辟空间
	transform(v.begin(), v.end(), v1.begin(), Transform());    //传入仿函数
	for_each(v1.begin(), v1.end(), MyPrint());                 //传入仿函数
	cout << endl;
}

//查找算法

//find
void test96()    
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find(v.begin(), v.end(), 50);      //find内置数据类型
	if (it == v.end())
	{
		cout << "没有查找到指定元素" << endl;
	}
	else
	{
		cout << "查找到了指定元素" << endl;
		cout << "查找到的元素为：" << *it << endl;
	}

}

class Person_97
{
public:
	string MyName;
	int Age;
	Person_97(string name, int age)
	{
		this->MyName = name;
		this->Age = age;
	}
	bool operator==(const Person_97 &p)     //需要对==进行重载,编译器才知道如何对自定义数据类型比较
	{
		if (p.Age == this->Age && p.MyName == this->MyName)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void test97()
{
	vector<Person_97>v;
	Person_97 p1("aaa", 10);
	Person_97 p2("bbb", 20);
	Person_97 p3("ccc", 30);
	Person_97 p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person_97 pp("bbb", 20);   //待查元素
	vector<Person_97>::iterator it =  find(v.begin(), v.end(), pp);    //find自定义数据  
	if (it == v.end())
	{
		cout << "没有查找到指定内容" << endl;
	}
	else
	{
		cout << "查找到了指定内容" << endl;
		cout << "查找到的内容为：" << (*it).MyName<<" "<<(*it).Age << endl;
	}

}

//find_if
class Greater
{
public:
	bool operator()(int a)    //一元谓词
	{
		return a > 5;
	}
};

void test98()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//find_if内置数据类型   传入一元谓词   返回第一个满足的元素
	vector<int>::iterator it = find_if(v.begin(), v.end(), Greater());  
	if (it == v.end())
	{
		cout << "没有查找到指定元素" << endl;
	}
	else
	{
		cout << "查找到了指定元素" << endl;
		cout << "查找到的元素为：" << *it << endl;
	}
}

class Greater20
{
public:
	bool operator()(Person_97& p)
	{
		return p.Age > 20;
	}
};

void test99()
{
	vector<Person_97>v;
	Person_97 p1("aaa", 10);
	Person_97 p2("bbb", 20);
	Person_97 p3("ccc", 30);
	Person_97 p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	//find_if内置数据类型   传入一元谓词   返回第一个满足的元素  
	vector<Person_97>::iterator it = find_if(v.begin(), v.end(), Greater20());     
	if (it == v.end())
	{
		cout << "没有查找到指定元素" << endl;
	}
	else
	{
		cout << "查找到了指定元素" << endl;
		cout << "查找到的元素为：" << (*it).MyName << " " << (*it).Age << endl;
	}
}

//adjacent_find()   查找相邻重复元素
void test100()
{
	vector<int>v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(3);
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());   //返回相邻重复元素的第一个位置迭代器
	if (it == v.end())
	{
		cout << "没有查找到相邻重复元素" << endl;
	}
	else
	{
		cout << "查找到了相邻重复元素" << endl;
		cout << "相邻重复元素为：" << *it << endl;
	}

}
int main()
{
	//test94();
	//test95();
	//test96();
	//test97();
	//test98();
	//test99();
	test100();

	system("pause");
	return 0;
}