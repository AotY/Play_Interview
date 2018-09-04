#include <iostream>
#include <vector>
#include <string>


using namespace std;


class Solution {
private:

    int n, m;

    int moveArr[8][2] = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0,  1},
            {1,  1},
            {1,  0},
            {1,  -1},
            {0,  -1}
    };


    bool inArea(int i, int j) {
        return (i >= 0 && i < n) && (j >= 0 && j < m);
    }


    vector<vector<bool>> mark;

    void tryClick(vector<vector<char>> &board, int curI, int curJ) {

        if (board[curI][curJ] == 'M') {
            board[curI][curJ] = 'X';
            return;
        }

        if (board[curI][curJ] != 'E')
            return;


        // mark
        mark[curI][curJ] = true;

        int mines = 0;

        for (int k = 0; k < 8; ++k) {
            int newI = moveArr[k][0] + curI;
            int newJ = moveArr[k][1] + curJ;

            if (inArea(newI, newJ)) {
                if (board[newI][newJ] == 'M')
                    mines++;
            }
        }

        // 周围有 mines
        if (mines > 0) {
            board[curI][curJ] = '0' + mines;
        } else {
            // 周围没有
            board[curI][curJ] = 'B';

            // 尝试继续填充
            for (int k = 0; k < 8; ++k) {
                int newI = moveArr[k][0] + curI;
                int newJ = moveArr[k][1] + curJ;

                if (inArea(newI, newJ) && !mark[newI][newJ]) {
                    tryClick(board, newI, newJ);
                }
            }

        }

        return;

    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {


        n = board.size();
        if (n == 0)
            return board;

        m = board[0].size();


        mark = vector<vector<bool>>(n, vector<bool>(m, false));
        tryClick(board, click[0], click[1]);

        return board;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}