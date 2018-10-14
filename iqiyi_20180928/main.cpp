
#include <iostream>
#include <vector>

using namespace std;

// 清雨又在吃自助餐了。
// 排在清雨面前的有N种食物，排成一排，清雨可以选择其中的若干种食物，但是不能连续选择相邻的食物。
// 因为清雨很挑食，当所有食物都不合口味时，他可以一种都不选，即一个都不选也算为一种方法。
// 请问他有多少种选择食物的方法呢？

int main() {

    int n;
    cin >> n;
    long res;
    if (n == 1)
        res = 2;
    else {

        long a = 2;
        long b = 3;
        for (int i = 3; i <= n; ++i) {
            long tmp = a + b;
            a = b;
            b = tmp;
        }
        res = b;
    }

    cout << res << endl;


    return 0;
}

/*
5 20
4 42 40 26 46

*/
// 36