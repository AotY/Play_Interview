#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        int len = s.size();

        if (len == 0)
            return 0;

        if (len == 1)
            return 1;

        // memo[i][j]  表示 s[i..j] 是否为回文
        vector<vector<bool>> memo = vector<vector<bool>>(len, vector<bool>(len, false));


        // 基础状态： memo[i][j] = true;  memo[i][i+1] = s[i] == s[i+1]
        for (int i = 0; i < len; ++i) {
            memo[i][i] = true;
            res++;
            if (i + 1 < len) {
                if (s[i] == s[i + 1]) {
                    memo[i][i + 1] = true;
                    res++;
                }
            }
        }

        //  递推更长长度的回文串
        for (int k = 2; k < len; ++k) {
            for (int i = 0; i < len - k; ++i) {
                for (int j = i + k; j < len; j += k) {
                    // memo[i][j] = memo[i + 1][j-1] && s[i] == s[j]
                    if (memo[i + 1][j - 1] && s[i] == s[j]) {
                        memo[i][j] = true;
                        res++;
                    }

                }
            }
        }


        return res;
    }
};


int main() {
    Solution s;
    cout << s.countSubstrings("aabaa") << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}