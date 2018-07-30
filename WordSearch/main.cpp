#include <iostream>
#include <vector>

using namespace std;

static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

// 基本的回溯法，是否可以利用剪枝来提高效率呢？
class Solution {
private:

    vector<pair<int, int>> moveWays = {{-1, 0}, // 上
                                       {0,  1}, // 右
                                       {1,  0}, // 下
                                       {0,  -1} // 左
    };


    vector<vector<bool>> mark;

    bool isLegal(int m, int n, int newM, int newN) {
        bool notLegal = ((newM < 0) || (newM >= m) || (newN < 0) || (newN >= n));
        return !notLegal;
    }

    bool existPath(vector<vector<char>> &board, string word, int m, int n, int startI, int startJ, int index) {

        if (index > (word.size() - 1)) {
            return true;
        }

        bool res = false;

        for (int k = 0; k < moveWays.size(); ++k) {
            int newI = moveWays[k].first + startI;
            int newJ = moveWays[k].second + startJ;

            if (isLegal(m, n, newI, newJ) && !mark[newI][newJ] && word[index] == board[newI][newJ]) {
                mark[newI][newJ] = true;
                res = res || existPath(board, word, m, n, newI, newJ, index + 1);
                mark[newI][newJ] = false;
            }
        }

        return res;

    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size();
        int n = board[0].size();

        mark = vector<vector<bool>>(m, vector<bool>(m, false));

        bool res = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    mark[i][j] = true;
                    res =  existPath(board, word, m, n, i, j, 1);
                    if (res) //
                        return true;
                    mark[i][j] = false;
                }
            }
        }

        return res;
    }
};


int main() {


    vector<vector<char>> board = {
            {'F', 'Y', 'C', 'E', 'N', 'R', 'D'},
            {'K', 'L', 'N', 'F', 'I', 'N', 'U'},
            {'A', 'A', 'A', 'R', 'A', 'H', 'R'},
            {'N', 'D', 'K', 'L', 'P', 'N', 'E'},
            {'A', 'L', 'A', 'N', 'S', 'A', 'P'},
            {'O', 'O', 'G', 'O', 'T', 'P', 'N'},
            {'H', 'P', 'O', 'L', 'A', 'N', 'O'}
    };
//
//    vector<vector<char>> board = {
//            {'A'}
//    };

    Solution s;
    cout << s.exist(board, "HOLLAND") << endl;

    return 0;
}