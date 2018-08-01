#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 记忆化搜索
class Solution {

private:
    vector<vector<int>> memo;

    int searchLcs(string &s1, string &s2, int m, int n) {
        if (m < 0 || n < 0)
            return 0;

        if (memo[m][n] != -1)
            return memo[m][n];

        int res = 0;
        if (s1[m] == s2[n])
            res += 1 + searchLcs(s1, s2, m - 1, n - 1);
        else {
            res = max(searchLcs(s1, s2, m, n - 1),
                      searchLcs(s1, s2, m - 1, n));
        }
        memo[m][n] = res;
        return res;
    }

public:
    int lcs(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();
        if (m == 0 || n == 0)
            return 0;

        memo = vector<vector<int>>(m, vector<int>(n, -1));
        int res = searchLcs(s1, s2, m - 1, n - 1);

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