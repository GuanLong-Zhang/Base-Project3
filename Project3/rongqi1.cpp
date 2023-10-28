# include<iostream>
# include<deque>
# include<algorithm>
# include<stack>
# include<queue>
# include<list>
# include<set>
using namespace std;

//����deque ������vector����
void dequeprint(const deque<int>& d)     //�޶�ֻ��
{
	for (deque<int>::const_iterator it=d.begin(); it!=d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//deque�������캯��
void test50()
{
	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);    //β�巨
	}
	dequeprint(d);
	deque<int> d1(d.begin(), d.end());    //���丳ֵ
	dequeprint(d1);
	deque<int> d2(10, 100);    //10��100
	dequeprint(d2);
	deque<int> d3(d2);         //d3����d2
	dequeprint(d3);
}

//deque�����ĸ�ֵ����
void test51()
{
	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);    //β�巨
	}
	dequeprint(d);
	deque<int> d1 = d;     //=��ֵ
	dequeprint(d1);
	deque<int> d2;
	d2.assign(d1.begin(), d1.end());   //assign��ֵ
	dequeprint(d2);
	deque<int> d3;
	d3.assign(10, 100);  //10��100
	dequeprint(d3);
}

//deque�����Ĵ�С����
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
		cout << "����Ϊ��" << endl;
	}
	else
	{
		cout << "�����Ĵ�СΪ��" << d.size() << endl;

	}
	d.resize(15);    //���� Ĭ����0�������
	dequeprint(d);    
	d.resize(20,1);    //���� ָ����1���
	dequeprint(d); 
	d.resize(10);      //���� �Զ�ɾ��
	dequeprint(d);

}

//deque���������ɾ��
void test53()
{
	deque<int> d;
	d.push_back(10);    //β�巨
	d.push_back(20);
	d.push_front(30);   //ͷ�巨
	d.push_front(40);
	dequeprint(d);      //40 30 10 20
	d.pop_back();       //βɾ��
	dequeprint(d);      //40 30 10
	d.pop_front();      //ͷɾ��
	dequeprint(d);      //30 10

	d.insert(d.begin(), 1000);       //ͷ������1000
	dequeprint(d);
	d.insert(d.begin(), 2, 10000);       //ͷ������2��10000
	dequeprint(d);
	deque<int> d1;
	for (int i = 0; i < 3; i++)
	{
		d1.push_back(i);
	}
	d.insert(d.begin(), d1.begin(), d1.end());
	dequeprint(d);

	deque<int>::iterator it = d.begin();   //��ʼ������
	it++;    //ƫ��
	d.erase(it);   //ɾ���ڶ���Ԫ��
	dequeprint(d);
	d.erase(d.begin(), d.end());   //ɾ������Ԫ�� �ȼ���clear
	dequeprint(d);
	d.clear();
	dequeprint(d);
}

//deque���������ݴ�ȡ
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
		cout << d[i] << " ";     //[]��ȡ����
	}
	cout << endl;
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << " ";     //.at()��ȡ����
	}
	cout << endl;
	cout << "��һ��Ԫ�أ�" << d.front() << endl;
	cout << "���һ��Ԫ�أ�" << d.back() << endl;
}

//deque�����������
void test55()
{
	deque<int> d;
	d.push_back(10);    //β�巨
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);   //ͷ�巨
	d.push_front(200);
	d.push_front(300);

	dequeprint(d);
	sort(d.begin(), d.end());   //����   ��������
	cout << "�����Ľ��" << endl;
	dequeprint(d);

}

//stack����
void test57()
{
	stack<int> s;   //ջ �Ƚ����
	s.push(10);     //��ջ  ջ��
	s.push(20);
	s.push(30); 
	s.push(40);
	cout << "ջ�Ĵ�С��" << s.size() << endl;
	while (!s.empty())   //�п�
	{
		cout << "ջ��Ԫ�أ�" << s.top() << endl;
		s.pop();    //��ջ   ջ��
	}
	cout << "ջ�Ĵ�С��" << s.size() << endl;

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

//queue����
void test58()
{
	queue<person7> q;
	person7 p0("С��", 18);
	person7 p1("С��", 28);
	person7 p2("С��", 38);
	person7 p3("С��", 48);
	q.push(p0);   //��� ��β
	q.push(p1);
	q.push(p2);
	q.push(p3);
	cout << "��СΪ��" << q.size() << endl;
	while (!q.empty())   //�п�
	{
		cout << "��ͷԪ��" << q.front().name<<" "<<q.front().age<<endl;
		cout << "��βԪ��" << q.back().name << " " << q.back().age << endl;
		q.pop();     //���� ��ͷ
	
	}
	cout << "��СΪ��" << q.size() << endl;
}

void listprint(list<int>& l)
{
	for (list<int>::iterator lit = l.begin(); lit != l.end(); lit++)
	{
		cout << *lit << " ";
	}
	cout << endl;
}

//list�������캯��
void test59()
{
	list<int> l;
	l.push_back(10);   //β�巨
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	listprint(l);

	list<int> l1(l.begin(), l.end());   //���乹��
	listprint(l1);

	list<int> l2(l1);    //��������
	listprint(l2);

	list<int> l3(4, 1000);   //4��1000
	listprint(l3);
}

//list������ֵ�ͽ���
void test60()
{
	list<int> l;
	l.push_back(10);   //β�巨
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	listprint(l);

	list<int> l1;
	l1 = l;    // =��ֵ
	listprint(l1);

	cout << "����ǰ" << endl;
	list<int> l2;
	l2.assign(l1.begin(), l1.end());     // assign ��ֵ
	listprint(l2);

	list<int> l3;
	l3.assign(4, 1000);   //4��1000
	listprint(l3);

	l2.swap(l3);
	cout << "������" << endl;
	listprint(l2);
	listprint(l3);

}

//list������С����
void test61()
{
	list<int> l;
	l.push_back(10);   //β�巨
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	listprint(l);

	if (l.empty())
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		cout << "��СΪ��" << l.size() << endl;
	}
	l.resize(10);    //���� Ĭ����0�������
	cout << "��СΪ��" << l.size() << endl;
	listprint(l);

	l.resize(15, 1);  //���� ָ����1�������
	cout << "��СΪ��" << l.size() << endl;
	listprint(l);
	 
	l.resize(4);      //���� �Զ�ɾ��
	cout << "��СΪ��" << l.size() << endl;
	listprint(l);
}

//list���������ɾ��
void test62()
{
	list<int> l;
	l.push_back(10);   //β��
	l.push_back(20);
	l.push_back(30);
	l.push_front(100);  //ͷ��
	l.push_front(200);
	l.push_front(300);
	listprint(l);   // 300 200 100 10  20  30
	l.pop_back();    //βɾ
	listprint(l);
	l.pop_front();   //ͷɾ
	listprint(l);
	l.insert(l.begin(), 1000);   //��ʼ������ ����1000  ���Ըı��������λ��
	listprint(l);
	l.erase(l.begin());   //ɾ����һ��Ԫ��
	listprint(l);
	l.push_front(10000);
	l.push_back(10000);
	listprint(l);
	l.remove(10000);      //ɾ��Ԫ��10000   ���������е�10000������ɾ��
	listprint(l);
	l.clear();       //���
	listprint(l);
}

//list�������ݴ�ȡ
void test63()
{
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_front(10);
	l.push_front(20);
	listprint(l);

	//û��[] �� .at() ����list�Ľṹ�й� ֻ�ܽ���˫����ʣ�����Ϊ˫��ѭ������
	cout << "��һ��Ԫ��" << l.front() << endl;
	cout << "���һ��Ԫ��" << l.back() << endl;
}

//����
bool compare(int a, int b)
{
	return a > b;
}

//list������ת������
void test64()
{
	list<int> l;
	l.push_back(50);
	l.push_back(20);
	l.push_back(10);
	l.push_back(40);
	listprint(l);
	l.reverse();   //��ת
	listprint(l);
	l.sort();      //����  ����    //sort(l.begin(),l.end()) ���� ֻ��������ʵ�����֧�����ַ�ʽ
	listprint(l);
	l.sort(compare);  //����  ָ��һ������compare
	listprint(l);

}

//set multiset����
void setprint(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//set��������͸�ֵ
void test66()
{
	set<int> s;
	s.insert(20);    //set�������ڲ���������Զ��������� (Ĭ������)  ���������ظ���Ԫ�� ��ʹ�����ظ���ֵҲû��Ч��
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(30);
	setprint(s);   // 10 20 30 40

	set<int> s1(s);
	setprint(s1);

	set<int> s2 = s1;   //=��ֵ
	setprint(s2);
}

//set�����Ĵ�С�ͽ���
void test67()
{
	set<int> s;
	s.insert(10);
	s.insert(40);
	s.insert(30);
	s.insert(20);
	s.insert(20);
	setprint(s);   //set�����ظ����������û��Ч��������Ҳ����������С
	if (s.empty())
	{
		cout << "��СΪ��" << endl;
	}
	else
	{
		cout << "��СΪ��" << s.size() << endl;
	}

	set<int> s1;
	s1.insert(100);
	s1.insert(400);
	s1.insert(300);
	s1.insert(200);
	cout << "����ǰ:" << endl;
	setprint(s);
	setprint(s1);
	s.swap(s1);
	cout << "������" << endl;
	setprint(s);
	setprint(s1);
}

//set���������ɾ��
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
	s.erase(30);   //ɾ��Ԫ��30
	setprint(s);
	//s.erase(s.begin(), s.end());   //ָ���������ɾ�����൱��clear
	s.clear();    //���
	setprint(s);
}

//set�����Ĳ��Һ�ͳ��
void test69()
{
	set<int> s;
	s.insert(30);
	s.insert(40);
	s.insert(10);
	s.insert(20);
	setprint(s);

	set<int>::iterator pos = s.find(40);  //find ���Ҷ�ӦԪ�أ����ҵ��ͷ��ض�ӦԪ�صĵ�������û�в��ҵ��ͷ�����ֹ������
	if (pos != s.end())
	{
		cout << "Ԫ�ز��ҵ���" << endl;
		cout << "Ԫ��Ϊ��" << *pos << endl;
	}
	else
	{
		cout << "Ԫ��δ�ҵ�" << endl;
	}

	int num = s.count(40);   //ͳ�Ƹ���
	cout << "����Ϊ��" << num << endl;
}

//multiset����
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
	multiset<int> m;    //multiset������set ��������ظ������ݣ����ҽ����Զ���������
	m.insert(30);
	m.insert(40);
	m.insert(40);
	m.insert(10);
	m.insert(20);
	multisetprint(m);
}

class compare1   //�º���
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

class compare2    //�º���
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
		cout <<"������"<< (*it).name << " " <<"���䣺"<< (*it).age << endl;
	}
	cout << endl;
}



//set����������
void test72()
{
	set<int> s;    //�Զ�������������
	s.insert(10);
	s.insert(40);
	s.insert(20);
	s.insert(30);
	setprint(s);

	set<int,compare1> s1;    //ָ��������� ����
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	setprint1(s1);

	set<person9,compare2> s2;  //�������併��
	person9 p1("С��", 28);
	person9 p2("С��", 18);
	person9 p3("С��", 38);

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