#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;


class Solution {
private:
    int result = 0;

    vector<bool> rowsMark;
    vector<bool> columnsMark;

    vector<bool> mainDiagonalsMark;
    vector<bool> secondDiagonalsMark;

    void searchSolution(int n, int rowNum) {

        if (rowNum >= n) {
            result ++;
            return;
        }

        // 尝试填充这一行
        // 行，列，两个对角线 不能有 Q
        for (int j = 0; j < n; ++j) {
            // 行列可以
            if (!rowsMark[rowNum] && !columnsMark[j]) {

                // 左右对角线是否可以
                int mainIndex = (rowNum - j) + (n-1);
                int secondIndex = rowNum + j;
                if (!mainDiagonalsMark[mainIndex] && !secondDiagonalsMark[secondIndex]) {

                    rowsMark[rowNum] = true;
                    columnsMark[j] = true;

                    mainDiagonalsMark[mainIndex] = true;
                    secondDiagonalsMark[secondIndex] = true;

                    // 尝试填充下一行
                    searchSolution(n, rowNum + 1);

                    // 回溯
                    rowsMark[rowNum] = false;
                    columnsMark[j] = false;
                    mainDiagonalsMark[mainIndex] = false;
                    secondDiagonalsMark[secondIndex] = false;
                }

            }
        }
        return;
    }

public:
    int totalNQueens(int n) {
        if (n == 0)
            return 0;


        // 比如 n = 4

        // 0, 1, 2, 3
        rowsMark = vector<bool>(n, false);
        // 0, 1, 2, 3
        columnsMark = vector<bool>(n, false);

        // (i-j) + 3 (3, 2, 1, 0, -1, -2, -3) -> 6 5 4 3 2 1 0
        mainDiagonalsMark = vector<bool>(n + (n - 1), false);

        // (i + j) 0, 1, 2, 3, 4, 5, 6
        secondDiagonalsMark = vector<bool>(n + (n - 1), false);

        searchSolution(n, 0);

        return result;
    }
};



int main() {

    Solution s;
    cout << s.totalNQueens(4) << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}