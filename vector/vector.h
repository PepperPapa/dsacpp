// Copyright 2017 zhongxin
// license: BSD
// author: zhongxin
#include <iostream>

using namespace std;
#pragma once
#define DEFAULT_CAPACITY 3  // Ĭ�ϳ�ʼ����
typedef int Rank;

template <class T> class Vector {
public:
	Vector(int capacity = DEFAULT_CAPACITY, int size = 0, T v = 0);
	~Vector ();
	Rank size(); // ���������ĳ���

private:
	Rank _size; // ����
	int _capacity; // ��ģ
	T* _elem; // ����������	
};

// TIP: �������Ա����ʵ�ִ��������������ͬһ��ͷ�ļ��ڱ������ͨ��������ᱨ��

// ��ʼ����ΪDEFAULT_CAPACITY������Ϊsize������ֵȫΪ0
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
