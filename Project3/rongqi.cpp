//STL 标准模板库
# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

void testcout(int val)
{
	cout << val << endl;
}

//vector容器存放内置数据类型
void test30()
{
	vector<int> v;   //创建vector

	v.push_back(10); //插入数据  尾插法
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//vector<int>::iterator itbegin = v.begin();   //起始迭代器  指向容器第一个元素位置
	//vector<int>::iterator itend = v.end();       //结束迭代器  指向容器最后一个元素的下一个位置

	////遍历输出1
	//while (itbegin != itend)
	//{
	//	cout << *itbegin << endl;    //itbegin相当于指针的用法
	//	itbegin++;
	//}
	
	//遍历输出2
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << endl;
	//}

	//遍历输出3   algorithm自带的遍历算法
	for_each(v.begin(), v.end(), testcout);

}

class person6
{
public:
	string name;
	int age;
	person6(string n, int a)
	{
		name = n;
		age = a;
	}
};

//vector容器存放自定义数据类型
void test31()
{
	vector<person6> v;
	person6 p1("小明", 18);
	person6 p2("小红", 28);
	person6 p3("小张", 38);
	person6 p4("小琪", 48);
	person6 p5("小李", 58);
	person6 p6("小高", 68);

	v.push_back(p1);   //插入数据 尾插法
	v.push_back(p2); 
	v.push_back(p3); 
	v.push_back(p4); 
	v.push_back(p5);
	v.push_back(p6);

	for (vector<person6>::iterator it = v.begin(); it != v.end(); it++)    //遍历输出   <>括号里面是啥那么*it就是啥
	{
		cout << "姓名：" << (*it).name << endl;
		cout << "年龄：" << (*it).age << endl;
	}

}

//vector容器存放自定义数据类型的指针
void test32()
{
	vector<person6*> v;
	person6 p1("小明", 18);
	person6 p2("小红", 28);
	person6 p3("小张", 38);
	person6 p4("小琪", 48);
	person6 p5("小李", 58);
	person6 p6("小高", 68);

	v.push_back(&p1);   //插入数据 尾插法
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	v.push_back(&p6);

	for (vector<person6*>::iterator it = v.begin(); it != v.end(); it++)    //遍历输出
	{
		cout << "::姓名：" << (*it)->age << endl;
		cout << "::年龄：" << (*it)->name << endl;
	}
}

//容器嵌套容器
void test33()
{
	vector<vector<int>> v;  //vector嵌套vector

	vector<int> v1;    //vector
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	for (int i = 0; i < 4; i++)   //赋值
	{
		v1.push_back(i);
		v2.push_back(i+1);
		v3.push_back(i+2);
		v4.push_back(i+3);
	}

	v.push_back(v1);   //vector插入vector
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it 是vector<int>  所以需要继续遍历
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}

//string容器
//string的构造函数
void test34()
{
	string s1;
	cout << "s1:" << s1 << endl;
	const char* str = "hello world";
	string s2(str);
	cout << "s2:" << s2 << endl;
	string s3(s2);
	cout << "s3:" << s3 << endl;
	string s4(10, 'H');          //10个H
	cout << "s4:" << s4 << endl;

}

//string赋值操作
void test35()
{
	string s1;
	s1 = "hello world";
	cout << "s1:" << s1 << endl;

	string s2;
	s2 = s1;
	cout << "s2:" << s2 << endl;

	string s3;
	s3 = 'c';
	cout << "s3:" << s3 << endl;

	string s4;
	s4.assign("hello c++");
	cout << "s4:" << s4 << endl;

	string s5;
	s5.assign("hello c++", 5);    //hello c++的前5个字符赋给s5
	cout << "s5:" << s5 << endl;

	string s6;
	s6.assign(s5);
	cout << "s6:" << s6 << endl;

	string s7;
	s7.assign(10, 'W');    //10个W
	cout << "s7:" << s7 << endl;
}

//string字符串拼接
void test36()
{
	string s1;
	s1 = "我";
	s1 += "是谁?";   //拼接一个字符串
	cout << "s1:" << s1 << endl;
	s1 += 'c';       //拼接一个字符
	cout << "s1:" << s1 << endl;
	string s2;
	s2 = "你是谁？";
	s2 += s1;  
	cout << "s2:" << s2 << endl;

	string s3;
	s3="我";
	s3.append("爱");
	cout << "s3:" << s3 << endl;
	s3.append("game abcdef", 4);   //前4个拼接
	cout << "s3:" << s3 << endl;
	s3.append(s2);
	cout << "s3:" << s3 << endl;
	string s4 = "game";
	s3.append(s4, 0, 2);   //从s4的第0个位置开始截取2个进行拼接
	cout << "s3:" << s3 << endl;
}

//string查找和替换
void test37()
{
	string s1 = "abcdefghde";
	int p=s1.find("de");   //假如字符串存在 则返回对应的位置 不存在则返回-1   find查找为从左往右查
	if (p == -1)
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "位置为：" << p << endl;    //3
	}

	int q = s1.rfind("de");      //refind查找为从右往左查
	if (q == -1)
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "位置为：" << q << endl;    //8
	}

	string s2 = "abcdefgh";
	s2.replace(1, 3, "1111");    //从第一个位置开始的3个字符替换为1111
	cout << "s2:" << s2 << endl;
}

//string字符串比较
void test38()
{
	string s1 = "aello";
	string s2 = "hello";
	if (s1.compare(s2) == 0)    //逐字符比较
	{
		cout << "s1等于s2" << endl;
	}
	else if (s1.compare(s2) > 0)
	{
		cout << "s1大于s2" << endl;
	}
	else
	{
		cout << "s1小于s2" << endl;
	}
}

//string字符存取
void test39()
{
	string s1 = "hello";
	cout << "s1:" << s1 << endl;

	for (int i = 0; i < s1.size(); i++)    //单个字符读取 []
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < s1.size(); i++)    // 单个字符读取 at
	{
		cout << s1.at(i) << " ";
	}
	cout << endl;

	s1[0] = 'a';      //修改单个字符[]
	cout << "s1:"<<s1 << endl;

	s1.at(0) = 'h';   //修改单个字符at
	cout << "s1:" << s1 << endl;
}

//string字符串插入和删除
void test40()
{
	string s1 = "hello";
	s1.insert(1, "1111");   //在第一个位置插入1111
	cout << "s1:" << s1 << endl;
	s1.erase(1, 4);         //从第一个位置开始删除4个字符
	cout << "s1:" << s1 << endl;
}

//string字串
void test41()
{
	string s1 = "abcdefgh";
	string s2 = s1.substr(1, 3);    //从第一个位置取三个字符
	cout << s2 << endl;
	string s3 = "zhangguanlong@qq.com";
	int p=s3.find('@');
	string s4 = s3.substr(0, p);
	cout << "s4:" << s4 << endl;
}

//vector容器
void vectorprint(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//vector构造函数
void test42()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);   //尾插法 插入数据
	}
	vectorprint(v1);

	vector<int> v2(v1.begin(), v1.end());  //将v1从开头到结尾的数据赋给v2
	vectorprint(v2);

	vector<int> v3(10, 100);   //将10个100赋给v3
	vectorprint(v3);

	vector<int> v4(v3);   //将v3整体赋给v4
	vectorprint(v4);
}

//vector赋值操作
void test43()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vectorprint(v1);

	vector<int> v2;     //=赋值
	v2 = v1;
	vectorprint(v2);

	vector<int> v3;     //assign赋值
	v3.assign(v1.begin(), v1.end());  
	vectorprint(v3);

	vector<int> v4;    //10个100
	v4.assign(10, 100);
	vectorprint(v4);
}

//vector容量和大小
void test44()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vectorprint(v1);

	if (v1.empty())   //容器为空
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器不为空" << endl;
		cout << "容器容量为：" << v1.capacity() << endl;    //13
		cout << "容器大小为：" << v1.size() << endl;      //10 容量>大小
	}

	v1.resize(15);   //调整大小  指定长了默认用0进行填充，当然也可以进行指定 
	vectorprint(v1);

	v1.resize(20,100);  //指定长了多出的位置用100进行填充
	vectorprint(v1);

	v1.resize(10);      //指定短了 进行自动删减
	vectorprint(v1);
}

//vector插入和删除
void test45()
{
	vector<int> v1;
	v1.push_back(1);   //尾插法 插入数字1
	v1.push_back(2);
	v1.push_back(3);
	vectorprint(v1);

	v1.pop_back();   //尾删法  删除一个元素
	vectorprint(v1);

	v1.insert(v1.begin(), 100);   //头部插入100
	vectorprint(v1);

	v1.insert(v1.begin(), 2, 1000);   //头部插入2个1000
	vectorprint(v1);

	v1.erase(v1.begin());   //删除头部一个元素
	vectorprint(v1);

	//v1.erase(v1.begin(), v1.end());  //从头到尾删除v1  等价于clear
	v1.clear();    //清空
	vectorprint(v1);
}

//vector数据存取
void test46()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);   //尾插法
	}

	for (int i = 0; i < v1.size(); i++)   //单个元素读取[]
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < v1.size(); i++)   //单个元素读取.at()
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	cout << "第一个元素：" << v1.front() << endl;
	cout << "最后一个元素：" << v1.back() << endl;

}

//vector容器互换
void test47()
{
	vector<int> v1;
	cout << "交换前" << endl;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);    //尾插法
	}
	vectorprint(v1);

	vector<int> v2;
	for (int i = 9; i >= 0; i--)
	{
		v2.push_back(i);
	}
	vectorprint(v2);

	cout << "交换后" << endl;
	v1.swap(v2);    //交换容器 v1 v2
	vectorprint(v1);
	vectorprint(v2);
}

//容器互换实际用途
void test48()
{
	vector<int> v1;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
	}
	cout << "容量为：" << v1.capacity() << endl;    //138255
	cout << "大小为：" << v1.size() << endl;        //100000

	v1.resize(3);   //大了用0进行填充 小了直接自动删除元素
	cout << "容量为：" << v1.capacity() << endl;     //138255
	cout << "大小为：" << v1.size() << endl;         //3

	vector<int>(v1).swap(v1);   //利用swap收缩内存   匿名对象(v1) 和v1 进行了交换，匿名对象在用完就被系统自动释放了
	cout << "容量为：" << v1.capacity() << endl;     //3
	cout << "大小为：" << v1.size() << endl;         //3
}

void test49()
{
	vector<int> v;
	v.reserve(100000);   //利用reserve 预留空间
	int num = 0;  //开辟次数
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);   //尾插法
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "num = " << num << endl;
}
//int main()
//{
//	//test30();
//	//test31();
//	//test32();
//	//test33();
//	//test34();
//	//test35();
//	//test36();
//	//test37();
//	//test38();
//	//test39();
//	//test40();
//	//test41();
//	//test42();
//	//test43();
//	//test44();
//	//test45();
//	//test46();
//	//test47();
//	//test48();
//	test49();
//
//	system("pause");
//	return 0;
//}