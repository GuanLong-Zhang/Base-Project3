# include<iostream>
using namespace std;

//ģ�尸�� 
//�Բ�ͬ���͵������������
//�Ӵ�С ѡ������

//ֵ����ģ��
template<typename T>
void myswap1(T& a, T& b)  //���ô���
{
	T temp = a;
	a = b;
	b = temp;
}

//ѡ������ģ��    ʱ�临�Ӷ�n^2
template<typename T>
void sort(T arry[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;   //��������±�Ϊi
		for (int j = i + 1; j < len; j++)
		{
			if (arry[max] < arry[j])
			{
				max = j;   //�����±�
			}
		}
		if (max != i)   //���ֵ�±���ԭ���費һ��ʱ����Ҫ����ֵ����
		{
			myswap1(arry[max], arry[i]);
		}

	}
}

//��ӡģ��
template<typename T>
void printarry(T arry[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arry[i] << " ";
	}
	cout << endl;
}

void test10()
{
	char chararry[] = "bcadfehg";
	int num = sizeof(chararry) / sizeof(chararry[0]);
	sort(chararry, num);
	printarry(chararry, num);
}

void test11()
{
	int intarry[] = {0,2,6,9,8,7,4,1,3};
	int num = sizeof(intarry) / sizeof(intarry[0]);
	sort(intarry, num);
	printarry(intarry, num);
}

//int main()
//{
//	test10();
//	test11();
//
//	system("pause");
//	return 0;
//}