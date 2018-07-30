#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

class Solution {
public:
    void backtrace(vector<string> &ans, string &cur, int lb, int rb) {

        if (lb < 0 && rb != 0)
            return;

        else if (lb == 0 && rb == 0) {
            ans.push_back(cur);
            return;
        }

        cur.push_back('(');
        backtrace(ans, cur, lb - 1, rb);
        cur.pop_back();
        if (rb > lb) { // 这句可以提高效率
            cur.push_back(')');
            backtrace(ans, cur, lb, rb - 1);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        backtrace(ans, cur, n, n);
        return ans;
    }
};

int main() {

    Solution s;
    vector<string> results = s.generateParenthesis(3);

    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}