#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    vector<vector<bool>> visited;

    int n, m;

    void dfs(vector<vector<char>> &board, int x, int y) {

        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }

        if (board[x][y] != 'E')
            return;

        int offsetX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int offsetY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        int mines = 0;

        visited[x][y] = true;

        for (int i = 0; i < 8; i++) {
            int row = x + offsetX[i];
            int col = y + offsetY[i];

            if (row < 0 || row >= n || col < 0 || col >= m)
                continue;

            if (board[row][col] == 'M')
                mines++;
        }


        if (mines > 0) {

            board[x][y] = '0' + mines;

        } else {

            board[x][y] = 'B';

            for (int i = 0; i < 8; i++) {

                int row = x + offsetX[i];
                int col = y + offsetY[i];

                if (row < 0 || row >= n || col < 0 || col >= m || visited[row][col])
                    continue;

                dfs(board, row, col);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        int x, y;

        n = board.size();
        m = board[0].size();

        visited.assign(n, vector<bool>(m, false));


        dfs(board, click[0], click[1]);

        return board;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}