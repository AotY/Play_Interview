#include <iostream>
#include <vector>


using namespace std;

// 动态规划

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<int> res = triangle.back();

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                res[j] = min(res[j], res[j + 1]) + triangle[i][j];
            }
        }
        return res[0];
    }
};

int main() {
    Solution s;

    vector<vector<int>> triangle = {
            {-1},
            {-2, -3}
    };

    cout << s.minimumTotal(triangle) << endl;
    return 0;
}