#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//STL�����㷨
//�����㷨

//��ͨ����
void print_vector(int val)   
{
	cout << val << " ";
}

//�º���
class MyPrint
{
public:
	void operator()(int a)
	{
		cout << a << " ";
	}
};

//for_each()   ��������
void test94()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(),print_vector);   //������ͨ����
	cout << endl;
	for_each(v.begin(), v.end(), MyPrint());     //����º���
	cout << endl;
}

//�º���
class Transform
{
public:
	int operator()(int v)    
	{
		return v + 100;
	}
};

//transform()   ��һ�����������ݰ��˵�����һ������
void test95()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>v1;
	v1.resize(v.size());   //��Ŀ���������ٿռ�
	transform(v.begin(), v.end(), v1.begin(), Transform());    //����º���
	for_each(v1.begin(), v1.end(), MyPrint());                 //����º���
	cout << endl;
}

//�����㷨

//find
void test96()    
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find(v.begin(), v.end(), 50);      //find������������
	if (it == v.end())
	{
		cout << "û�в��ҵ�ָ��Ԫ��" << endl;
	}
	else
	{
		cout << "���ҵ���ָ��Ԫ��" << endl;
		cout << "���ҵ���Ԫ��Ϊ��" << *it << endl;
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
	bool operator==(const Person_97 &p)     //��Ҫ��==��������,��������֪����ζ��Զ����������ͱȽ�
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

	Person_97 pp("bbb", 20);   //����Ԫ��
	vector<Person_97>::iterator it =  find(v.begin(), v.end(), pp);    //find�Զ�������  
	if (it == v.end())
	{
		cout << "û�в��ҵ�ָ������" << endl;
	}
	else
	{
		cout << "���ҵ���ָ������" << endl;
		cout << "���ҵ�������Ϊ��" << (*it).MyName<<" "<<(*it).Age << endl;
	}

}

//find_if
class Greater
{
public:
	bool operator()(int a)    //һԪν��
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
	//find_if������������   ����һԪν��   ���ص�һ�������Ԫ��
	vector<int>::iterator it = find_if(v.begin(), v.end(), Greater());  
	if (it == v.end())
	{
		cout << "û�в��ҵ�ָ��Ԫ��" << endl;
	}
	else
	{
		cout << "���ҵ���ָ��Ԫ��" << endl;
		cout << "���ҵ���Ԫ��Ϊ��" << *it << endl;
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
	//find_if������������   ����һԪν��   ���ص�һ�������Ԫ��  
	vector<Person_97>::iterator it = find_if(v.begin(), v.end(), Greater20());     
	if (it == v.end())
	{
		cout << "û�в��ҵ�ָ��Ԫ��" << endl;
	}
	else
	{
		cout << "���ҵ���ָ��Ԫ��" << endl;
		cout << "���ҵ���Ԫ��Ϊ��" << (*it).MyName << " " << (*it).Age << endl;
	}
}

//adjacent_find()   ���������ظ�Ԫ��
void test100()
{
	vector<int>v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(3);
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());   //���������ظ�Ԫ�صĵ�һ��λ�õ�����
	if (it == v.end())
	{
		cout << "û�в��ҵ������ظ�Ԫ��" << endl;
	}
	else
	{
		cout << "���ҵ��������ظ�Ԫ��" << endl;
		cout << "�����ظ�Ԫ��Ϊ��" << *it << endl;
	}

}

//binary_search()   ���ֲ��ң����ڲ�����������  ���ҵ�����true���鲻������false
void test101()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	int a = 1;  //�����ҵ�Ԫ��
	bool bo = binary_search(v.begin(), v.end(), a);
	if (bo == true)
	{
		cout << "���ҵ���Ԫ�أ�"<< a  << endl;
	}
	else
	{
		cout << "û�в��ҵ�Ԫ�أ�" << a << endl;
	}
}

//count()   ͳ��Ԫ�ظ���������Ԫ�ظ���
void test102()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(10);
	v.push_back(20);
	int a = 40;    //��ͳ�Ƶ�Ԫ��     ͳ��������������
	int num = count(v.begin(), v.end(), a);
	cout << "��ͳ�Ƶ�Ԫ��" << a << "�ĸ���Ϊ��" << num << endl;
}

void test103()
{
	vector<Person_97>v;
	Person_97 p1("aaa", 10);
	Person_97 p2("bbb", 20);
	Person_97 p3("ccc", 30);
	Person_97 p4("ddd", 40);
	Person_97 p5("bbb", 20);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	Person_97 pp("bbb", 20);   //��ͳ��Ԫ��
	int num = count(v.begin(), v.end(), pp);    //ͳ���Զ�������    ��Ҫ�����н���==�����أ������༭����֪����αȽ�
	cout << "����Ϊ��" << pp.MyName << " " << "����Ϊ��" << pp.Age << " " << "��Ԫ�ظ���Ϊ��" << num << endl;
	
}

class Greater_20
{
public:
	bool operator()(int val)   //һԪν��
	{
		return val > 20;
	}
};

//count_if  ������������ͳ��Ԫ�ظ���  ����ν��
void test104()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);
	int num = count_if(v.begin(), v.end(), Greater_20());   //ͳ��������������
	cout << "����20��Ԫ�ظ���Ϊ��" << num << endl;
}

class Person_105
{
public:
	bool operator()(Person_97& p)   //һԪν��
	{
		if (p.MyName == "bbb" && p.Age == 20)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void test105()
{
	vector<Person_97>v;
	Person_97 p1("aaa", 10);
	Person_97 p2("bbb", 20);
	Person_97 p3("ccc", 30);
	Person_97 p4("ddd", 40);
	Person_97 p5("bbb", 20);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	int num = count_if(v.begin(), v.end(), Person_105());   //ͳ���Զ�����������
	cout << "����Ϊ��" << "bbb" << " " << "����Ϊ��" << 20 << " " << "��Ԫ�ظ���Ϊ��" << num << endl;

}

//int main()
//{
//	//test94();
//	//test95();
//	//test96();
//	//test97();
//	//test98();
//	//test99();
//	//test100();
//	//test101();
//	//test102();
//	//test103();
//	//test104();
//	test105();
//
//	system("pause");
//	return 0;
//}