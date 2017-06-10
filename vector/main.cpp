﻿// Copyright 2017 zhongxin
// license: BSD
// author: zhongxin

// 依据邓俊辉老师的《数据结构》mooc课程的练习
#include <iostream>

#include "vector.h"

using namespace std;

int main() {
	Vector<int> v;
	cout << "初始向量长度为：" << v.size() << endl;
	for (int i = 0; i < 100; i++) {
		v.insert(i, i);
		cout << "向量秩为" << i << "的元素为：" << v.get(i) << endl;
	}
	cout << "目前向量的长度为：" << v.size() << endl;
	
	system("pause");
	return 0;
}