#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// Expand Around Center
// https://leetcode.com/articles/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = (int) s.length();

        int left = 0;
        int right = 0;

        int leftRes = 0;
        int maxLen = 0;

        int i = 0;
        while (i < len) {
            left = i;
            right = i;

            while (right + 1 < len && s[right] == s[right + 1])
                ++right;

            i = right + 1;

            while (left >= 0 && right < len && s[left] == s[right]) {
                --left;
                ++right;
            }

            if (maxLen < right - left - 1) {
                leftRes = left + 1;
                maxLen = right - left - 1;
            }
        }
        return s.substr(leftRes, maxLen);
    }

};

int main() {
    Solution s;
    cout << s.longestPalindrome("bbd") << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}