# include<iostream>
using namespace std;

//����ģ��
template <typename T>   //����һ������ģ��
//����ģ��
void myswap(T& a, T& b)   //���ô���   
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a=10;
	int b=20;
	char c = 'c';
	cout << "����ǰ" << endl;
	cout << "a = " << a << " " << "b = " << b << endl;
	myswap(a, b);      //���÷�ʽһ   �Զ������Ƶ�
	//myswap<int>(a, b);   //���÷�ʽ��   ��ʾָ������
	//�Զ������Ƶ���ʱ�򣬱����Ƶ���һ�µ��������Ͳſ���ʹ��,��Ȼ�ᱨ��
	//myswap(a, c);   //���� ���Ͳ�һ��
	cout << "������" << endl;
	cout << "a = " << a << " " << "b = " << b << endl;
}

template<typename T>
void func()
{
	cout << "func�����ĵ���" << endl;
}

void test02()
{
	//func()    //���� ��Ϊû��ָ��T������
	func<int>();   //��Ȼ���õ����޲κ��������ǻ�����Ҫָ��T���������ͣ���Ȼ�ᱨ�����ָ������
}


//int main()
//{
//	//test01();
//	//test02();
//
//	system("pause");
//	return 0;
//}