#include <iostream>
#include <vector>

using namespace std;

// 思路，与border相连接的Mark就好，其他的就填充啦。
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

    void dfsMark(vector<vector<char>> &board, int i, int j) {

        if (!inArea(i, j)) {
            return;
        }

        mark[i][j] = true;

        // move
        for (int k = 0; k < 4; ++k) {
            int newI = i + moveArr[k][0];
            int newJ = j + moveArr[k][1];

            if (inArea(newI, newJ) && board[newI][newJ] == 'O' && !mark[newI][newJ]) { //
                dfsMark(board, newI, newJ);
            }
        }

        return;
    }

public:
    void solve(vector<vector<char>> &board) {

        m = board.size();
        if (m <= 2)
            return;

        n = board[0].size();
        if (n <= 2)
            return;

        // 初始化
        mark = vector<vector<bool>>(m, vector<bool>(n, false));

        // 第一行
        for (int i = 0; i < n; ++i) {
            if (board[0][i] == 'O' && !mark[0][i]) { //  && !mark[i][j]
                dfsMark(board, 0, i);
            }
        }

        // 最后一行
        for (int i = 0; i < n; ++i) {
            if (board[m - 1][i] == 'O' && !mark[m - 1][i]) { //  && !mark[i][j]
                dfsMark(board, m - 1, i);
            }
        }

        // 第一列
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O' && !mark[i][0]) { //  && !mark[i][j]
                dfsMark(board, i, 0);
            }
        }

        // 最后一列
        for (int i = 0; i < m; ++i) {
            if (board[i][n - 1] == 'O' && !mark[i][n - 1]) { //  && !mark[i][j]
                dfsMark(board, i, n - 1);
            }
        }

        // flipping
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !mark[i][j])
                    board[i][j] = 'X';

            }
        }
    }
};

int main() {

//    vector<vector<char>> grid = {{'O', 'O', 'O', 'O', 'X', 'X'},
//                                 {'O', 'O', 'O', 'O', 'O', 'O'},
//                                 {'O', 'X', 'O', 'X', 'O', 'O'},
//                                 {'O', 'X', 'O', 'O', 'X', 'O'},
//                                 {'O', 'X', 'O', 'X', 'O', 'O'},
//                                 {'O', 'X', 'O', 'O', 'O', 'O'}};

    vector<vector<char>> grid = {{'O', 'O', 'X', 'X'},
                                 {'X', 'O', 'O', 'X'},
                                 {'X', 'X', 'O', 'X'},
                                 {'X', 'O', 'X', 'X'}};
    Solution s;
    s.solve(grid);

    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}