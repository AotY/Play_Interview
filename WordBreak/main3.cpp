#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int lenS = s.size();
        vector<bool> memo = vector<bool> (lenS + 1, false);
        memo[0] = true;

        for (int i = 1; i < memo.size(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                string seg = s.substr(j, i - j);
                if (memo[j] && wordSet.find(seg) != wordSet.end()) {
                    memo[i] = true;
                    break;
                }
            }
         }

        return memo[lenS];
    }
};

int main() {
    Solution s;
    string str = "catsanddog";
    vector<string> wordDict = {{"cats"},
                               {"dog"},
                               {"sand"},
                               {"and"},
                               {"cat"}};

//    string str = "leetcode";
//    vector<string> wordDict = {{"leet"},
//                               {"code"}};

//    string str = "a";
//    vector<string> wordDict = {{"a"}};

    cout << s.wordBreak(str, wordDict) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}