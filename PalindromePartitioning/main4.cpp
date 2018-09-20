#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isTarget(string s) {
        if (s.size() == 0 || s.size() == 1)
            return true;
        for (int i = 0; i < s.size() / 2; ++i)
            if (s[i] != s[s.size() - 1 - i])
                return false;
        return true;
    }

    vector<vector<string>> partition(string s) {
        if (s.size() == 0)
            return vector<vector<string>>();
        vector<vector<string>> res;
        vector<string> tmp;
        dfs(s, 0, tmp, res);
        return res;
    }

    void dfs(string &s, int start, vector<string> &tmp, vector<vector<string>> &res) {
        if (start == s.size()) {
            res.push_back(tmp);
            return;
        }

        for (int i = start + 1; i <= s.size(); ++i) {
            string sub = s.substr(start, i - start);
            if (isTarget(sub)) {
                tmp.push_back(sub);
                dfs(s, i, tmp, res);
                tmp.pop_back();
            }
        }
    }


};

int main() {
    Solution s;
    vector<vector<string>> results = s.partition("aab");

    for (int i = 0; i < results.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < results[i].size(); ++j) {
            cout << results[i][j] << ", ";
        }
        cout << "], ";
        cout << endl;
    }

    return 0;
}