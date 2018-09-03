#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>


using namespace std;

// 数独
// 输入9行，每行为空格隔开的9个数字，为0的地方就是需要填充的。
// 输出九行，每行九个空格隔开的数字，为解出的答案。


// 尝试填充一个值，然后能否搜索下去
// 三个条件
// 每一行都用到1,2,3,4,5,6,7,8,9
// 每一列都用到1,2,3,4,5,6,7,8,9
// 每3×3的格子都用到1,2,3,4,5,6,7,8,9

int N = 9;

int moveArr[4][2] = {
        {1,  0},
        {0,  1},
        {-1, 0},
        {0,  -1}
};

bool inSudoku(int i, int j) {
    return (i >= 0 && i < N) && (j >= 0 && j < N);
}

// 9 行
//vector<vector<int>> rows = vector<vector<int>>(9, vector<int>(9 + 1, 0));
vector<set<int>> rows = vector<set<int>>(N, set<int>());


// 9 列
//vector<vector<int>> columns = vector<vector<int>>(9, vector<int>(9 + 1, 0));
vector<set<int>> columns = vector<set<int>>(N, set<int>());


// 9 个 区域
//vector<vector<int>> subSudokus = vector<vector<int>>(9, vector<int>(9 + 1, 0));
vector<set<int>> subSudokus = vector<set<int>>(N, set<int>());

bool solveSudoku(vector<vector<int>> &sudoku, stack<pair<int, int>> &zeroPositions) {

    // 检查是否完成
    if (zeroPositions.empty()) {
        for (int i = 0; i < N; ++i) {
            if (rows[i].size() != 9)
                return false;
        }

        for (int i = 0; i < N; ++i) {
            if (columns[i].size() != 9)
                return false;
        }

        for (int i = 0; i < N; ++i) {
            if (subSudokus[i].size() != 9)
                return false;
        }

        return true;

    }

    // 没有完成

    int curI = zeroPositions.top().first;
    int curJ = zeroPositions.top().second;

    // 尝试每一个数字是否满足题意
    for (int i = 1; i <= N; ++i) {

        // 如果i能放入该位置
        if (rows[curI].find(i) == rows[curI].end() && columns[curJ].find(i) == columns[curJ].end()) {

            // 判断属于哪一个子区域
            int subIndex = curI / 3 * 3 + curJ / 3;

            if (subSudokus[subIndex].find(i) == subSudokus[subIndex].end()) {

                // 可以填充
                sudoku[curI][curJ] = i;

                zeroPositions.pop();

                rows[curI].insert(i);
                columns[curJ].insert(i);
                subSudokus[subIndex].insert(i);

                // 找到下一个为零的地方尝试填充，不行就回溯

                bool res = solveSudoku(sudoku, zeroPositions);
                if (res)
                    return true;

                // 回溯
                rows[curI].erase(rows[curI].find(i));
                columns[curJ].erase(columns[curJ].find(i));
                subSudokus[subIndex].erase(subSudokus[subIndex].find(i));

                sudoku[curI][curJ] = 0;

                zeroPositions.push(make_pair(curI, curJ));

            }

        }
    }

    return false;

}

int main() {


    vector<vector<int>> sudoku = vector<vector<int>>(N, vector<int>(N));

    stack<pair<int, int>> zeroPositions = stack<pair<int, int>>();


    int startI, startJ;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> sudoku[i][j];

            if (sudoku[i][j] == 0) {
//                zeroPositions.insert(make_pair(i, j));
                zeroPositions.push(make_pair(i, j));
            } else  {
                // 判断属于哪一个子区域
                int subIndex = i / 3 * 3 + j / 3;

                // 插入的是当前值
                rows[i].insert(sudoku[i][j]);
                columns[j].insert(sudoku[i][j]);
                subSudokus[subIndex].insert(sudoku[i][j]);

            }
        }
    }

    solveSudoku(sudoku, zeroPositions);

    cout << endl;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j != N - 1)
                cout << sudoku[i][j] << " ";
            else
                cout << sudoku[i][j];
        }
        cout << endl;
    }
    return 0;
}


/*

0 9 5 0 2 0 0 6 0
0 0 7 1 0 3 9 0 2
6 0 0 0 0 5 3 0 4
0 4 0 0 1 0 6 0 7
5 0 0 2 0 7 0 0 9
7 0 3 0 9 0 0 2 0
0 0 9 8 0 0 0 0 6
8 0 6 3 0 2 1 0 5
0 5 0 0 7 0 2 8 3


 *
 */