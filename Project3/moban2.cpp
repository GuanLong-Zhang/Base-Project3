# include<iostream>
using namespace std;
# include"person11.h"
# include"person12.hpp"

//��ͨ�����뺯��ģ�������
//�Ƿ���Խ�����ʽ����ת��
//��ͨ�������ÿ���ʵ����ʽ����ת��
//����ģ�������ʽָ�����͵��õ�ʱ�����

//��ͨ�����ͺ���ģ��ĵ��ù��ƣ�
// �����Ե���ʱ�����ȵ�����ͨ����
// ͨ����ģ�庯���б�ǿ�Ƶ��ú���ģ��
// ����ģ����Է�������
// ������ģ���и��õ�ƥ��Ч��ʱ�����ȵ��ú���ģ��

//��ͨ����
int add(int a, int b)
{
	cout << "��ͨ��������" << endl;
	return a + b;
}

//����ģ��
template<typename T>
T add(T a, T b)  
{
	cout << "����ģ�����" << endl;
	return a + b;
}

//����ģ������
template<typename T>
T add(T a, T b, T c)
{
	cout << "����ģ�����ص���" << endl;
	return a + b + c;
}

void test20()
{
	int a = 10;
	int b = 20;
	char ch = 'c';  //'c'��Ӧ��ascii��Ϊ99
	int d = 100;
	cout << "a+b = " << add(a, b) << endl;
	cout << "a+c = " << add(a, ch) << endl;   //��ʽ����ת�� ���ַ�cת��Ϊ����99
	cout << "a+b = " << add<>(a, b) << endl;   //��ģ������б�ǿ�Ƶ��ú���ģ��
	//cout << "a+c = " << add<>(a, ch) << endl;   //���� �Զ������Ƶ�����������Ҫһ��  ���������ʽ����ת��
	cout << "a+c = " << add<int>(a, ch) << endl;   //��ʾָ�����Ϳ��Խ�����ʽ����ת��
	cout << "a+c+d = " << add(a, b, d) << endl;

	char ch1 = 'a';   //97
	char ch2 = 'b';   //98
	cout << "a+b = " << (int)add(ch1, ch2) << endl;
}

//ģ��ľ�����
//ģ�岢�������ܵ�,�����ض����������ͣ���Ҫ���⴦��

class person
{
public:
	string name;
	int age;
	person(string n, int a)  //���캯����ʼ��
	{
		name = n;
		age = a;
	}
};


//�����Զ�����������ͽ��бȽ������ַ�ʽ�����
//��ʽһ:�Ⱥ�����
//��ʽ�������廯person�汾

//��ʽһ �Ⱥ�����
bool operator==(person& p1, person& p2)
{
	if (p1.name == p2.name && p1.age == p2.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//�Ƚ�ģ��
template<typename T>
bool compare(T& a, T& b)   //���������������Ϳ��Խ��бȽϣ������Զ�������;Ͳ�������
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��ʽ�� ���廯personģ��
template<>bool compare(person& p1, person& p2)
{
	if (p1.name == p2.name && p1.age == p2.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//�������ݱȽ�
void test21()
{
	int a = 10;
	int b = 20;
	bool bl = compare(a, b);
	if (bl)
	{
		cout << "������ͬ" << endl;
	}
	else
	{
		cout << "���߲�ͬ" << endl;
	}
}

//�Զ������ݱȽ�
void test22()
{
	person p1("nike", 18);
	person p2("nike", 28);
	bool b2 = compare(p1, p2);
	if (b2)
	{
		cout << "������ͬ" << endl;
	}
	else
	{
		cout << "���߲�ͬ" << endl;
	}
}

//��ģ��
template<class NT,class AT=int>    //��ģ������ڲ����б�����Ĭ�ϲ���
class person1
{
public:
	NT name;
	AT age;
	person1(NT n, AT a)   //���캯����ʼ��
	{
		name = n;
		age = a;
	}
	void show()
	{
		cout << "name:" << name << endl;
		cout << "age:" << age << endl;
	}
};

void test23()
{
	//person1 p1("tom", 18);   //���� ��ģ��û���Զ������Ƶ�
	person1<string, int> p1("tom", 18);   //����ֻ�ܲ�����ʽָ������
	p1.show();
	person1<string>p2("jack", 28);
	p2.show();

}

class person2
{
public:
	void showperson2()
	{
		cout << "showperson2" << endl;
	}
};

class person3
{
public:
	void showperson3()
	{
		cout << "showperson3" << endl;
	}
};

template<class T>
class person4
{
public:
	T obj;
	void func1()
	{
		obj.showperson2();
	}
	void func2()
	{
		obj.showperson3();
	}
};

void test24()
{
	person4<person3> p;
	//p.func1();    //��ģ���еĳ�Ա����ֻ���ڱ����õ�ʱ��Żᴴ��
	p.func2();
}

//��ģ���������������
template<class T1,class T2>
class person5
{
public:
	T1 name;
	T2 age;
	person5(T1 n, T2 a)
	{
		name = n;
		age = a;
	}
	void showperson5()
	{
		cout << "������" << name << endl;
		cout << "���䣺" << age << endl;
	}
};

//1.ָ����������
void printperson1(person5<string, int>&p)
{
	p.showperson5();
}

void test25()
{
	person5<string, int>p("С��", 28);
	printperson1(p);
}

//2.����ģ�廯   ����ģ��
template<typename T1,typename T2>
void printperson2(person5<T1, T2>& p)
{
	p.showperson5();
	cout << "T1������" <<typeid(T1).name() << endl;
	cout << "T2������" <<typeid(T2).name() << endl;
}

void test26()
{
	person5<string, int>p("С��", 38);
	printperson2(p);
}

//3.������ģ�廯    ����ģ��
template<typename T>
void printperson3(T &p)
{
	p.showperson5();
}

void test27()
{
	person5<string, int>p("С��", 48);
	printperson3(p);
}

//��ģ��ͼ̳�
template<class T>
class base1    //���� ģ����
{
public:
	T m;
};

class son1 :public base1<int>    //����<>ָ�������е�T���������� ����Ȼ�ᱨ��
{

};

template<class T,class T1>
class son2 :public base1<T>   //���� ģ����   ���ָ�������е�T��Ҫ������Ҳ��Ϊ��ģ��
{
public:
	T1 m1;
};

void test79()
{ 
	son1 s1;   //ʵ��������
	cout << "son1��СΪ��" << sizeof(s1) << endl;
	son2<int,char> s2;     //��ʾָ������
	cout << "son2��СΪ��" << sizeof(s2) << endl;

}

//��ģ���Ա��������ʵ��
template<class T1, class T2>
class person10
{
public:
	T1 m1;
	T2 m2;
	//person10(T1 a, T2 b)    //����ʵ��
	//{
	//	m1 = a;
	//	m2 = b;
	//}
	//void showperson10()
	//{
	//	cout << "������" << m1 << endl;
	//	cout << "���䣺" << m2 << endl;
	//}
	person10(T1 a, T2 b);   //�������� ����ʵ��
	void showperson10();
};

template<class T1,class T2>
person10<T1,T2>::person10(T1 a, T2 b)
{
	m1 = a;
	m2 = b;
}

template<class T1, class T2>
void person10<T1, T2>::showperson10()
{
	cout << "������" << m1 << endl;
	cout << "���䣺" << m2 << endl;
}


void test80()
{
	person10<string, int> p1("С��",18);
	p1.showperson10();

}

//��ģ����ļ���д
//��ʽһ   .h �� .cpp
template<class T1, class T2>
person11<T1, T2>::person11(T1 a, T2 b)
{
	m1 = a;
	m2 = b;
}

template<class T1, class T2>
void person11<T1, T2>::showperson11()
{
	cout << "������" << m1 << endl;
	cout << "���䣺" << m2 << endl;
}

void test81()
{
	person11<string, int> p2("С��", 28);
	p2.showperson11();

}

//��ʽ��    .hpp ֱ�ӽ�������ʵ��д��һ���ļ���
void test82()
{
	person12<string, int> p3("С��", 38);
	p3.showperson12();
}

//��ģ�����Ԫ
template<class T1, class T2>    //person13����
class person13;

template<class T1, class T2>
void printperson13(person13<T1, T2>& p)
{
	cout << "����ʵ��" << endl;
	cout << "������" << p.name << endl;
	cout << "���䣺" << p.age << endl;
}

template<class T1,class T2>
class person13
{
	//ȫ�ֺ�������ʵ��
	//friend void printperson13(person13<T1, T2>& p)    //����friend �ſ��Է���˽������ ���ӻᱨ��  
	//{
	// 	cout << "����ʵ��" << endl;
	//	cout << "������" << p.name << endl;
	//	cout << "���䣺" << p.age << endl;
	//}

	//ȫ�ֺ�������ʵ��
	friend void printperson13<>(person13<T1, T2>& p);   //�������� ����ʵ��   ��Ҫ����<>����˵����һ��ģ�庯��

public:
	person13(T1 a, T2 b)  //���캯����ʼ��
	{
		name = a;
		age = b;
	}
private:
	T1 name;
	T2 age;
};

void test83()
{
	person13<string, int> p("С��", 48);
	printperson13(p);
}

//int main()
//{
//	//test20();
//	//test21();
//	//test22();
//	//test23();
//	//test24();
//	//test25();
//	//test26();
//	//test27();
//   //ѧϰ���������ַ�����ѧϰ��ģ��ͼ̳У����Դ�79��ʼ
//	//test79();
//	//test80();
//	//test81();
//	//test82();
//	test83();
//
//	system("pause");
//	return 0;
//}
