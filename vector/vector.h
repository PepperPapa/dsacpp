// Copyright 2017 zhongxin
// license: BSD
// author: zhongxin
#include <iostream>

using namespace std;
#pragma once
#define DEFAULT_CAPACITY 3  // 默认初始容量
typedef int Rank;

template <class T> class Vector {
public:
	Vector(int capacity = DEFAULT_CAPACITY, int size = 0, T v = 0);
	~Vector ();
	Rank size(); // 返回向量的长度

private:
	Rank _size; // 长度
	int _capacity; // 规模
	T* _elem; // 向量数据区	
};

// TIP: 以下类成员函数实现代码和声明必须在同一个头文件内编译才能通过，否则会报错

// 初始容量为DEFAULT_CAPACITY，长度为size，向量值全为0
template <class T> Vector<T>::Vector(int capacity=DEFAULT_CAPACITY, int size=0, T val=0){
	_capacity = capacity;
	_elem = new T[_capacity = capacity];
	for (_size = 0; _size < size; _size++) {
		_elem[_size] = val;
	}
}

template <class T> Vector<T>::~Vector() {
	delete[] _elem;
}

template <class T> Rank Vector<T>::size() {
	return _size;
}
