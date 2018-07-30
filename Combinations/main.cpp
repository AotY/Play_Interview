#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class Solution {
private:
    vector<vector<int>> results;

    void searchCombination(int n, int k, int start, vector<int> &c) {
        if (k == c.size()) {
            results.push_back(c);
            return;
        }

        // (n - (k - c.size()) + 1)
        for (int i = start; i <= n; ++i) {
            c.push_back(i);
            searchCombination(n, k, i + 1, c);
            c.pop_back();
        }

//        for (int i = start; i < (n - (k - c.size()) + 1); ++i) {
//            c.push_back(i);
//            searchCombination(n, k, i + 1, c);
//            c.pop_back();
//        }
        return;
    }


public:
    vector<vector<int>> combine(int n, int k) {
        if (n == 0 || k == 0)
            return results;

        // 只要求求次数时可以使用
//        if (k > (n / 2))
//            k = n - k;

        vector<int> c;
        searchCombination(n, k, 1, c);
        return results;
    }
};


int main() {
    Solution s;
    vector<vector<int>> results = s.combine(4, 3);
    for (auto result: results) {
        for (auto i: result) {
            cout << i << " ";
        }
        cout << endl;
    }

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}