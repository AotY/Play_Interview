#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 这个方法不行，因为要考虑子串不连续的情况

class Solution {
private:
    int searchPalindrome(const string &s, int left, int right) {
        int res = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {

            if (left == right)
                res ++;
            else
                res += 2;

            left --;
            right ++;

        }

        return res;
    }

public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        if (len == 0)
            return 0;

        if (len == 1)
            return 1;

        int res = 0;

        // 求最长的回文子串的长度 （子串可以不连续）

        for (int i = 0; i < len; ++i) {
            // 考虑长度为奇数的情况
            res = max(res, searchPalindrome(s, i, i)) ;

            if (i + 1 < len) // 考虑长度为偶数的情况
                res = max(res, searchPalindrome(s, i, i + 1));
        }

        return res;
    }
};


int main() {
    Solution s;

    cout << s.longestPalindromeSubseq("bbbab") << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}