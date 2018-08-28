#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.size();
        vector<int> dp(n, 1);
        for (int j = 1; j < n; j++) {

            int len = 0;
            for (int i = j - 1; i >= 0; i--) {
                int t = dp[i];
                if (s[i] == s[j]) {
                    dp[i] = len + 2;
                }
                len = max(len, t);
            }

        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = max(ans, dp[i]);
        return ans;
    }
};

int main() {
    Solution s;

    cout << s.longestPalindromeSubseq("bbbab") << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}