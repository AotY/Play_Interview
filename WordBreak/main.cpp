#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;


bool pairCompare(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    else
        return p1.first < p2.first;
}

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int lenDict = wordDict.size();
        int lenS = s.size();

        int minLen = INT_MAX;
        unordered_set<string> wordSet;

        for (int i = 0; i < lenDict; ++i) {
            wordSet.insert(wordDict[i]);
            minLen = min(minLen, (int) wordDict[i].size());
        }

        vector<pair<int, int>> segs;

        // word(i, j)
        for (int i = 0; i <= (lenS - minLen); ++i) {
            for (int j = i; j < lenS; ++j) {
                int curLen = j - i + 1;
                if (curLen >= minLen) {
                    string seg = s.substr(i, curLen);
                    if (wordSet.find(seg) != wordSet.end())
                        segs.push_back(make_pair(i, j));
                }
            }
        }

        // 寻找是否有解

        // 排序
        sort(segs.begin(), segs.end(), pairCompare);

        vector<bool> memo(lenS, false);
        for (int i = 0; i < segs.size(); ++i) {
            if (segs[i].first == 0)
                memo[segs[i].second] = true;
            else {
                if (memo[segs[i].first - 1]) {
                    if (segs[i].second == (lenS - 1))
                        return true;
                    else
                        memo[segs[i].second] = true;
                }
            }
        }


        return memo[lenS - 1];
    }
};

int main() {
    Solution s;
//    string str = "catsandog";
//    vector<string> wordDict = {{"cats"},
//                               {"dog"},
//                               {"sand"},
//                               {"and"},
//                               {"cat"}};
//    string str = "leetcode";
//
//    vector<string> wordDict = {{"leet"},
//                               {"code"}};
    string str = "a";

    vector<string> wordDict = {{"a"}};
    cout << s.wordBreak(str, wordDict) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}