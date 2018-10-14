/*
 * main2.cpp
 * Copyright (C) 2018 LeonTao
 *
 * Distributed under terms of the MIT license.
 */

/* #include "main2.h" */
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>


using namespace std;


/*
 *在数学分析中，有这样一个问题：能否用一条无限长的线，穿过任意维度空间里面的所有点？答案是肯定的，
 *而且不止有一种这样的曲线。Hilbert曲线就是其中的一种，它在边长n=2，4，8的图上的 索引效果如下所示
 *
 */

void rotate(int n, pair<int, int> &point, pair<int,int> &rotatePoint){
	if (rotatePoint.second == 0){
		if (rotatePoint.first == 1){
			point.first = n - 1 - point.first;
			point.second = n - 1 - point.second;
		}

        swap(point.first, point.second);
		// int tmp  = point.first;
		// point.first = point.second;
		// point.second = tmp;
	}
}


int xy2Hilbert (int n, pair<int, int> &point)
{
    pair<int, int> rotatePoint;
    int res=0;
	for (int i = n/2; i > 0; i /= 2)
	{
		rotatePoint.first = (point.first & i) > 0;
		rotatePoint.second = (point.second & i) > 0;
		res += i * i * ((3 * rotatePoint.first) ^ rotatePoint.second);
		rotate(i, point, rotatePoint);
	}
	return res;
}


int main() {

	int n;
	// cin >> n;
	n = 4;

	for (int i = n-1; i >= 0; i--){
		for (int j = 0; j < n; j++) {
            pair<int, int> point = make_pair(j , i);
			cout << xy2Hilbert(n, point) + 1 << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}
