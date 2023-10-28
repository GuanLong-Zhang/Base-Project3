# include<iostream>
# include<deque>
# include<algorithm>
# include<stack>
# include<queue>
# include<list>
# include<set>
using namespace std;

//遍历deque 方法和vector类似
void dequeprint(const deque<int>& d)     //限定只读
{
	for (deque<int>::const_iterator it=d.begin(); it!=d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//deque容器构造函数
void test50()
{
	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);    //尾插法
	}
	dequeprint(d);
	deque<int> d1(d.begin(), d.end());    //区间赋值
	dequeprint(d1);
	deque<int> d2(10, 100);    //10个100
	dequeprint(d2);
	deque<int> d3(d2);         //d3拷贝d2
	dequeprint(d3);
}

//deque容器的赋值操作
void test51()
{
	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);    //尾插法
	}
	dequeprint(d);
	deque<int> d1 = d;     //=赋值
	dequeprint(d1);
	deque<int> d2;
	d2.assign(d1.begin(), d1.end());   //assign赋值
	dequeprint(d2);
	deque<int> d3;
	d3.assign(10, 100);  //10个100
	dequeprint(d3);
}

//deque容器的大小操作
void test52()
{
	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	dequeprint(d);
	if (d.empty())   
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器的大小为：" << d.size() << endl;

	}
	d.resize(15);    //长了 默认用0进行填充
	dequeprint(d);    
	d.resize(20,1);    //长了 指定用1填充
	dequeprint(d); 
	d.resize(10);      //短了 自动删除
	dequeprint(d);

}

//deque容器插入和删除
void test53()
{
	deque<int> d;
	d.push_back(10);    //尾插法
	d.push_back(20);
	d.push_front(30);   //头插法
	d.push_front(40);
	dequeprint(d);      //40 30 10 20
	d.pop_back();       //尾删法
	dequeprint(d);      //40 30 10
	d.pop_front();      //头删法
	dequeprint(d);      //30 10

	d.insert(d.begin(), 1000);       //头部插入1000
	dequeprint(d);
	d.insert(d.begin(), 2, 10000);       //头部插入2个10000
	dequeprint(d);
	deque<int> d1;
	for (int i = 0; i < 3; i++)
	{
		d1.push_back(i);
	}
	d.insert(d.begin(), d1.begin(), d1.end());
	dequeprint(d);

	deque<int>::iterator it = d.begin();   //起始迭代器
	it++;    //偏移
	d.erase(it);   //删除第二个元素
	dequeprint(d);
	d.erase(d.begin(), d.end());   //删除所有元素 等价于clear
	dequeprint(d);
	d.clear();
	dequeprint(d);
}

//deque容器的数据存取
void test54()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";     //[]读取数据
	}
	cout << endl;
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << " ";     //.at()读取数据
	}
	cout << endl;
	cout << "第一个元素：" << d.front() << endl;
	cout << "最后一个元素：" << d.back() << endl;
}

//deque容器排序操作
void test55()
{
	deque<int> d;
	d.push_back(10);    //尾插法
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);   //头插法
	d.push_front(200);
	d.push_front(300);

	dequeprint(d);
	sort(d.begin(), d.end());   //排序   升序排序
	cout << "排序后的结果" << endl;
	dequeprint(d);

}

//stack容器
void test57()
{
	stack<int> s;   //栈 先进后出
	s.push(10);     //入栈  栈顶
	s.push(20);
	s.push(30); 
	s.push(40);
	cout << "栈的大小：" << s.size() << endl;
	while (!s.empty())   //判空
	{
		cout << "栈顶元素：" << s.top() << endl;
		s.pop();    //出栈   栈顶
	}
	cout << "栈的大小：" << s.size() << endl;

}

class person7
{
public:
	string name;
	int age;
	person7(string n, int a)
	{
		name = n;
		age = a;
	}
};

//queue容器
void test58()
{
	queue<person7> q;
	person7 p0("小明", 18);
	person7 p1("小红", 28);
	person7 p2("小张", 38);
	person7 p3("小李", 48);
	q.push(p0);   //入队 队尾
	q.push(p1);
	q.push(p2);
	q.push(p3);
	cout << "大小为：" << q.size() << endl;
	while (!q.empty())   //判空
	{
		cout << "队头元素" << q.front().name<<" "<<q.front().age<<endl;
		cout << "队尾元素" << q.back().name << " " << q.back().age << endl;
		q.pop();     //出队 对头
	
	}
	cout << "大小为：" << q.size() << endl;
}

void listprint(list<int>& l)
{
	for (list<int>::iterator lit = l.begin(); lit != l.end(); lit++)
	{
		cout << *lit << " ";
	}
	cout << endl;
}

//list容器构造函数
void test59()
{
	list<int> l;
	l.push_back(10);   //尾插法
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	listprint(l);

	list<int> l1(l.begin(), l.end());   //区间构造
	listprint(l1);

	list<int> l2(l1);    //拷贝构造
	listprint(l2);

	list<int> l3(4, 1000);   //4个1000
	listprint(l3);
}

//list容器赋值和交换
void test60()
{
	list<int> l;
	l.push_back(10);   //尾插法
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	listprint(l);

	list<int> l1;
	l1 = l;    // =赋值
	listprint(l1);

	cout << "交换前" << endl;
	list<int> l2;
	l2.assign(l1.begin(), l1.end());     // assign 赋值
	listprint(l2);

	list<int> l3;
	l3.assign(4, 1000);   //4个1000
	listprint(l3);

	l2.swap(l3);
	cout << "交换后" << endl;
	listprint(l2);
	listprint(l3);

}

//list容器大小操作
void test61()
{
	list<int> l;
	l.push_back(10);   //尾插法
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	listprint(l);

	if (l.empty())
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "大小为：" << l.size() << endl;
	}
	l.resize(10);    //长了 默认用0进行填充
	cout << "大小为：" << l.size() << endl;
	listprint(l);

	l.resize(15, 1);  //长了 指定用1进行填充
	cout << "大小为：" << l.size() << endl;
	listprint(l);
	 
	l.resize(4);      //短了 自动删除
	cout << "大小为：" << l.size() << endl;
	listprint(l);
}

//list容器插入和删除
void test62()
{
	list<int> l;
	l.push_back(10);   //尾插
	l.push_back(20);
	l.push_back(30);
	l.push_front(100);  //头插
	l.push_front(200);
	l.push_front(300);
	listprint(l);   // 300 200 100 10  20  30
	l.pop_back();    //尾删
	listprint(l);
	l.pop_front();   //头删
	listprint(l);
	l.insert(l.begin(), 1000);   //开始迭代器 插入1000  可以改变迭代器的位置
	listprint(l);
	l.erase(l.begin());   //删除第一个元素
	listprint(l);
	l.push_front(10000);
	l.push_back(10000);
	listprint(l);
	l.remove(10000);      //删除元素10000   容器中所有的10000都进行删除
	listprint(l);
	l.clear();       //清空
	listprint(l);
}

//list容器数据存取
void test63()
{
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_front(10);
	l.push_front(20);
	listprint(l);

	//没有[] 和 .at() 这与list的结构有关 只能进行双向访问，本质为双向循环链表
	cout << "第一个元素" << l.front() << endl;
	cout << "最后一个元素" << l.back() << endl;
}

//降序
bool compare(int a, int b)
{
	return a > b;
}

//list容器反转和排序
void test64()
{
	list<int> l;
	l.push_back(50);
	l.push_back(20);
	l.push_back(10);
	l.push_back(40);
	listprint(l);
	l.reverse();   //反转
	listprint(l);
	l.sort();      //排序  升序    //sort(l.begin(),l.end()) 报错 只有随机访问迭代器支持这种方式
	listprint(l);
	l.sort(compare);  //降序  指定一个函数compare
	listprint(l);

}

//set multiset容器
void setprint(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//set容器构造和赋值
void test66()
{
	set<int> s;
	s.insert(20);    //set容器对于插入的数据自动进行排序 (默认升序)  不允许有重复的元素 即使插入重复的值也没有效果
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(30);
	setprint(s);   // 10 20 30 40

	set<int> s1(s);
	setprint(s1);

	set<int> s2 = s1;   //=赋值
	setprint(s2);
}

//set容器的大小和交换
void test67()
{
	set<int> s;
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(20);
	s.insert(20);
	setprint(s);   //set对于重复插入的数据没有效果，并且也不会计算其大小
	if (s.empty())
	{
		cout << "大小为空" << endl;
	}
	else
	{
		cout << "大小为：" << s.size() << endl;
	}

	set<int> s1;
	s1.insert(100);
	s1.insert(400);
	s1.insert(300);
	s1.insert(200);
	cout << "交换前:" << endl;
	setprint(s);
	setprint(s1);
	s.swap(s1);
	cout << "交换后：" << endl;
	setprint(s);
	setprint(s1);
}

//set容器插入和删除
void test68()
{
	set<int> s;
	s.insert(30);
	s.insert(40);
	s.insert(10);
	s.insert(20);
	setprint(s);
	s.erase(s.begin());
	setprint(s);
	s.erase(30);   //删除元素30
	setprint(s);
	//s.erase(s.begin(), s.end());   //指定区间进行删除，相当于clear
	s.clear();    //清空
	setprint(s);
}

//set容器的查找和统计
void test69()
{
	set<int> s;
	s.insert(30);
	s.insert(40);
	s.insert(10);
	s.insert(20);
	setprint(s);

	set<int>::iterator pos = s.find(40);  //find 查找对应元素，查找到就返回对应元素的迭代器，没有查找到就返回终止迭代器
	if (pos != s.end())
	{
		cout << "元素查找到了" << endl;
		cout << "元素为：" << *pos << endl;
	}
	else
	{
		cout << "元素未找到" << endl;
	}

	int num = s.count(40);   //统计个数
	cout << "数量为：" << num << endl;
}

//multiset容器
void multisetprint(multiset<int>& m)
{
	for (multiset<int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test70()
{
	multiset<int> m;    //multiset区别于set 允许插入重复的数据，并且进行自动升序排序
	m.insert(30);
	m.insert(40);
	m.insert(40);
	m.insert(10);
	m.insert(20);
	multisetprint(m);
}

class compare1   //仿函数
{
public:
	bool operator()(int a, int b)const     
	{
		return a > b;
	}
};

void setprint1(set<int, compare1>& s)
{
	for (set<int, compare1>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

class person9
{
public:
	string name;
	int age;
	person9(string n, int a)
	{
		name = n;
		age = a;
	}
};

class compare2    //仿函数
{
public:
	bool operator()(const person9& p1, const person9& p2)const
	{
		return p1.age > p2.age;
	}
};

void setprint2(set<person9,compare2>& s)
{
	for (set<person9,compare2>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout <<"姓名："<< (*it).name << " " <<"年龄："<< (*it).age << endl;
	}
	cout << endl;
}



//set容器的排序
void test72()
{
	set<int> s;    //自动进行升序排序
	s.insert(10);
	s.insert(40);
	s.insert(20);
	s.insert(30);
	setprint(s);

	set<int,compare1> s1;    //指定排序规制 降序
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	setprint1(s1);

	set<person9,compare2> s2;  //按照年龄降序
	person9 p1("小明", 28);
	person9 p2("小红", 18);
	person9 p3("小李", 38);

	s2.insert(p1);
	s2.insert(p2);
	s2.insert(p3);
	setprint2(s2);

}

//int main()
//{
//	//test50();
//	//test51();
//	//test52();
//	//test53();
//	//test54();
//	//test55();
//	//test57();
//	//test58();
//	//test59();
//	//test60();
//	//test61();
//	//test62();
//	//test63();
//	//test64();
//	//test66();
//	//test67();
//	//test68();
//	//test69();
//	//test70();
//	//test72();
//
//	system("pause");
//	return 0;
//}