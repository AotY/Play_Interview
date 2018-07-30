#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 首先使用动态规划的方法
// 定义状态 memo[i][j] 为从开始到 memo[i][j] 可能的路径
class Solution {
public:
    int uniquePaths(int m, int n) {
        int res = 0;

        if (m == 0 && n == 0)
            return res;

        // 这里如果使用构造方法的初始化全部元素，复杂度是 O(n^2)
        vector<vector<int>> memo(m, vector<int>(n));

        // 只初始化必要的元素
        for (int i = 0; i < m; ++i) {
            memo[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            memo[0][j] = 1;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
            }
        }
        return memo[m - 1][n - 1];
    }
};

int main() {

    Solution s;
    cout << s.uniquePaths(7, 3) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}