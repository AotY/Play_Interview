#include <iostream>
#include <vector>

using namespace std;

// main 超时，搜索太多
class Solution {

public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);


        n += 2;
        // 【
        vector<vector<int>> memo(n, vector<int>(n, 0));


        for (int i = n - 3; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                for (int k = i + 1; k < j; k++)
                    memo[i][j] = max(memo[i][j], nums[i] * nums[k] * nums[j] + memo[i][k] + memo[k][j]);
            }
        }

        return memo[0][n - 1];
    }
};

int main() {
    vector<int> nums = {3, 1, 5, 8};

    Solution s;

    cout << s.maxCoins(nums) << endl;

    return 0;
}