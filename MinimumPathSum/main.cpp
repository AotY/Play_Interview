#include <iostream>
#include <vector>

using namespace std;



// Minimum Path Sum ，动态规划问题 [0, 0] -> [m-1, n-1]路径上的最小和

class Solution {

private:

    int m, n;

    bool inPath(int i, int j) {
        return (i >= 0 && i < m) && (j >= 0 && j < n);
    }


    int moveArr[2][2] = {
            {0,  -1},
            {-1, 0}
    };

public:
    int minPathSum(vector<vector<int>> &grid) {
        m = grid.size();
        if (m == 0)
            return 0;

        n = grid[0].size();


        // memo[i][j]  到i,j的最小和
        vector<vector<int>> memo = vector<vector<int>>(m, vector<int>(n));


        // 状态转移
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int tmp = INT_MAX;
                for (int k = 0; k < 2; ++k) {
                    int lastI = i + moveArr[k][0];
                    int lastJ = j + moveArr[k][1];
                    if (inPath(lastI, lastJ)) {
                        tmp = min(tmp, memo[lastI][lastJ]);
                    }
                }
                tmp = tmp == INT_MAX ? 0 : tmp;
                memo[i][j] = tmp + grid[i][j];
            }
        }


        return memo[m - 1][n - 1];

    }
};


int main() {

    Solution s;
    vector<vector<int>> grid = {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };

    cout << s.minPathSum(grid) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}