#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 找出连续的最长公共子序列，对的，就是这样。
class Solution {

public:
    int lcs(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();
        if (m == 0 || n == 0)
            return 0;

        vector<vector<int>> memo(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j]) {
                    memo[i][j] += 1;
                    if (i - 1 >= 0 && j - 1 >= 0)
                        memo[i][j] += memo[i - 1][j - 1];
                }
            }
        }
//        int res = memo[m-1][n-1];

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, memo[i][j]);
            }
        }

        return res;
    }
};


int main() {
    string s1 = "abacdfgdcaba";
    string s2 = "abacdgfdcaba";

    Solution s;
    cout << s.lcs(s1, s2) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}