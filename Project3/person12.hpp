#pragma once
# include<iostream>
using namespace std;

//将声明和实现写到一个文件中，并且将其命名为.hpp

template<class T1, class T2>
class person12
{
public:
	T1 m1;
	T2 m2;
	person12(T1 a, T2 b);   //类内声明 
	void showperson12();
};

template<class T1, class T2>
person12<T1, T2>::person12(T1 a, T2 b)   //类外实现
{
	m1 = a;
	m2 = b;
}

template<class T1, class T2>
void person12<T1, T2>::showperson12()
{
	cout << "姓名：" << m1 << endl;
	cout << "年龄：" << m2 << endl;
}