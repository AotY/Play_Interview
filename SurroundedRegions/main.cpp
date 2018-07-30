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

    vector<vector<int>> memo; // -1 没有记录， 0 - 不能flipping， 1- 可以flipping
    bool inArea(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    bool isBorder(int i, int j) {
        return 0 == i || i == (m - 1) || j == 0 || j == (n - 1);
    }

    bool isMark(vector<vector<char>> &board, int i, int j) {

        if (isBorder(i, j)) {
            return false;
        }

        if (memo[i][j] != -1) {
            if (memo[i][j] == 0)
                return false;
        }

        mark[i][j] = true;

        bool sureMark = true;

        // move
        for (int k = 0; k < 4; ++k) {

//            if(!sureMark)
//                break;

            int newI = i + moveArr[k][0];
            int newJ = j + moveArr[k][1];

            if (inArea(newI, newJ) && board[newI][newJ] == 'O' && !mark[newI][newJ]) { //
                sureMark = sureMark && isMark(board, newI, newJ);
            }
        }

        memo[i][j] = sureMark ? 1 : 0;
        mark[i][j] = false;

        return sureMark;
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

        memo = vector<vector<int>>(m, vector<int>(n, -1));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') { //  && !mark[i][j]
                    //  island 加一
                    bool sureMark = isMark(board, i, j);
                    if (sureMark)
                        board[i][j] = 'X';
                }
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