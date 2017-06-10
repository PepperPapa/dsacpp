// Copyright 2017 zhongxin
// license: BSD
// author: zhongxin
#include <iostream>

using namespace std;
#pragma once
#define DEFAULT_CAPACITY 3  // 默认初始容量
typedef int Rank;

// Vector类声明
template <class T>
class Vector {
public:
	Vector(int capacity = DEFAULT_CAPACITY, int size = 0, T v = 0);
	~Vector ();
	Rank size(); // 报告向量当前的规模（元素总数）
	Rank insert(Rank r, T e); // e作为秩为r元素插入，原后继依次后移
	T get(Rank r); // 获取秩为r的元素

private:
	Rank _size; // 长度
	int _capacity; // 存储空间的规模
	T* _elem; // 向量数据区
	void expand(); // 空间不足时以2倍现有空间进行扩容
};

// TIP: 以下类成员函数实现代码和声明必须在同一个头文件内编译才能通过，否则会报错

// Vector类实现
// 初始容量为DEFAULT_CAPACITY，长度为size，向量值全为0
template <class T>
Vector<T>::Vector(int capacity = DEFAULT_CAPACITY, int size = 0, T val = 0){
	_capacity = capacity;
	_elem = new T[_capacity = capacity];
	for (_size = 0; _size < size; _size++) {
		_elem[_size] = val;
	}
}

template <class T>
Vector<T>::~Vector() {
	delete [] _elem;
}

template <class T>
Rank Vector<T>::size() {
	return _size;
}

template <class T>
Rank Vector<T>::insert(Rank r, T e) {
	if ((r >= 0) && (r <= _size)) {
		expand(); // 根据情况确定是否扩容
		_size += 1; // 向量长度增加1
		// 依次将r～_size-1范围内的元素右移一个单位
		int i;
		for (i = _size - 1; i > r; i--) {
			_elem[i] = _elem[i - 1];
		}
		_elem[i] = e;
		return r;
	}
	return -1;
}

template <class T>
T Vector<T>::get(Rank r) {
	if ((r >= 0) && (r < _size)) {
		return _elem[r];
	}
	return -1;
}

template <class T>
void Vector<T>::expand() {
	if (_size >= _capacity) {
		T* old_elem = _elem;
		_capacity *= 2; // 按两倍容量进行扩容
		_elem = new T[_capacity];
		// 复制原有数据到新数据区
		for (int i = 0; i < _size; i++) {
			_elem[i] = old_elem[i];
		}

		delete [] old_elem;
	}
}
