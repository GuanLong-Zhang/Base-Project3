#pragma once
# include<iostream>
using namespace std;

//��������ʵ��д��һ���ļ��У����ҽ�������Ϊ.hpp

template<class T1, class T2>
class person12
{
public:
	T1 m1;
	T2 m2;
	person12(T1 a, T2 b);   //�������� 
	void showperson12();
};

template<class T1, class T2>
person12<T1, T2>::person12(T1 a, T2 b)   //����ʵ��
{
	m1 = a;
	m2 = b;
}

template<class T1, class T2>
void person12<T1, T2>::showperson12()
{
	cout << "������" << m1 << endl;
	cout << "���䣺" << m2 << endl;
}