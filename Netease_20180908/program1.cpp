#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

// 第一题
// 给定一个N*M的矩阵，在矩阵中每一块有一张牌，我们假定刚开始的时候所有牌的牌面向上。
//  现在对于每个块进行如下操作：
//  翻转某个块中的牌，并且与之相邻的其余八张牌也会被翻转。
// XXX
// XXX
// XXX
//   如上矩阵所示，翻转中间那块时，这九块中的牌都会被翻转一次。
// 请输出在对矩阵中每一块进行如上操作以后，牌面向下的块的个数。
/*
 * 如果相邻的块是奇数，最终向上，如果相邻的块是偶数，最终向下，中间的块，左右上下都有的，
 * 翻完是下，数中间有多少块，就有多少个1，边缘的话另外考虑
5
1 1
1 2
3 1
4 1
2 2

1
0
1
2
0
 */

long cal(long n, long m) {

    if (n == 1 && m == 1) {
        return 1;
    }

    if (n == 1 && m > 1) {
        return m - 2;
    }

    if (n > 1 && m == 1) {
        return n - 2;
    }

    return (m - 2) * (n - 2);
}


int main() {

    // 输入的第一行为测试用例数t(1 <= t <= 100000),
    int t;
    cin >> t;

    // 接下来t行，每行包含两个整数N, M(1 <= N, M <= 1,000,000,000)
    vector<long> result;

    for (int i = 0; i < t; ++i) {
        int n, m;
        cin >> n >> m;

        result.push_back(cal(n, m));
    }

    // 输出仅包含一行，输出牌面向下的块的个数

    for (long i : result) {
        cout << i << endl;
    }

    return 0;
}