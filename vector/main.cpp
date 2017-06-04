// Copyright 2017 zhongxin
// license: BSD
// author: zhongxin

// 依据邓俊辉老师的《数据结构》mooc课程的练习
#include <iostream>

#include "vector.h"

using namespace std;

int main() {
	Vector<int> v(10, 6, 8);
	cout << v.size() << endl;

	system("pause");
	return 0;
}