#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>

using namespace std;


struct SearchStatus {
    int i;
    int j;

    int matchIndex; // 准备match的位置

    SearchStatus(int i, int j, int matchIndex) : i(i), j(j), matchIndex(matchIndex) {};
};


// 回溯法搜索，可以用队列来实现 （有问题）
class Solution {
private:
    const int moveArr[4][2] = {{-1, 0},
                               {0,  1},
                               {1,  0},
                               {0,  -1}}; //  上 右 下 左


    int n;
    int m;
    vector<vector<bool>> mark;

    bool inArea(int i, int j) {
        if (i >= 0 && i < n && j >= 0 && j < m)
            return true;

        return false;
    }


    bool searchWordInBoard(vector<vector<char>> &board, string &word, int i, int j, string curWord) {

        if (curWord.size() == word.size()) {
            if (curWord == word)
                return true;

            return false;
        }

        int res = false;
        // 上下左右 四个方向查找， 保证不能越界，还要标记是否已经访问
        for (int k = 0; k < 4; ++k) {
            int newI = i + moveArr[k][0];
            int newJ = j + moveArr[k][1];

            if (inArea(newI, newJ) && !mark[newI][newJ]) {
                mark[newI][newI] = true;
                curWord.push_back(board[newI][newI]);
                res = searchWordInBoard(board, word, newI, newJ, curWord);
                if (res)
                    return true;
                curWord.pop_back();
                mark[newI][newI] = false;

            }
        }


        return res;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        n = board.size();
        set<string> resultsSet;
        vector<string> results;
        if (n == 0)
            return results;
        m = board[0].size();

        mark = vector<vector<bool>>(n, vector<bool>(m, false));

        // 搜索每一个word是否在board出现
        for (int i = 0; i < words.size(); ++i) {
            bool isBreak = false;
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < m; ++k) {
                    if (board[j][k] == words[i][0]) {
                        string curWord = "";
                        curWord.push_back(board[j][k]);
                        mark[j][k] = true;
                        bool isExists = searchWordInBoard(board, words[i], j, k, curWord);
                        if (isExists) {
                            resultsSet.insert(words[i]);
                            isBreak = true;
                            break;
                        }
                        mark[j][k] = false;
                        curWord.pop_back();
                    }
                }

                if (isBreak)
                    break;
            }


        }

        // 需要去重
        results = vector<string>(resultsSet.begin(), resultsSet.end());

        return results;
    }
};


int main() {

    Solution s;

    vector<string> words = {"aabbbbabbaababaaaabababbaaba"}; //
    vector<vector<char>> board = {
            {'b', 'a', 'a', 'b', 'a', 'b'},
            {'a', 'b', 'a', 'a', 'a', 'a'},
            {'a', 'b', 'a', 'a', 'a', 'b'},
            {'a', 'b', 'a', 'b', 'b', 'a'},
            {'a', 'a', 'b', 'b', 'a', 'b'},
            {'a', 'a', 'b', 'b', 'b', 'a'},
            {'a', 'a', 'b', 'a', 'a', 'b'}
    };

    // 需要去重
    vector<string> results = s.findWords(board, words);


    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }


    return 0;
}