#include <iostream>
#include <vector>

using namespace std;


class Solution {

private:
    // 边界值
    int m, n;
    vector<vector<bool>> mark;

    int moveArr[4][2] = {{-1, 0},
                         {0,  1},
                         {1,  0},
                         {0,  -1}};

    bool inArea(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void bfsMark(vector<vector<char>> &grid, int i, int j) {
        mark[i][j] = true;

        // move
        for (int k = 0; k < 4; ++k) {
            int newI = i + moveArr[k][0];
            int newJ = j + moveArr[k][1];

            if (inArea(newI, newJ) && !mark[newI][newJ] && grid[newI][newJ] == '1') {
                bfsMark(grid, newI, newJ);
            }
        }

        return;
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        m = grid.size();
        if (m == 0)
            return 0;
        n = grid[0].size();

        // 初始化
        mark = vector<vector<bool>>(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !mark[i][j]) {
                    //  island 加一
                    res++;
                    bfsMark(grid, i, j);
                }
            }
        }

        return res;
    }
};

// floodfill  算法问题
int main() {
    vector<vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
    };
    Solution s;
    cout << s.numIslands(grid) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}