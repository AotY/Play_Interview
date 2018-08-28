#include <iostream>
#include <string>
#include <vector>

using namespace std;

//动态规划 memo[i][j]

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        if (len == 0)
            return 0;

        if (len == 1)
            return 1;


        // memo[i][j] s[i .. j]的最长回文子序列
        vector<vector<int>> memo = vector<vector<int>>(len, vector<int>(len, 0));

        // 初始化 memo[i][i] = 1
        for (int i = 0; i < len; ++i) {
            memo[i][i] = 1;
        }

        // if s[i] == s[j], then memo[i][j] = memo[i+1][j-1] + 2
        // otherwise, memo[i][j] = max(memo[i+1][j], memo[i][j-1])
        for (int i = len - 2; i >= 0; --i) {
            for (int j = i + 1; j < len; ++j) {

                if (s[i] == s[j]) {
                    memo[i][j] = memo[i + 1][j - 1] + 2;
                } else {

                    memo[i][j] = max(memo[i + 1][j], memo[i][j - 1]);
                }


            }
        }

        return memo[0][len - 1];
    }
};


int main() {
    Solution s;

    cout << s.longestPalindromeSubseq("bbbab") << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}