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
	void show(); // only for test
	Rank size(); // 报告向量当前的规模（元素总数）
	Rank insert(Rank r, T e); // e作为秩为r元素插入，原后继依次后移
	T get(Rank r); // 获取秩为r的元素
	Rank put(Rank r, T e); // 用e替换秩为r元素的数值
	T remove(Rank r); // 删除秩为r的元素，返回该元素原值
	int disordered(); // 判断所有元素是否已按非降序排列, 返回逆序相邻元素对的总数
	void bubbleSort(Rank lo, Rank hi); // 调整各元素的位置，使之按非降序排列(冒泡排序)
	void mergeSort(Rank lo, Rank hi); // 调整各元素的位置，使之按非降序排列(归并排序)

private:
	Rank _size; // 长度
	int _capacity; // 存储空间的规模
	T* _elem; // 向量数据区
	void expand(); // 空间不足时以2倍现有空间进行扩容
	void swap(Rank r1, Rank r2); // 交换秩为r1、r2的数据
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

// show method: only for test
template <class T>
void Vector<T>::show() {
	if (_size > 0) {
		cout << "[";
		for (int i = 0; i < _size; i++) {
			cout << _elem[i] << ",";
		}
		cout << "]" << endl;
	}
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

template <class T>
Rank Vector<T>::put(Rank r, T e) {
	if ((r >= 0) && (r < _size)) {
		_elem[r] = e;
		return r;
	}
	return -1;
}

template <class T>
T Vector<T>::remove(Rank r) {
	if ((r >= 0) && (r < _size)) {
		for (int i = r; i < (_size - 1); i++) {
			_elem[i] = _elem[i + 1];
		}
		_size -= 1;
	}
	return -1;
}

template <class T>
int Vector<T>::disordered() {
	int n = 0; // 记录逆序相邻元素对的个数
	for (int i = 0; i < (_size - 1); i++) {
	  if (_elem[i] > _elem[i + 1]) {
	  	n += 1;
	  }
	}
	return n;
}

template <class T>
void Vector<T>::swap(Rank r1, Rank r2) {
		T temp = _elem[r1];
		_elem[r1] = _elem[r2];
		_elem[r2] = temp;
}

template <class T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	// 冒泡排序
	// 共进行_size轮冒泡
	for (int i = lo; i < hi; i++) {
	  // 每一轮检查_size-1次相邻数据是否非升序，如果是则交换数据
		for (int j = lo; j < (hi - 1); j++) {
			if (_elem[j] > _elem[j + 1]) {
				swap(j, j + 1);
			}
		}
	}
}

template <class T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {
	// 归并排序
	if (lo < hi - 1) {  // lo == hi表示只剩一个字序列，自然已经有序了
		// 递归分解
		Rank mid = (lo + hi) / 2;
		mergeSort(lo, mid);
		mergeSort(mid, hi);
		// 合并
		int i = lo; // 用于跟踪第一子序列位置
		int j = mid; // 用于跟踪第二个字序列位置
		T* temp = new T[hi - lo]; // [lo, hi)左开右闭区间，用来临时存放合并的序列
		int k = 0; // 用于跟踪temp临时序列的位置
		while (true) {
			if ((_elem[i] > _elem[j]) && (j < hi)) {
				temp[k] = _elem[j];
				j++;
				k++;
			} else {
				temp[k] = _elem[i];
				i++;
				k++;
			}
			if ((i >= mid) && (j >= hi)) {
				break;
			}
		}

		for (i = lo; i < hi; i++) {
		  _elem[i] = temp[i - lo];
		}
		delete [] temp;
	}
}
