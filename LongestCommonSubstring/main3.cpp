#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 动态规划
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
                } else {
                    if (i - 1 >= 0)
                        memo[i][j] += memo[i - 1][j];
                    if (j - 1 >= 0)
                        memo[i][j] = max(memo[i][j], memo[i][j - 1]);
                }
            }
        }
        int res = memo[m - 1][n - 1];

        return res;
    }
};


int main() {
    string s1 = "ABAB";
    string s2 = "BABA";

    Solution s;
    cout << s.lcs(s1, s2) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}