# include<iostream>
# include<map>
using namespace std;

//pair����Ĵ���
void test71()
{
	//��һ�ַ�ʽ
	pair<string, int> p("С��", 18);
	cout << "������" << p.first << endl;
	cout << "���䣺" << p.second << endl;

	//�ڶ��ַ�ʽ
	pair<string, int> p1 = make_pair("С��", 28);
	cout << "������" << p1.first << endl;
	cout << "���䣺" << p1.second << endl;
}

void mapprint(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = "<< (*it).first << " " << "value = "<< (*it).second << " " << endl;
	}
	cout << endl;
}

//map���� ����͸�ֵ
void test73()
{
	map<int, int> m;     //Ĭ�Ϲ���
	m.insert(pair<int, int>(1, 10)); //��ֵ ʵֵ   ���ռ������Զ����� Ĭ������
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(2, 20));
	mapprint(m);

	map<int, int> m1(m);    //��������
	mapprint(m1);

	map<int, int> m2 = m;  //��ֵ
	mapprint(m2);
}

//map��С�ͽ���
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
		cout << "����Ϊ��" << endl;
	}
	else
	{
		cout << "��СΪ��" << m.size() << endl;
	}
	cout << endl;

	map<int, int> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(2, 20));

	cout << "����ǰ" << endl;
	mapprint(m);
	mapprint(m1);

	m.swap(m1);
	cout << "������" << endl;
	mapprint(m);
	mapprint(m1);

}

//map�����ɾ��
void test75()
{
	map<int, int> m;
	//���뷽ʽһ
	m.insert(pair<int, int>(1, 10));

	//���뷽ʽ��
	m.insert(make_pair(4, 40));

	//���뷽ʽ��
	m.insert(map<int, int>::value_type(3,30));

	//���뷽ʽ��
	m[2] = 20;

	mapprint(m);

	m.erase(m.begin());    //ɾ����һ��Ԫ��
	mapprint(m);
	
	m.erase(3);           //ɾ����Ϊ3��Ԫ��
	mapprint(m);

	//m.erase(m.begin(), m.end());   //ɾ������
	m.clear();        //���
	mapprint(m);
}

//map���Һ�ͳ��
void test76()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));

	map<int,int>::iterator pos=m.find(3);    //��������
	if (pos != m.end())
	{
		cout << "Ԫ�ز��ҵ���" << endl;
		cout << "key = "<<(*pos).first << " " << "value = "<<(*pos).second << endl;
	}
	else
	{
		cout << "Ԫ��δ�ҵ�" << endl;
	}

	int num = m.count(3);  //��Ϊ3�ĸ���   map����������������ͬ��Ԫ��  ���Խ��Ҫ��Ϊ0Ҫ��Ϊ1  multimap���Բ������ͬ��Ԫ��
	cout << "����Ϊ��" << num << endl;
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

//mapָ���������
void test77()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));	
	m.insert(pair<int, int>(3, 30));
	mapprint(m);   //Ĭ�ϰ��ռ�ֵ������������

	map<int, int, mapcompare> m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(4, 40));
	m1.insert(pair<int, int>(3, 30));
	mapprint1(m1);   //ָ����������
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