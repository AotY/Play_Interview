#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// 怎么改进呢 ？ 动态规划算法
// https://leetcode.com/articles/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0 || len == 1)
            return s;

        vector<vector<bool>> memo(len, vector<bool>(len, false));

        int maxLen = 1;
        int maxI = 0;


        for (int i = 0; i < len; ++i) {
            memo[i][i] = true;
            if (i + 1 < len) {
                memo[i][i + 1] = s[i] == s[i + 1];
                if (memo[i][i + 1]) {
                    maxI = i;
                    maxLen = 2;
                }
            }
        }

        for (int i = len - 1; i >= 0; --i) {
            for (int j = i + 2; j < len; ++j) {
                memo[i][j] = memo[i + 1][j - 1] && s[i] == s[j];
                if (memo[i][j]) {
                    int curLen = ((j - i) + 1);
                    if (curLen > maxLen) {
                        maxI = i;
                        maxLen = curLen;
                    }
                }

            }
        }
        return s.substr(maxI, maxLen);
    }
};


int main() {
    Solution s;
    cout << s.longestPalindrome("bbd") << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}