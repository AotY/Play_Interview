#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <unordered_set>


using namespace std;


// 暴力搜索超时，需要加上一些启发式的策略，减少搜索空间大小
// 从已有限制最多的位置开始搜索

struct BoardPosition {
    int x; //
    int y; //  位置信息

    int restriction; // 限制个数

    BoardPosition(int _x, int _y, int _restriction) : x(_x), y(_y), restriction(_restriction) {};
};

// 按照限制个数排序
bool positionCompare(const BoardPosition &bp1, const BoardPosition &bp2) {
    if (bp1.restriction == bp2.restriction) {
        return bp1.x < bp2.x;
    } else {
        return bp1.restriction > bp2.restriction;
    }
}


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


    bool solveSudoku(vector<vector<char>> &board, vector<BoardPosition> &restrictionPositions, int curIndex) {

        // 检查是否完成
        if (curIndex >= restrictionPositions.size()) {
            for (int i = 0; i < N; ++i) {
                if (rows[i].size() != N)
                    return false;
            }

            for (int i = 0; i < N; ++i) {
                if (columns[i].size() != N)
                    return false;
            }

            for (int i = 0; i < N; ++i) {
                if (subBoards[i].size() != N)
                    return false;
            }

            return true;

        }

        // 没有完成

        int curI = restrictionPositions[curIndex].x;
        int curJ = restrictionPositions[curIndex].y;

        // 尝试每一个数字是否满足题意
        for (int i = 0; i < N; ++i) {

            char curDigit = digits[i];

            // 如果i能放入该位置
            if (rows[curI].find(curDigit) == rows[curI].end() && columns[curJ].find(curDigit) == columns[curJ].end()) {

                // 判断属于哪一个子区域
                int subIndex = curI / THREE * THREE + curJ / THREE;

                if (subBoards[subIndex].find(curDigit) == subBoards[subIndex].end()) {

                    // 可以填充
//                    board[curI][curJ] = curDigit;


                    rows[curI].insert(curDigit);
                    columns[curJ].insert(curDigit);
                    subBoards[subIndex].insert(curDigit);

                    // 找到下一个为零的地方尝试填充，不行就回溯

                    bool res = solveSudoku(board, restrictionPositions, curIndex + 1);

                    if (res)
                        return true;

                    // 回溯
                    rows[curI].erase(rows[curI].find(curDigit));
                    columns[curJ].erase(columns[curJ].find(curDigit));
                    subBoards[subIndex].erase(subBoards[subIndex].find(curDigit));

//                    board[curI][curJ] = '.';
                }

            }
        }

        return false;

    }


public:
    bool isValidSudoku(vector<vector<char>> &board) {


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


        //
        vector<BoardPosition> restrictionPositions = vector<BoardPosition>();

        for (int i = 0; i < zeroPositions.size(); ++i) {

            int _x = zeroPositions[i].first;
            int _y = zeroPositions[i].second;
            int _subIndex = _x / THREE * THREE + _y / THREE;
            int _restriction = (int) (rows[_x].size() + columns[_y].size() + subBoards[_subIndex].size());

            restrictionPositions.push_back(BoardPosition(_x, _y, _restriction));
        }


        sort(restrictionPositions.begin(), restrictionPositions.end(), positionCompare);


        return solveSudoku(board, restrictionPositions, 0);
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