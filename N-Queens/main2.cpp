#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>


using namespace std;

class Solution {

private:
    void dp(vector<vector<string>> &ans,
            vector<bool> &cols,
            vector<bool> &xandys,
            vector<bool> &xplusys, int start, int n, vector<int> &tmp) {
        if (tmp.size() >= n) {
            vector<string> temps(n, string(n, '.'));
            for (int i = 0; i < tmp.size(); i++) {
                int x = tmp[i] / n;
                int y = tmp[i] % n;
                temps[x][y] = 'Q';
            }
            ans.push_back(temps);
            return;
        }

        if (start >= n) return;


        for (int i = 0; i < n; i++) {
            int x = start;
            int y = i;

            if (cols[y]) {
                continue;
            }

            if (xandys[x + y]) continue;

            if (xplusys[x - y + n - 1]) continue;

            cols[y] = true;
            xandys[x + y] = true;
            xplusys[x - y + n - 1] = true;
            tmp.push_back(start * n + i);

            dp(ans, cols, xandys, xplusys, start + 1, n, tmp);

            cols[y] = false;
            xandys[x + y] = false;
            xplusys[x - y + n - 1] = false;
            tmp.pop_back();
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<bool> cols(n, false);
        vector<bool> xandys(2 * n - 1, false);
        vector<bool> xplusys(2 * n - 1, false);
        vector<int> tmp;
        dp(ans, cols, xandys, xplusys, 0, n, tmp);
        return ans;
    }


};

int main() {
    Solution s;

    int n = 5;
    vector<vector<string>> results = s.solveNQueens(n);

    for (int k = 0; k < results.size(); ++k) {

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << results[k][i][j];
            }

            cout << endl;
        }

        cout << endl;
        cout << endl;
    }

    return 0;
}