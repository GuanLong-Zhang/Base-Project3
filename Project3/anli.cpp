# include<iostream>
# include<vector>
# include<deque>
# include<algorithm>
# include<ctime>
# include <list>
# include<map>
# include"myarray.hpp"
using namespace std;

# define 人事部门 0    //宏定义
# define 技术部门 1
# define 管理部门 2

//vector存放5个人 deque存放打的10个分数
class person6
{
public:
	string name;
	int score;
	person6(string n, int s)  //构造函数赋初值
	{
		name = n;
		score = s;
	}

};

void vectorprint(vector<person6>& v)
{
	for (vector<person6>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名："<< (*it).name << " " <<"分数：" << (*it).score << endl;
	}
	cout << "**********************************" << endl;
}

void creatperson6(vector<person6>& v)
{
	string nseed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string n = "选手";
		n += nseed[i];
		int s = 0;
		person6 p(n,s);
		v.push_back(p);   //将对象p放入容器中
	}
}

void setscore(vector<person6>& v)
{
	srand((unsigned int)time(NULL));  //随机数种子
	for (vector<person6>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 40 + 61;    //60~100
			d.push_back(score);
		}
		cout << (*it).name << "打分：" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;

		sort(d.begin(), d.end());   //升序排序
		d.pop_front();   //头删法
		d.pop_back();    //尾删法

		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}
		int avg = sum / d.size();
		(*it).score = avg;	
	}
	cout << "**********************************" << endl;
}

void test56()
{
	vector<person6> v;
	creatperson6(v);
	vectorprint(v);
	setscore(v);
	vectorprint(v);
}

//list容器案例
class person8
{
public:
	string name;
	int age;
	int height;
	person8(string n, int a, int h)
	{
		name = n;
		age = a;
		height = h;
	}
};

void listprint(list<person8> &l)
{
	for (list<person8>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "姓名：" << (*it).name << " " << "年龄：" << (*it).age << " " << "身高：" << (*it).height << endl;
	}
	cout << "*********************************" << endl;
}

bool compare(person8 &a,person8 &b)
{
	if (a.age != b.age)
	{
		return a.age < b.age;
	}
	else
	{
		return a.height > b.height;
	}
}

void test65()
{
	list<person8> l;
	person8 p1("小明", 18, 175);    //年龄升序，年龄相同身高降序
	person8 p2("小红", 38, 180);
	person8 p3("小李", 38, 165);
	person8 p4("小张", 28, 185);

	l.push_back(p1);   //将对象放入list容器
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	cout << "原样输出：" << endl;
	listprint(l);

	cout << "年龄升序,相同则身高降序：" << endl;
	l.sort(compare);   //指定函数  规定排序规则 括号里面存放函数名  
	listprint(l);

}

//容器综合案例
class worker
{
public:
	string name;
	int salary;
};

void createrworker(vector<worker>& v)
{
	string namespeed = "abcdefghijk";
	for (int i = 0; i < 10; i++)
	{
		worker w;
		w.name = "员工";
		w.name += namespeed[i];

		w.salary =rand() % 10000 + 10000;
		v.push_back(w);   //将对象送入vector

	}
}

void workerprint(vector<worker>& v)
{
	for (vector<worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).name <<"  " << "工资：" << (*it).salary << endl;
	}
	cout << endl;
}

void setgroup(vector<worker>& v, multimap<int, worker>& m)
{
	for (vector<worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int id = rand() % 3;  //部门编号

		m.insert(pair<int, worker>(id, (*it)));

	}
}

void showworker(multimap<int, worker>& m)
{
	multimap<int, worker>::iterator pos = m.find(人事部门);
	int nu = m.count(人事部门);
	int n = 0;
	cout << "人事部门" << endl;
	for (; pos != m.end(),n<nu; pos++,n++)
	{
		cout << "姓名：" << (*pos).second.name << " " << "薪资：" << (*pos).second.salary << endl;
	}

	cout << "--------------------------------" << endl;
	pos = m.find(技术部门);  //复用定义的类型
	nu = m.count(技术部门);
	n = 0;
	cout << "技术部门" << endl;
	for (; pos != m.end(), n < nu; pos++, n++)
	{
		cout << "姓名：" << (*pos).second.name << " " << "薪资：" << (*pos).second.salary << endl;
	}

	cout << "--------------------------------" << endl;
	pos = m.find(管理部门);
	nu = m.count(管理部门);
	n = 0;
	cout << "管理部门" << endl;
	for (; pos != m.end(), n < nu; pos++, n++)
	{
		cout << "姓名：" << (*pos).second.name << " " << "薪资：" << (*pos).second.salary << endl;
	}
	cout << endl;

}

void test78()
{
	srand((unsigned int)time(NULL));  //随机数种子
	vector<worker> v;
	createrworker(v);
	workerprint(v);
	multimap<int, worker> m;
	setgroup(v,m);
	showworker(m);

} 

//类模板案例  myarray.hpp
void printmyarray(myarray<int, int, int>& m)
{
	for (int i = 0; i < m.getsize(); i++)
	{
		cout << m[i] << " ";
	}
	cout << endl;
}

class person13
{
public:
	string name;
	int age;
	person13()
	{

	}
	person13(string a, int b)
	{
		name = a;
		age = b;
	}
};

void printperson13(myarray<person13, int, int>& m)
{
	for (int i = 0; i < m.getsize(); i++)
	{
		cout << "姓名："<< m[i].name <<" 年龄："<<m[i].age<<endl;
	}
}

void test84()
{
	//内置数据类型
	myarray<int, int, int> m1(5);
	for (int i = 0; i < 5; i++)
	{
		m1.pushback(i);   //尾插
	}
	cout << "m1输出" << endl;
	printmyarray(m1);
	cout << "容量：" << m1.getcapacity() << endl;
	cout << "大小：" << m1.getsize() << endl;

	myarray<int, int, int> m2(m1);  //拷贝构造
	cout << "m2输出" << endl;
	printmyarray(m2);
	m2.popback();   //尾删
	cout << "容量：" << m2.getcapacity() << endl;    //容量不变 大小变了
	cout << "大小：" << m2.getsize() << endl;

	myarray<int, int, int> m3(100);
	m3 = m1;

	//自定义数据类型
	myarray<person13, int, int> m4(10);
	person13 p1("小王", 18);
	person13 p2("小李", 28);
	person13 p3("小张", 38);
	person13 p4("小蓝", 48);
	m4.pushback(p1);
	m4.pushback(p2);
	m4.pushback(p3);
	m4.pushback(p4);
	printperson13(m4);
	cout << "容量：" << m4.getcapacity() << endl;    
	cout << "大小：" << m4.getsize() << endl;

}

//int main()
//{
//	//test56();
//	//test65();
//	//test78();
//	test84();
//
//	system("pause");
//	return 0;
//}