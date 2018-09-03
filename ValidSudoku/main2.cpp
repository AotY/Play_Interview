#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <unordered_set>


using namespace std;

// 看错题目，只需要验证输入的数独是否合法就好了
class Solution {
private:
    const static int N = 9;

    const static int THREE = 3;

    // 9 行
    vector<unordered_set<char>> rows = vector<unordered_set<char>>(N, unordered_set<char>());

    // 9 列
    vector<unordered_set<char>> columns = vector<unordered_set<char>>(N, unordered_set<char>());


    // 9 个 区域
    vector<unordered_set<char>> subBoards = vector<unordered_set<char>>(N, unordered_set<char>());



public:
    bool isValidSudoku(vector<vector<char>> &board) {


        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {

                // 需要填充
                if (board[i][j] != '.') {
                // 是数字

                    // 插入的是当前值
                    if (rows[i].find(board[i][j]) == rows[i].end()) {
                        rows[i].insert(board[i][j]);
                    } else {
                        return false;
                    }

                    if (columns[j].find(board[i][j]) == columns[j].end()) {
                        columns[j].insert(board[i][j]);
                    } else {
                        return false;
                    }

                    // 判断属于哪一个子区域
                    int subIndex = i / THREE * THREE + j / THREE;

                    if (subBoards[subIndex].find(board[i][j]) == subBoards[subIndex].end()) {
                        subBoards[subIndex].insert(board[i][j]);
                    } else {
                        return false;
                    }

                }

            }
        }

        return true;

    }
};

int main() {


    vector<vector<char>> board =
//            {
//                    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//                    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//                    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//                    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//                    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//                    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//                    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//                    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//                    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
//            };

            {
                    {'.', '8', '7', '6', '5', '4', '3', '2', '1'},
                    {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'9', '.', '.', '.', '.', '.', '.', '.', '.'}
            };

    Solution s;

    cout << s.isValidSudoku(board) << endl;
    return 0;
}