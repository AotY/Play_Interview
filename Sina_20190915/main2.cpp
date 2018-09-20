#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;


// 找出连续的最长公共子序列，对的，就是这样。
class Solution {

public:
    int lcs(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();

        if (m == 0 || n == 0)
            return 0;

        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) { // 从1开始
            for (int j = 1; j <= n; j++) { //
                if (s1[i-1] == s2[j-1]) { // s1 的 i-1位置 与 s2的j -1位置是否相等
                    memo[i][j] = memo[i - 1][j - 1] + 1;
                } else {
                    memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
                }
            }
        }



        return memo[m][n];
    }
};

int main() {
//    string s1 = "abcd1e1f1";
//    string s2 = "bcd2e2f2";

    int m;
    int n;
    cin >> m >> n;

    string s1;
    string s2;

    cin >> s1;
    cin >> s2;


    Solution s;

    cout << s.lcs(s1, s2) << endl;

    return 0;
}

//abcd1e1f1
//bcd2e2f2

// 131342353f224
// fafq3434411233242