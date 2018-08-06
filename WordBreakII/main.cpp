#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
private:
    vector<string> res;

    void backTracking(const unordered_set<string> &wordSet, const string &s, int index,
                      string &cur) {

        if (index > s.size() - 1) {
            res.push_back(cur);
            return;
        }


        for (int i = index; i < s.size(); ++i) {
            string seg = s.substr(index, i - index + 1);
            int curLen = cur.size();
            if (wordSet.find(seg) != wordSet.end()) {
                cur += seg;
                if (i != s.size() - 1)
                    cur += " ";
                backTracking(wordSet, s, i + 1, cur);

                cur = cur.substr(0, curLen);
            }
        }
        return;
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        int sLen = s.size();
        vector<bool> memo = vector<bool>(sLen + 1, false);
        memo[0] = true;

        // dp
        for (int i = 1; i < memo.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (memo[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    memo[i] = true;
                    break;
                }
            }
        }

        if (!memo[sLen])
            return res;

        // bt
        string cur = "";
        backTracking(wordSet, s, 0, cur);

        return res;
    }
};


int main() {

    Solution s;
    string str = "a";
    vector<string> wordDict = {{"a"}};

    vector<string> res = s.wordBreak(str, wordDict);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
