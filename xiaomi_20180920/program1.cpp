#include <iostream>
#include <vector>

using namespace std;

// 大礼包
// 小米之家是成人糖果店。里面有很多便宜，好用，好玩的产品。
// 中秋节快到了，小米之家想给米粉们准备一些固定金额大礼包。
// 对于给定的一个金额，需要判断 能不能 用不同种产品（一种产品在礼包最多出现一次）组合出来这个金额。
// 聪明的你来帮帮米家的小伙伴吧。

//输入 N （N 是正整数， N  <= 200）
//输入 N 个价格p（正整数, p <= 10000）用单空格分割
//输入金额 M（M是正整数，M <= 100000 ）

// 能组合出来输出 1
// 否则输出 0

bool canCombination(vector<int> &prices, int index, int m, vector<vector<int>> &memo) {

    if (m == 0)
        return true;

    if (m < 0 || index >= prices.size())
        return false;



    if (memo[index][m] != -1)
        return memo[index][m] == 1;

    // 考虑当前的price, 或者不考虑当前的price
    bool res = canCombination(prices, index + 1, m - prices[index], memo) ||
            canCombination(prices, index + 1, m, memo);

    memo[index][m] = res ? 1 : 0;

    return res;
}

int main() {

    int N;
    cin >> N;

    vector<int> prices = vector<int>(N);
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }

    int M;
    cin >> M;

    vector<vector<int>> memo = vector<vector<int>>(N, vector<int>(M + 1, -1));

    bool res = canCombination(prices, 0, M, memo);

    if (res)
        cout << 1 << endl;
    else
        cout << 0 << endl;


    return 0;
}

/**
6
99 199 1999 10000 39 1499
10238


1
*/