# include<iostream>
using namespace std;

//函数模板
template <typename T>   //声明一个函数模板
//交换模板
void myswap(T& a, T& b)   //引用传递   
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
	cout << "交换前" << endl;
	cout << "a = " << a << " " << "b = " << b << endl;
	myswap(a, b);      //调用方式一   自动类型推导
	//myswap<int>(a, b);   //调用方式二   显示指定类型
	//自动类型推导的时候，必须推导出一致的数据类型才可以使用,不然会报错
	//myswap(a, c);   //报错 类型不一致
	cout << "交换后" << endl;
	cout << "a = " << a << " " << "b = " << b << endl;
}

template<typename T>
void func()
{
	cout << "func函数的调用" << endl;
}

void test02()
{
	//func()    //报错 因为没有指定T的类型
	func<int>();   //虽然调用的是无参函数，但是还是需要指定T的数据类型，不然会报错；随便指定即可
}


//int main()
//{
//	//test01();
//	//test02();
//
//	system("pause");
//	return 0;
//}