#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<ctime>
using namespace std;

//STL�����㷨1
//�����㷨

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
	for_each(v.begin(), v.end(), print_vector_106);    //�����㷨��������ͨ����
	cout << endl;
	sort(v.begin(), v.end());   //������ν�ʣ�Ĭ������
	for_each(v.begin(), v.end(), print_vector_106);    //�����㷨��������ͨ����
	cout << endl;
	sort(v.begin(), v.end(), compare_106());  //����ν�ʣ����н�������
	for_each(v.begin(), v.end(), print_vector_106);    //�����㷨��������ͨ����
	cout << endl;
	sort(v.begin(), v.end(), greater<int>());  //�����ڽ��������󣬽��н�������
	for_each(v.begin(), v.end(), print_vector_106);    //�����㷨��������ͨ����
	cout << endl;

}

//random_shuffle   �����������
void test107()
{
	srand((unsigned int)time(NULL));    //�������
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print_vector_106);
	cout << endl;
	random_shuffle(v.begin(), v.end());   //�������˳��
	for_each(v.begin(), v.end(), print_vector_106);
	cout << endl;

}

//merge   �ϲ�����������������洢������һ������   ���������������򣬺ϲ���õ�������Ҳ�������
void test108()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>target;   //Ŀ������
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	target.resize(v1.size() + v2.size());    //��Ŀ����������ռ�
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
	for_each(target.begin(), target.end(), print_vector_106);
	cout << endl;

}

//reverse   ��ת
void test109()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(70);
	v.push_back(60);
	cout << "ԭʼ���ݣ�" << endl;
	for_each(v.begin(), v.end(), print_vector_106);
	cout << endl;
	cout << "��ת���ݣ�" << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), print_vector_106);
	cout << endl;
}

//���õĿ������滻�㷨
//copy 
void test110()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "v1��Ԫ��Ϊ��" << endl;
	for_each(v1.begin(), v1.end(), print_vector_106);
	cout << endl;
	vector<int>v2;
	v2.resize(v1.size());
	cout << "v2��Ԫ��Ϊ��" << endl;
	for_each(v2.begin(), v2.end(), print_vector_106);
	cout << endl;
	copy(v1.begin(), v1.end(), v2.begin());
	cout << "���ƺ��v2��Ԫ��Ϊ��" << endl;
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

//replace ��������ָ����Χ�ڵľ�Ԫ���滻����Ԫ��
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
	cout << "�滻ǰ��" << endl;
	for_each(v.begin(), v.end(), print_vector_111());    //����º���
	cout << endl;
	replace(v.begin(), v.end(), 20, 2000);     //��ԭ�����е�20�滻Ϊ2000
	cout << "�滻��" << endl;
	for_each(v.begin(), v.end(), print_vector_111());    //����º���
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