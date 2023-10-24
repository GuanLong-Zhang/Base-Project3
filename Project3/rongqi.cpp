//STL ��׼ģ���
# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

void testcout(int val)
{
	cout << val << endl;
}

//vector�������������������
void test30()
{
	vector<int> v;   //����vector

	v.push_back(10); //��������  β�巨
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//vector<int>::iterator itbegin = v.begin();   //��ʼ������  ָ��������һ��Ԫ��λ��
	//vector<int>::iterator itend = v.end();       //����������  ָ���������һ��Ԫ�ص���һ��λ��

	////�������1
	//while (itbegin != itend)
	//{
	//	cout << *itbegin << endl;    //itbegin�൱��ָ����÷�
	//	itbegin++;
	//}
	
	//�������2
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << endl;
	//}

	//�������3   algorithm�Դ��ı����㷨
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

//vector��������Զ�����������
void test31()
{
	vector<person6> v;
	person6 p1("С��", 18);
	person6 p2("С��", 28);
	person6 p3("С��", 38);
	person6 p4("С��", 48);
	person6 p5("С��", 58);
	person6 p6("С��", 68);

	v.push_back(p1);   //�������� β�巨
	v.push_back(p2); 
	v.push_back(p3); 
	v.push_back(p4); 
	v.push_back(p5);
	v.push_back(p6);

	for (vector<person6>::iterator it = v.begin(); it != v.end(); it++)    //�������   <>����������ɶ��ô*it����ɶ
	{
		cout << "������" << (*it).name << endl;
		cout << "���䣺" << (*it).age << endl;
	}

}

//vector��������Զ����������͵�ָ��
void test32()
{
	vector<person6*> v;
	person6 p1("С��", 18);
	person6 p2("С��", 28);
	person6 p3("С��", 38);
	person6 p4("С��", 48);
	person6 p5("С��", 58);
	person6 p6("С��", 68);

	v.push_back(&p1);   //�������� β�巨
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	v.push_back(&p6);

	for (vector<person6*>::iterator it = v.begin(); it != v.end(); it++)    //�������
	{
		cout << "::������" << (*it)->age << endl;
		cout << "::���䣺" << (*it)->name << endl;
	}
}

//����Ƕ������
void test33()
{
	vector<vector<int>> v;  //vectorǶ��vector

	vector<int> v1;    //vector
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	for (int i = 0; i < 4; i++)   //��ֵ
	{
		v1.push_back(i);
		v2.push_back(i+1);
		v3.push_back(i+2);
		v4.push_back(i+3);
	}

	v.push_back(v1);   //vector����vector
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it ��vector<int>  ������Ҫ��������
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}

//string����
//string�Ĺ��캯��
void test34()
{
	string s1;
	cout << "s1:" << s1 << endl;
	const char* str = "hello world";
	string s2(str);
	cout << "s2:" << s2 << endl;
	string s3(s2);
	cout << "s3:" << s3 << endl;
	string s4(10, 'H');          //10��H
	cout << "s4:" << s4 << endl;

}

//string��ֵ����
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
	s5.assign("hello c++", 5);    //hello c++��ǰ5���ַ�����s5
	cout << "s5:" << s5 << endl;

	string s6;
	s6.assign(s5);
	cout << "s6:" << s6 << endl;

	string s7;
	s7.assign(10, 'W');    //10��W
	cout << "s7:" << s7 << endl;
}

//string�ַ���ƴ��
void test36()
{
	string s1;
	s1 = "��";
	s1 += "��˭?";   //ƴ��һ���ַ���
	cout << "s1:" << s1 << endl;
	s1 += 'c';       //ƴ��һ���ַ�
	cout << "s1:" << s1 << endl;
	string s2;
	s2 = "����˭��";
	s2 += s1;  
	cout << "s2:" << s2 << endl;

	string s3;
	s3="��";
	s3.append("��");
	cout << "s3:" << s3 << endl;
	s3.append("game abcdef", 4);   //ǰ4��ƴ��
	cout << "s3:" << s3 << endl;
	s3.append(s2);
	cout << "s3:" << s3 << endl;
	string s4 = "game";
	s3.append(s4, 0, 2);   //��s4�ĵ�0��λ�ÿ�ʼ��ȡ2������ƴ��
	cout << "s3:" << s3 << endl;
}

//string���Һ��滻
void test37()
{
	string s1 = "abcdefghde";
	int p=s1.find("de");   //�����ַ������� �򷵻ض�Ӧ��λ�� �������򷵻�-1   find����Ϊ�������Ҳ�
	if (p == -1)
	{
		cout << "δ�ҵ��ַ���" << endl;
	}
	else
	{
		cout << "λ��Ϊ��" << p << endl;    //3
	}

	int q = s1.rfind("de");      //refind����Ϊ���������
	if (q == -1)
	{
		cout << "δ�ҵ��ַ���" << endl;
	}
	else
	{
		cout << "λ��Ϊ��" << q << endl;    //8
	}

	string s2 = "abcdefgh";
	s2.replace(1, 3, "1111");    //�ӵ�һ��λ�ÿ�ʼ��3���ַ��滻Ϊ1111
	cout << "s2:" << s2 << endl;
}

//string�ַ����Ƚ�
void test38()
{
	string s1 = "aello";
	string s2 = "hello";
	if (s1.compare(s2) == 0)    //���ַ��Ƚ�
	{
		cout << "s1����s2" << endl;
	}
	else if (s1.compare(s2) > 0)
	{
		cout << "s1����s2" << endl;
	}
	else
	{
		cout << "s1С��s2" << endl;
	}
}

//string�ַ���ȡ
void test39()
{
	string s1 = "hello";
	cout << "s1:" << s1 << endl;

	for (int i = 0; i < s1.size(); i++)    //�����ַ���ȡ []
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < s1.size(); i++)    // �����ַ���ȡ at
	{
		cout << s1.at(i) << " ";
	}
	cout << endl;

	s1[0] = 'a';      //�޸ĵ����ַ�[]
	cout << "s1:"<<s1 << endl;

	s1.at(0) = 'h';   //�޸ĵ����ַ�at
	cout << "s1:" << s1 << endl;
}

//string�ַ��������ɾ��
void test40()
{
	string s1 = "hello";
	s1.insert(1, "1111");   //�ڵ�һ��λ�ò���1111
	cout << "s1:" << s1 << endl;
	s1.erase(1, 4);         //�ӵ�һ��λ�ÿ�ʼɾ��4���ַ�
	cout << "s1:" << s1 << endl;
}

//string�ִ�
void test41()
{
	string s1 = "abcdefgh";
	string s2 = s1.substr(1, 3);    //�ӵ�һ��λ��ȡ�����ַ�
	cout << s2 << endl;
	string s3 = "zhangguanlong@qq.com";
	int p=s3.find('@');
	string s4 = s3.substr(0, p);
	cout << "s4:" << s4 << endl;
}

//vector����
void vectorprint(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//vector���캯��
void test42()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);   //β�巨 ��������
	}
	vectorprint(v1);

	vector<int> v2(v1.begin(), v1.end());  //��v1�ӿ�ͷ����β�����ݸ���v2
	vectorprint(v2);

	vector<int> v3(10, 100);   //��10��100����v3
	vectorprint(v3);

	vector<int> v4(v3);   //��v3���帳��v4
	vectorprint(v4);
}

//vector��ֵ����
void test43()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vectorprint(v1);

	vector<int> v2;     //=��ֵ
	v2 = v1;
	vectorprint(v2);

	vector<int> v3;     //assign��ֵ
	v3.assign(v1.begin(), v1.end());  
	vectorprint(v3);

	vector<int> v4;    //10��100
	v4.assign(10, 100);
	vectorprint(v4);
}

//vector�����ʹ�С
void test44()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vectorprint(v1);

	if (v1.empty())   //����Ϊ��
	{
		cout << "����Ϊ��" << endl;
	}
	else
	{
		cout << "������Ϊ��" << endl;
		cout << "��������Ϊ��" << v1.capacity() << endl;    //13
		cout << "������СΪ��" << v1.size() << endl;      //10 ����>��С
	}

	v1.resize(15);   //������С  ָ������Ĭ����0������䣬��ȻҲ���Խ���ָ�� 
	vectorprint(v1);

	v1.resize(20,100);  //ָ�����˶����λ����100�������
	vectorprint(v1);

	v1.resize(10);      //ָ������ �����Զ�ɾ��
	vectorprint(v1);
}

//vector�����ɾ��
void test45()
{
	vector<int> v1;
	v1.push_back(1);   //β�巨 ��������1
	v1.push_back(2);
	v1.push_back(3);
	vectorprint(v1);

	v1.pop_back();   //βɾ��  ɾ��һ��Ԫ��
	vectorprint(v1);

	v1.insert(v1.begin(), 100);   //ͷ������100
	vectorprint(v1);

	v1.insert(v1.begin(), 2, 1000);   //ͷ������2��1000
	vectorprint(v1);

	v1.erase(v1.begin());   //ɾ��ͷ��һ��Ԫ��
	vectorprint(v1);

	//v1.erase(v1.begin(), v1.end());  //��ͷ��βɾ��v1  �ȼ���clear
	v1.clear();    //���
	vectorprint(v1);
}

//vector���ݴ�ȡ
void test46()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);   //β�巨
	}

	for (int i = 0; i < v1.size(); i++)   //����Ԫ�ض�ȡ[]
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < v1.size(); i++)   //����Ԫ�ض�ȡ.at()
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	cout << "��һ��Ԫ�أ�" << v1.front() << endl;
	cout << "���һ��Ԫ�أ�" << v1.back() << endl;

}

//vector��������
void test47()
{
	vector<int> v1;
	cout << "����ǰ" << endl;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);    //β�巨
	}
	vectorprint(v1);

	vector<int> v2;
	for (int i = 9; i >= 0; i--)
	{
		v2.push_back(i);
	}
	vectorprint(v2);

	cout << "������" << endl;
	v1.swap(v2);    //�������� v1 v2
	vectorprint(v1);
	vectorprint(v2);
}

//��������ʵ����;
void test48()
{
	vector<int> v1;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);
	}
	cout << "����Ϊ��" << v1.capacity() << endl;    //138255
	cout << "��СΪ��" << v1.size() << endl;        //100000

	v1.resize(3);   //������0������� С��ֱ���Զ�ɾ��Ԫ��
	cout << "����Ϊ��" << v1.capacity() << endl;     //138255
	cout << "��СΪ��" << v1.size() << endl;         //3

	vector<int>(v1).swap(v1);   //����swap�����ڴ�   ��������(v1) ��v1 �����˽�������������������ͱ�ϵͳ�Զ��ͷ���
	cout << "����Ϊ��" << v1.capacity() << endl;     //3
	cout << "��СΪ��" << v1.size() << endl;         //3
}

void test49()
{
	vector<int> v;
	v.reserve(100000);   //����reserve Ԥ���ռ�
	int num = 0;  //���ٴ���
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);   //β�巨
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