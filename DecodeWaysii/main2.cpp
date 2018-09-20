#include <iostream>
#include <string>

using namespace std;

static auto x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

#define mod 1000000007

class Solution {
public:
    int numDecodings(string s) {
        int length = s.length();
        if (!length) return 0;

        int c = 1e9 + 7;

        vector<long> dp(length + 1, 1);

        if (length >= 1) {
            if (s[0] == '*') {
                dp[1] = 9;
            } else if (s[0] == '0') {
                dp[1] = 0;
            } else {
                dp[1] = 1;
            }
        }

        for (int i = 2; i <= length; i++) {
            if (s[i - 1] == '*') {
                dp[i] = 9 * dp[i - 1] % c;
            } else if (s[i - 1] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i - 1];
            }

            if (s[i - 2] == '*') {
                if (s[i - 1] == '*') {
                    dp[i] = (dp[i] + 15 * dp[i - 2] % c) % c;
                } else if (s[i - 1] >= '0' && s[i - 1] <= '6') {
                    dp[i] = (dp[i] + 2 * dp[i - 2] % c) % c;
                } else {
                    dp[i] = (dp[i] + dp[i - 2]) % c;
                }
            } else if (s[i - 2] == '1') {
                if (s[i - 1] == '*') {
                    dp[i] = (dp[i] + 9 * dp[i - 2] % c) % c;
                } else {
                    dp[i] = (dp[i] + dp[i - 2]) % c;
                }
            } else if (s[i - 2] == '2') {
                if (s[i - 1] == '*') {
                    dp[i] = (dp[i] + 6 * dp[i - 2] % c) % c;
                } else if (s[i - 1] >= '0' && s[i - 1] <= '6') {
                    dp[i] = (dp[i] + dp[i - 2]) % c;
                }
            }
        }

        return (int) dp[length];
    }
};

int main() {
    return 0;
}