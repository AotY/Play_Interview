#include <iostream>
#include <string>

using namespace std;

// 时间超时
class Solution {
private:
    bool isPalindrome(string sub) {
        int len = sub.size();

        int mid = len >> 1;
        for (int i = 0; i < mid; ++i) {
            if (sub[i] != sub[len - i - 1])
                return false;

        }

        return true;
    }

public:
    string longestPalindrome(string s) {
        int len = s.size();
        if (len == 0 || len == 1) {
            return s;
        }

        int charArr[256] = {0};

        int maxLen = 0;
        string sub = "";
        string maxSub = "";
        int left = 0;
        int right = 0;

        for (int i = 0; i < len; ) {

            if (charArr[s[i]] > 1 ) {
                if (isPalindrome(sub)) {
                    //  是回文
                    charArr[s[left++]] --;
                } else {
                   //  不是回文

                }

            } else {
                charArr[s[i]] += 1;
                sub += s[i];
            }
        }

        return maxSub;
    }
};

// 暴力解法
int main() {
    Solution s;
    cout << s.longestPalindrome("aaabaa") << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}