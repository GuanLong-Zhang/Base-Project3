#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

//��������(�º���)  �º���������һ���࣬������һ������,����С����
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
	cout<<"a + b = "<< m(a,b)<<endl;   //����������ʹ��ʱ����������ͨ����һ������
}

class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	int count;                        //��������������Լ�������
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
	cout << "MyPrint�����õĴ�����" << m.count << endl;
}

void doprint(MyPrint& m, string s)
{
	m(s);
}

void test87()
{
	MyPrint m;
	doprint(m, " hello c++ !");            //�������������Ϊ�������д���
}

//ν�� ����bool���͵ķº�����Ϊν��
class greater_five
{
public:
	bool operator()(int a)    //һԪν��
	{
		return a > 5;
	}
};

void test88()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);   //β�巨
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), greater_five());   //���ҵ�һ������һԪν��������Ԫ��,greater_five()Ϊ������������
	if (it == v.end())
	{
		cout << "δ���ҵ�����5��Ԫ��" << endl;
	}
	else
	{
		cout << "�ҵ�����5�ĵ�һ��Ԫ��Ϊ��" << *it << endl;
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
	bool operator()(int a, int b)    //��Ԫν��
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
	sort(v.begin(), v.end());    //Ĭ������
	print_vector_result(v);
	cout << "-----------------------------" << endl;
	sort(v.begin(), v.end(), MyCompare());   //����
	print_vector_result(v);
}

//�ڽ���������  STL�Դ��ĺ�������(�º���)   ��Ҫ����ͷ�ļ� #include<functional>
//�����º���   һԪ�Ͷ�Ԫ
//negate   ȡ��  һԪ�����º���   �����为��������������
void test90()
{
	negate<int>v;
	int a = 10;
	cout << "��ʼ a = " << a << endl;
	int b = v(a);
	cout << "ȡ�� a = " << b << endl;

}

//plus  �ӷ�   ��Ԫ�����º���
void test91()
{
	plus<int>p;
	int a = 10;
	int b = 20;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout<< "a + b ="<< p(a, b) << endl;
	//plus<int>p;     //�� �� �� �� ȡģ
	//minus<int>m;      
	//multiplies<int>m;
	//divides<int>d;
	//modulus<int>m;

}

//��ϵ�º���    ����  ������  ����  ���ڵ��� С�� С�ڵ���
void test92()
{
	vector<int>v;
	v.push_back(20);
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	print_vector_result(v);
	sort(v.begin(), v.end(), greater<int>());   //����
	print_vector_result(v);

}

//�߼��º���  �� �� ��
void test93()
{
	vector<int>v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	print_vector_result(v);
	vector<int>v1;
	v1.resize(v.size());   //�����ݰ���֮ǰ����Ҫ��Ŀ�������Ĵ�С����ָ��
	transform(v.begin(), v.end(), v1.begin(), logical_not<bool>());   //���ݰ���
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