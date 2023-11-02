#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<ctime>
using namespace std;

//STL常用算法1
//排序算法

void print_vector_106(int val)
{
	cout << val << " ";
}

class compare_106
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

//sort
void test106()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(20);
	v.push_back(70);
	v.push_back(60);
	for_each(v.begin(), v.end(), print_vector_106);    //遍历算法，传入普通函数
	cout << endl;
	sort(v.begin(), v.end());   //不传入谓词，默认升序
	for_each(v.begin(), v.end(), print_vector_106);    //遍历算法，传入普通函数
	cout << endl;
	sort(v.begin(), v.end(), compare_106());  //传入谓词，进行降序排序
	for_each(v.begin(), v.end(), print_vector_106);    //遍历算法，传入普通函数
	cout << endl;
	sort(v.begin(), v.end(), greater<int>());  //传入内建函数对象，进行降序排序
	for_each(v.begin(), v.end(), print_vector_106);    //遍历算法，传入普通函数
	cout << endl;

}

//random_shuffle   随机调整次序
void test107()
{
	srand((unsigned int)time(NULL));    //随机种子
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print_vector_106);
	cout << endl;
	random_shuffle(v.begin(), v.end());   //随机打乱顺序
	for_each(v.begin(), v.end(), print_vector_106);
	cout << endl;

}

//merge   合并两个容器，并将其存储到另外一个容器   两个容器必须有序，合并后得到的容器也是有序的
void test108()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>target;   //目标容器
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	target.resize(v1.size() + v2.size());    //给目标容器分配空间
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
	for_each(target.begin(), target.end(), print_vector_106);
	cout << endl;

}

//reverse   反转
void test109()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(70);
	v.push_back(60);
	cout << "原始数据：" << endl;
	for_each(v.begin(), v.end(), print_vector_106);
	cout << endl;
	cout << "反转数据：" << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), print_vector_106);
	cout << endl;
}

//常用的拷贝和替换算法
//copy 
void test110()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "v1的元素为：" << endl;
	for_each(v1.begin(), v1.end(), print_vector_106);
	cout << endl;
	vector<int>v2;
	v2.resize(v1.size());
	cout << "v2的元素为：" << endl;
	for_each(v2.begin(), v2.end(), print_vector_106);
	cout << endl;
	copy(v1.begin(), v1.end(), v2.begin());
	cout << "复制后的v2的元素为：" << endl;
	for_each(v2.begin(), v2.end(), print_vector_106);
	cout << endl;

}

class print_vector_111
{
public:
	void operator()(int a)
	{
		cout << a << " ";
	}
};

//replace 将容器内指定范围内的旧元素替换成新元素
void test111()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(20);
	v.push_back(20);
	v.push_back(30);
	v.push_back(90);
	v.push_back(50);
	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), print_vector_111());    //传入仿函数
	cout << endl;
	replace(v.begin(), v.end(), 20, 2000);     //将原容器中的20替换为2000
	cout << "替换后：" << endl;
	for_each(v.begin(), v.end(), print_vector_111());    //传入仿函数
	cout << endl;

}

int main()
{
	//test106();
	//test107();
	//test108();
	//test109();
	//test110();
	test111();

	system("pause");
	return 0;
}