#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 首先使用动态规划的方法
// 定义状态 memo[i][j] 为从开始到 memo[i][j] 可能的路径
class Solution {
private:
    vector<pair<int, int>> moveWays = {{-1, 0}, // 上，左
                                       {0,  -1}};


    bool isNotLegal(int m, int n, int newM, int newN) {
        bool notLegal = ((newM < 0) || (newM >= m) || (newN < 0) || (newN >= n));
        return notLegal;
    }

public:


    int uniquePaths(int m, int n) {
        int res = 0;

        if (m == 0 && n == 0)
            return res;

        vector<vector<int>> memo(m, vector<int>(n, 0));

        memo[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                for (int k = 0; k < moveWays.size(); ++k) {
                    int newM = i + moveWays[k].first;
                    int newN = j + moveWays[k].second;

                    if (!isNotLegal(m, n, newM, newN)) {
                        memo[i][j] = memo[i][j] + memo[newM][newN];
                    }
                }
            }
        }
        return memo[m-1][n-1];
    }
};

int main() {

    Solution s;
    cout << s.uniquePaths(7, 3) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}