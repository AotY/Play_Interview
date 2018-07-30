#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 首先使用记忆化搜索的方法
// 定义状态 memo[i][j] 为从开始到 memo[i][j] 可能的路径
class Solution {
private:
    vector<pair<int, int>> moveWays = {{-1, 0}, // 上，左
                                       {0,  -1}};

    vector<vector<int>> memo;

    bool isNotLegal(int m, int n, int newM, int newN) {
        bool notLegal = ((newM < 0) || (newM >= m) || (newN < 0) || (newN >= n));
        return notLegal;
    }

    int tryUniquePath(int m, int n, int curM, int curN) {

        if (curM == 0 && curN == 0)
            return 1;

        if (memo[curM][curN] != -1)
            return memo[curM][curN];

        int res;
        for (int i = 0; i <= curM; ++i) {
            for (int j = 0; j <= curN; ++j) {
                res = 0;
                for (int k = 0; k < moveWays.size(); ++k) {
                    int newM = i + moveWays[k].first;
                    int newN = j + moveWays[k].second;

                    if (!isNotLegal(m, n, newM, newN)) {
                        res = res + tryUniquePath(m, n, newM, newN);
                    }
                }
            }
        }

        memo[curM][curN] = res;
        return res;
    }

public:


    int uniquePaths(int m, int n) {
        int res = 0;

        memo = vector<vector<int>>(m, vector<int>(n, -1));
        res = tryUniquePath(m, n, m-1, n-1);
        return res;
    }
};

int main() {

    Solution s;
    cout << s.uniquePaths(7, 3) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}