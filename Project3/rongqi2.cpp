# include<iostream>
# include<map>
using namespace std;

//pair对组的创建
void test71()
{
	//第一种方式
	pair<string, int> p("小明", 18);
	cout << "姓名：" << p.first << endl;
	cout << "年龄：" << p.second << endl;

	//第二种方式
	pair<string, int> p1 = make_pair("小红", 28);
	cout << "姓名：" << p1.first << endl;
	cout << "年龄：" << p1.second << endl;
}

void mapprint(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = "<< (*it).first << " " << "value = "<< (*it).second << " " << endl;
	}
	cout << endl;
}

//map容器 构造和赋值
void test73()
{
	map<int, int> m;     //默认构造
	m.insert(pair<int, int>(1, 10)); //键值 实值   按照键进行自动排序 默认升序
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(2, 20));
	mapprint(m);

	map<int, int> m1(m);    //拷贝构造
	mapprint(m1);

	map<int, int> m2 = m;  //赋值
	mapprint(m2);
}

//map大小和交换
void test74()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 100));
	m.insert(pair<int, int>(4, 400));
	m.insert(pair<int, int>(3, 300));
	m.insert(pair<int, int>(2, 200));
	mapprint(m);
	if (m.empty())
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "大小为：" << m.size() << endl;
	}
	cout << endl;

	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(2, 20));

	cout << "交换前" << endl;
	mapprint(m);
	mapprint(m1);

	m.swap(m1);
	cout << "交换后" << endl;
	mapprint(m);
	mapprint(m1);

}

//map插入和删除
void test75()
{
	map<int, int> m;
	//插入方式一
	m.insert(pair<int, int>(1, 10));

	//插入方式二
	m.insert(make_pair(4, 40));

	//插入方式三
	m.insert(map<int, int>::value_type(3,30));

	//插入方式四
	m[2] = 20;

	mapprint(m);

	m.erase(m.begin());    //删除第一个元素
	mapprint(m);
	
	m.erase(3);           //删除键为3的元素
	mapprint(m);

	//m.erase(m.begin(), m.end());   //删除区间
	m.clear();        //清空
	mapprint(m);
}

//map查找和统计
void test76()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));

	map<int,int>::iterator pos=m.find(3);    //按键查找
	if (pos != m.end())
	{
		cout << "元素查找到了" << endl;
		cout << "key = "<<(*pos).first << " " << "value = "<<(*pos).second << endl;
	}
	else
	{
		cout << "元素未找到" << endl;
	}

	int num = m.count(3);  //键为3的个数   map容器不允许插入键相同的元素  所以结果要不为0要不为1  multimap可以插入键相同的元素
	cout << "数量为：" << num << endl;
}

class mapcompare
{
public:
	bool operator()(int a, int b) const
	{
		return a > b;
	}
};

void mapprint1(map<int, int, mapcompare>& ma)
{
	for (map<int, int, mapcompare>::iterator it = ma.begin(); it != ma.end(); it++)
	{
		cout << "key = " << (*it).first << " " << "value = " << (*it).second << endl;
	}
	cout << endl;
}

//map指定排序规制
void test77()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));	
	m.insert(pair<int, int>(3, 30));
	mapprint(m);   //默认按照键值进行升序排序

	map<int, int, mapcompare> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(3, 30));
	mapprint1(m1);   //指定降序排序
}

//int main()
//{
//	//test71();
//	//test73();
//	//test74();
//	//test75();
//	//test76();
//	test77();
//
//	system("pause");
//	return 0;
//}