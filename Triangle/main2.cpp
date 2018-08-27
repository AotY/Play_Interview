#include <iostream>
#include <vector>


using namespace std;

//  尝试 搜索
// 超时
class Solution {


private:

    // memo[layer, index]
    vector<vector<int>> memo;

    int searchSum(const vector<vector<int>> &triangle, int layer, int index) {
        if (layer >= triangle.size())
            return 0;


        if (memo[layer][index] != INT_MAX)
            return memo[layer][index];


        int res = triangle[layer][index] + searchSum(triangle, layer + 1, index);

        if (index + 1 < triangle[layer].size()) {
            int res1 = triangle[layer][index + 1] + searchSum(triangle, layer + 1, index + 1);

            res = min(res, res1);
        }

        memo[layer][index] = res;

        return res;
    }

public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        if (n == 0)
            return 0;


        memo = vector<vector<int>>(n, vector<int>(n, INT_MAX));

        int res = searchSum(triangle, 0, 0);

        return res;
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