#include<iostream>
#include<string>
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

int main()
{
	//test85(10,10);
	//test86(" hello world !");
	test87();

	system("pause");
	return 0;
}