# include<iostream>
# include<vector>
# include<deque>
# include<algorithm>
# include<ctime>
# include <list>
# include<map>
# include"myarray.hpp"
using namespace std;

# define ���²��� 0    //�궨��
# define �������� 1
# define ������ 2

//vector���5���� deque��Ŵ��10������
class person6
{
public:
	string name;
	int score;
	person6(string n, int s)  //���캯������ֵ
	{
		name = n;
		score = s;
	}

};

void vectorprint(vector<person6>& v)
{
	for (vector<person6>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������"<< (*it).name << " " <<"������" << (*it).score << endl;
	}
	cout << "**********************************" << endl;
}

void creatperson6(vector<person6>& v)
{
	string nseed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string n = "ѡ��";
		n += nseed[i];
		int s = 0;
		person6 p(n,s);
		v.push_back(p);   //������p����������
	}
}

void setscore(vector<person6>& v)
{
	srand((unsigned int)time(NULL));  //���������
	for (vector<person6>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 40 + 61;    //60~100
			d.push_back(score);
		}
		cout << (*it).name << "��֣�" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;

		sort(d.begin(), d.end());   //��������
		d.pop_front();   //ͷɾ��
		d.pop_back();    //βɾ��

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

//list��������
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
		cout << "������" << (*it).name << " " << "���䣺" << (*it).age << " " << "��ߣ�" << (*it).height << endl;
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
	person8 p1("С��", 18, 175);    //��������������ͬ��߽���
	person8 p2("С��", 38, 180);
	person8 p3("С��", 38, 165);
	person8 p4("С��", 28, 185);

	l.push_back(p1);   //���������list����
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	cout << "ԭ�������" << endl;
	listprint(l);

	cout << "��������,��ͬ����߽���" << endl;
	l.sort(compare);   //ָ������  �涨������� ���������ź�����  
	listprint(l);

}

//�����ۺϰ���
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
		w.name = "Ա��";
		w.name += namespeed[i];

		w.salary =rand() % 10000 + 10000;
		v.push_back(w);   //����������vector

	}
}

void workerprint(vector<worker>& v)
{
	for (vector<worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << (*it).name <<"  " << "���ʣ�" << (*it).salary << endl;
	}
	cout << endl;
}

void setgroup(vector<worker>& v, multimap<int, worker>& m)
{
	for (vector<worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int id = rand() % 3;  //���ű��

		m.insert(pair<int, worker>(id, (*it)));

	}
}

void showworker(multimap<int, worker>& m)
{
	multimap<int, worker>::iterator pos = m.find(���²���);
	int nu = m.count(���²���);
	int n = 0;
	cout << "���²���" << endl;
	for (; pos != m.end(),n<nu; pos++,n++)
	{
		cout << "������" << (*pos).second.name << " " << "н�ʣ�" << (*pos).second.salary << endl;
	}

	cout << "--------------------------------" << endl;
	pos = m.find(��������);  //���ö��������
	nu = m.count(��������);
	n = 0;
	cout << "��������" << endl;
	for (; pos != m.end(), n < nu; pos++, n++)
	{
		cout << "������" << (*pos).second.name << " " << "н�ʣ�" << (*pos).second.salary << endl;
	}

	cout << "--------------------------------" << endl;
	pos = m.find(������);
	nu = m.count(������);
	n = 0;
	cout << "������" << endl;
	for (; pos != m.end(), n < nu; pos++, n++)
	{
		cout << "������" << (*pos).second.name << " " << "н�ʣ�" << (*pos).second.salary << endl;
	}
	cout << endl;

}

void test78()
{
	srand((unsigned int)time(NULL));  //���������
	vector<worker> v;
	createrworker(v);
	workerprint(v);
	multimap<int, worker> m;
	setgroup(v,m);
	showworker(m);

} 

//��ģ�尸��  myarray.hpp
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
		cout << "������"<< m[i].name <<" ���䣺"<<m[i].age<<endl;
	}
}

void test84()
{
	//������������
	myarray<int, int, int> m1(5);
	for (int i = 0; i < 5; i++)
	{
		m1.pushback(i);   //β��
	}
	cout << "m1���" << endl;
	printmyarray(m1);
	cout << "������" << m1.getcapacity() << endl;
	cout << "��С��" << m1.getsize() << endl;

	myarray<int, int, int> m2(m1);  //��������
	cout << "m2���" << endl;
	printmyarray(m2);
	m2.popback();   //βɾ
	cout << "������" << m2.getcapacity() << endl;    //�������� ��С����
	cout << "��С��" << m2.getsize() << endl;

	myarray<int, int, int> m3(100);
	m3 = m1;

	//�Զ�����������
	myarray<person13, int, int> m4(10);
	person13 p1("С��", 18);
	person13 p2("С��", 28);
	person13 p3("С��", 38);
	person13 p4("С��", 48);
	m4.pushback(p1);
	m4.pushback(p2);
	m4.pushback(p3);
	m4.pushback(p4);
	printperson13(m4);
	cout << "������" << m4.getcapacity() << endl;    
	cout << "��С��" << m4.getsize() << endl;

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