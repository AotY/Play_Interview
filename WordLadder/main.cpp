#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;


class Solution {
private:
    int diffCount(string &curWord, string nexWord) {
        int count = 0;
        for (int i = 0; i < curWord.size(); ++i) {
            if (curWord[i] != nexWord[i])
                count++;
        }
        return count;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        int res = 0;


        // word, times
        queue<pair<string, int>> searchQueue;
        searchQueue.push(make_pair(beginWord, 1));

        vector<bool> mark = vector<bool>(wordList.size(), false);

        pair<string, int> curPair;
        while (!searchQueue.empty()) {

            curPair = searchQueue.front();
            searchQueue.pop();


            for (int i = 0; i < wordList.size(); ++i) {
                // 判断与当前字符串是否只是一个编辑距离
                if (!mark[i] && diffCount(curPair.first, wordList[i]) <= 1) {
                    // 终止条件
                    if (wordList[i] == endWord)
                        return curPair.second + 1;

                    searchQueue.push(make_pair(wordList[i], curPair.second + 1));
                    mark[i] = true;
                }

            }
        }
        return res;
    }
};


int main() {
    Solution s;

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}