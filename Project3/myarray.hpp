#pragma once
# include<iostream>
using namespace std;

template<class T1,class T2,class T3>
class myarray
{
private:
	T1* address;    //ָ�������ָ��
	T2 capacity;    //����
	T3 size;        //��С
public:
	myarray(T2 a)    //ָ������  ��ʼ����С ������������
	{
		//cout << "�вι������" << endl;
		capacity = a;
		size = 0;
		address = new T1[capacity];   //��������
	}

	~myarray()   //�����ͷ�
	{
		if (address != NULL)
		{
			//cout << "��������" << endl;
			delete[] address;   //ɾ��
			address = NULL;     //�ÿ� ��ֹҰָ��
 		}
	}

	myarray(const myarray& arr)   //����ָ����Ҫ�������  ��ֹ�������ݱ��ظ��ͷ�
	{
		//cout << "�����������" << endl;
		capacity = arr.capacity;
		size = arr.size;

		address = new T1[arr.capacity];
		for (int i = 0; i < arr.size; i++)
		{
			address[i] = arr.address[i];
		}

	}

	myarray& operator=(const myarray& arr)
	{
		//cout << "�Ⱥ����ص���" << endl;
		if (address != NULL)
		{
			delete[] address;
			address = NULL;
			capacity = 0;
			size = 0;
		}

		capacity = arr.capacity;
		size = arr.size;

		address = new T1[arr.capacity];
		for (int i = 0; i < arr.size; i++)
		{
			address[i] = arr.address[i];
		}
		return *this;    //*this��ʾ��������

	}

	void pushback(const T1& val)
	{
		//�ж������ʹ�С�Ĺ�ϵ
		if (capacity == size)
		{
			return;
		}
		else
		{
			address[size] = val;   //β��
			size++;
		}
	}

	void popback()
	{
		if (size == 0)
		{
			return;
		}
		else
		{
			size--;    //βɾ
		}
	}

	//ͨ���±���з���
	T1& operator[](int idex)
	{
		return address[idex];
	}

	T2 getcapacity()
	{
		return capacity;
	}

	T3 getsize()
	{
		return size;
	}

};