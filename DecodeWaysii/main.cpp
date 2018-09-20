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
        if (s[0] == '0')
            return 0;
        register int i = 1;
        register int n = s.size();
        long long tmp, f0 = 1, f1 = s[0] == '*' ? 9 : 1;
        for (; i < n; ++i) {
            tmp = f1;
            f1 = f1 * (s[i] == '0' ? 0 : s[i] == '*' ? 9 : 1);
            if (s[i - 1] == '1') {
                if (s[i] == '*') f1 += f0 * 10 - f0;
                else f1 += f0;
            } else if (s[i - 1] == '2') {
                if (s[i] == '*') f1 += f0 * 7 - f0;
                else f1 += f0 * (s[i] < '7' ? 1 : 0);
            } else if (s[i - 1] == '*') {
                if (s[i] == '*') f1 += f0 * 17 - 2 * f0;
                else f1 += f0 * (s[i] < '7' ? 2 : 1);
            }
            f0 = tmp;
            f1 %= mod;
        }
        return f1;
    }
};

int main() {
    return 0;
}