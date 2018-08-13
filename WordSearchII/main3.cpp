#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        string str;

        TrieNode() : str("") {
            for (auto &a : child)
                a = NULL;
        }
    };

    struct Trie {
        TrieNode *root;

        Trie() : root(new TrieNode()) {}

        void insert(string s) {
            TrieNode *tmpRoot = root;
            for (auto &a : s) {
                int i = a - 'a'; // index
                if (!tmpRoot->child[i])
                    tmpRoot->child[i] = new TrieNode();

                tmpRoot = tmpRoot->child[i];
            }

            tmpRoot->str = s;
        }
    };

    vector<string> findWords(vector<vector<char> > &board, vector<string> &words) {
        vector<string> res;

        if (words.empty() || board.empty() || board[0].empty())
            return res;

        vector<vector<bool> > visit(board.size(), vector<bool>(board[0].size(), false));

        Trie T;
        //  创建前缀树
        for (auto &a : words)
            T.insert(a);

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (T.root->child[board[i][j] - 'a']) {
                    // 如果满足第一个位置
                    search(board, T.root->child[board[i][j] - 'a'], i, j, visit, res);
                }
            }
        }
        return res;
    }

    void
    search(vector<vector<char> > &board, TrieNode *p, int i, int j, vector<vector<bool> > &visit, vector<string> &res) {

        if (!p->str.empty()) {
            res.push_back(p->str);
            p->str.clear();
        }

        int d[][2] = {{-1, 0},
                      {1,  0},
                      {0,  -1},
                      {0,  1}};

        //
        visit[i][j] = true;

        for (auto &a : d) {
            int nx = a[0] + i, ny = a[1] + j;
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !visit[nx][ny] &&
                p->child[board[nx][ny] - 'a']) {
                search(board, p->child[board[nx][ny] - 'a'], nx, ny, visit, res);
            }
        }
        //
        visit[i][j] = false;
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