#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>

using namespace std;

// 需要用 前缀树实现，搜索超时


struct TrieNode {

    string word;

    TrieNode *child[26];

    //
    TrieNode() {
        word = "";
        for (int i = 0; i < 26; ++i) {
            child[i] = NULL;
        }
    }


};

class Solution {
private:
    TrieNode *root;
    vector<string> results;

    const int moveArr[4][2] = {{-1, 0},
                               {0,  1},
                               {1,  0},
                               {0,  -1}}; //  上 右 下 左


    int m; // 行
    int n;  // 列

    vector<vector<bool>> mark;

    bool inArea(int i, int j) {
        if (i >= 0 && i < m && j >= 0 && j < n)
            return true;

        return false;
    }


    void insert2Trie(TrieNode *root, string word) {
        TrieNode *tmpRoot = root;

        for (int i = 0; i < word.size(); ++i) {
            int charIndex = word[i] - 'a';
            if (tmpRoot->child[charIndex] == NULL)
                tmpRoot->child[charIndex] = new TrieNode();

            tmpRoot = tmpRoot->child[charIndex];
        }
        tmpRoot->word = word;
    }


    void searchInTrie(TrieNode *node, vector<vector<char>> &board) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (node->child[board[i][j] - 'a']) {
                    movingInTrie(node->child[board[i][j] - 'a'], board, i, j);
                }

            }
        }
    }


    void movingInTrie(TrieNode *node, vector<vector<char>> &board, int i, int j) {

        if (!node->word.empty()) {
            results.push_back(node->word);
            node->word.clear(); // 只需要记录一次
//            return;
        }

        // 四个方向上移动

        mark[i][j] = true;

        for (int k = 0; k < 4; ++k) {

            int newI = i + moveArr[k][0];
            int newJ = j + moveArr[k][1];

            if (inArea(newI, newJ) && !mark[newI][newJ]
                && node->child[board[newI][newJ] - 'a']) {
                movingInTrie(node->child[board[newI][newJ] - 'a'],
                             board, newI, newJ);
            }
        }

        mark[i][j] = false;
        return;
    }


public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {

        if (words.size() == 0)
            return results;

        m = board.size();
        if (m == 0)
            return results;
        n = board[0].size();


        // 先根据  words 建立前缀树
        root = new TrieNode();

        for (int i = 0; i < words.size(); ++i) {
            insert2Trie(root, words[i]);
        }

        mark = vector<vector<bool>>(m, vector<bool>(n, false));

        // board 在tire中是否能查找到单词
        searchInTrie(root, board);


        return results;
    }
};


int main() {

    Solution s;
//
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

//    vector<string> words = {"oath", "pea", "eat", "rain"};
//
//    vector<vector<char>> board = {
//            {'o', 'a', 'a', 'n'},
//            {'e', 't', 'a', 'e'},
//            {'i', 'h', 'k', 'r'},
//            {'i', 'f', 'l', 'v'}
//    };

//    vector<string> words = {"aa"};
//    vector<vector<char>> board = {
//            {'a', 'a'}
//    };

    // 需要去重
    vector<string> results = s.findWords(board, words);


    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }


    return 0;
}