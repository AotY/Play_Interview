#include <iostream>
#include <vector>

using namespace std;

// 经典的动态规划的题目，状态转移方程为 L(i, j)  = min( L(i - 1, j), L(i - 1, L(i - 1, j) - weights[j]))
// 在考虑 0到i个物品时箱子的最小剩余空间

/**
 *
 * @param weights
 * @param memo
 * @param n
 * @param v
 * @return
 */
int minLeftV(const vector<int> &weights, int n, int V) {

    // memo[i][j]  = min( memo[i - 1][j], memo[i - 1][j] - weights[i])
    vector<vector<int>> memo = vector<vector<int>>(n, vector<int>(V + 1));
//    vector<vector<int>> memo = vector<vector<int>>(2, vector<int>(V + 1)); // 优化，因为每一个只需要用到上一个状态的值


    // 初始化状态，只考虑第0号物品 （按下标顺序）
    for (int j = 1; j <= V; ++j) {
        memo[0][j] = j >= weights[0] ? j - weights[0] : j;
    }


    // 从第1号物品开始
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= V; ++j) { // V从1开始
            // 1. 不考虑这个物品
            memo[i][j] = memo[i - 1][j];
//            memo[i % 2][j] = memo[i - 1][j]; // 优化
            // 2. 考虑这个物品，如果能放下的话，减去当前物品的重量
            if (j >= weights[i])
                memo[i][j] = min(memo[i][j], memo[i - 1][j - weights[i]]);
//                memo[i % 2][j] = min(memo[i % 2][j], memo[(i - 1)  % 2][j - weights[i]]); // 优化
        }
    }

    // 返回最后一个状态的值
    return memo[n - 1][V];
    return memo[(n - 1) % 2][V]; // 优化
}


int main() {

    // 箱子容量为V（正整数，0<=v<=20000），同时有n个物品（0< n<n<=30），

    int V; // 箱子容量 V

    int n; //n个物品

    cin >> V;

    cin >> n;

    vector<int> weights = vector<int>(n);

    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    int res = minLeftV(weights, n, V);


    cout << res << endl;


    return 0;
}