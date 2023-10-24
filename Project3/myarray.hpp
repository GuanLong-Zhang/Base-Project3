#pragma once
# include<iostream>
using namespace std;

template<class T1,class T2,class T3>
class myarray
{
private:
	T1* address;    //指向堆区的指针
	T2 capacity;    //容量
	T3 size;        //大小
public:
	myarray(T2 a)    //指定容量  初始化大小 堆区开辟容量
	{
		//cout << "有参构造调用" << endl;
		capacity = a;
		size = 0;
		address = new T1[capacity];   //开辟数组
	}

	~myarray()   //析构释放
	{
		if (address != NULL)
		{
			//cout << "析构调用" << endl;
			delete[] address;   //删除
			address = NULL;     //置空 防止野指针
 		}
	}

	myarray(const myarray& arr)   //对于指针需要进行深拷贝  防止堆区数据被重复释放
	{
		//cout << "拷贝构造调用" << endl;
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
		//cout << "等号重载调用" << endl;
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
		return *this;    //*this表示返回自身

	}

	void pushback(const T1& val)
	{
		//判断容量和大小的关系
		if (capacity == size)
		{
			return;
		}
		else
		{
			address[size] = val;   //尾插
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
			size--;    //尾删
		}
	}

	//通过下标进行访问
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