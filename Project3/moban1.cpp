# include<iostream>
using namespace std;

//模板案例 
//对不同类型的数组进行排序
//从大到小 选择排序

//值交换模板
template<typename T>
void myswap1(T& a, T& b)  //引用传递
{
	T temp = a;
	a = b;
	b = temp;
}

//选择排序模板    时间复杂度n^2
template<typename T>
void sort(T arry[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;   //假设最大下标为i
		for (int j = i + 1; j < len; j++)
		{
			if (arry[max] < arry[j])
			{
				max = j;   //交换下标
			}
		}
		if (max != i)   //最大值下标与原假设不一致时，需要进行值交换
		{
			myswap1(arry[max], arry[i]);
		}

	}
}

//打印模板
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