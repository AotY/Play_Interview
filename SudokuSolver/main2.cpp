#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <unordered_set>


using namespace std;



class Solution {
private:
    const static int N = 9;

    const static int THREE = 3;

    const char digits[N] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    // 9 行
    vector<unordered_set<char>> rows = vector<unordered_set<char>>(N, unordered_set<char>());

    // 9 列
    vector<unordered_set<char>> columns = vector<unordered_set<char>>(N, unordered_set<char>());

    // 9 个 区域
    vector<unordered_set<char>> subBoards = vector<unordered_set<char>>(N, unordered_set<char>());

    bool solveSudoku(vector<vector<char>> &board, vector<pair<int, int>> &zeroPositions, int curIndex) {

        // 检查是否完成
        if (curIndex >= zeroPositions.size()) {
            return true;
        }

        // 没有完成

        int curI = zeroPositions[curIndex].first;
        int curJ = zeroPositions[curIndex].second;

        // 尝试每一个数字是否满足题意
        for (int i = 0; i < N; ++i) {

            char curDigit = digits[i];

            // 如果i能放入该位置
            if (rows[curI].find(curDigit) == rows[curI].end() && columns[curJ].find(curDigit) == columns[curJ].end()) {

                // 判断属于哪一个子区域
                int subIndex = curI / THREE * THREE + curJ / THREE;

                if (subBoards[subIndex].find(curDigit) == subBoards[subIndex].end()) {

                    // 可以填充
                    board[curI][curJ] = curDigit;

                    rows[curI].insert(curDigit);
                    columns[curJ].insert(curDigit);
                    subBoards[subIndex].insert(curDigit);

                    // 找到下一个为零的地方尝试填充，不行就回溯

                    if(solveSudoku(board, zeroPositions, curIndex + 1))
                        return true;

                    // 回溯
                    rows[curI].erase(rows[curI].find(curDigit));
                    columns[curJ].erase(columns[curJ].find(curDigit));
                    subBoards[subIndex].erase(subBoards[subIndex].find(curDigit));

                    board[curI][curJ] = '.';
                }

            }
        }

        return false;
    }


public:
    void solveSudoku(vector<vector<char>> &board) {


        vector<pair<int, int>> zeroPositions = vector<pair<int, int>>();

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {

                // 需要填充
                if (board[i][j] == '.') {
                    zeroPositions.push_back(make_pair(i, j));
                } else { // 是数字

                    // 判断属于哪一个子区域
                    int subIndex = i / THREE * THREE + j / THREE;

                    // 插入的是当前值
                    rows[i].insert(board[i][j]);
                    columns[j].insert(board[i][j]);
                    subBoards[subIndex].insert(board[i][j]);
                }

            }
        }

        solveSudoku(board, zeroPositions, 0);

    }
};

int main() {


    vector<vector<char>> board =
            {
                    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
            };


    Solution s;

    s.solveSudoku(board);


    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (j == 9 - 1)
                cout << board[i][j];
            else
                cout << board[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}