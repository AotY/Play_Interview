#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    // Transform S into T.
    // For example, S = "abba", T = "^#a#b#b#a#$".
    // ^ and $ signs are sentinels appended to each end to avoid bounds checking
    string preProcess(string s) {
        int n = s.length();
        if (n == 0)
            return "^$";
        string ret = "^";
        for (int i = 0; i < n; i++)
            ret += "#" + s.substr(i, 1);
        ret += "#$";
        return ret;
    }

    string longestPalindrome(string s) {
        string T = preProcess(s);
        int n = T.length();

//        int *P = new int[n];
        int P[50] = {0};
//        for (int i = 0; i < n; ++i) {
//            P[i] = 0;
//        }

        int C = 0, R = 0;

        int curR = 0;
        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * C - i; // equals to i' = C - (i-C)

            if ( R > i)
                P[i] = min(R - i, P[i_mirror]);
            else
                P[i] = 0;
//            P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;

            // Attempt to expand palindrome centered at i
            // Ti-d … Ti+d
            int right = i + 1 + P[i];
            int left = i - 1 - P[i];
            while (T[left] == T[right]) {
                P[i]++;
                right ++ ;
                left --;
            }

            // If palindrome centered at i expand past R,
            // adjust center based on expanded palindrome.
            curR = i + P[i];
            if (curR > R) {
                C = i; // center point
                R = curR; // right edge
            }
        }


        // Find the maximum element in P.
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n - 1; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
//        delete[] P;

        return s.substr((centerIndex - maxLen - 1) / 2, maxLen);
    }
};


int main() {
    Solution s;
    cout << s.longestPalindrome("abcb") << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}