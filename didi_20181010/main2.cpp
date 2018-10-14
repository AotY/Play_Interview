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

void rot(int n, int *x, int *y, int rx, int ry)
{
	if (ry == 0){
		if (rx == 1){
			*x = n - 1 - *x;
			*y = n - 1 - *y;
		}

		int t  = *x;
		*x = *y;
		*y = t;
	}
}


int xy2Hilbert (int n, int x, int y)
{
	int rx, ry, s, d=0;
	for (s=n/2; s>0; s/=2)
	{
		rx = ((x & s) > 0) ? 1 : 0;
		ry = ((y & s) > 0) ? 1 : 0;
		d += s * s * ((3 * rx) ^ ry);
		rot(s, &x, &y, rx, ry);
	}
	return d;
}


int main() {

	int n;
	// cin >> n;
	n = 4;

	for (int i = n-1; i >= 0; i--){
		for (int j = 0; j < n; j++) {
			cout << xy2Hilbert(n, j, i) + 1<< " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}
