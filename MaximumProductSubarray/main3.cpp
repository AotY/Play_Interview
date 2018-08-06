#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));

        dp[0][0] = nums[0];
        dp[0][1] = nums[0];

        int ret = dp[0][0];

        // 这个思路可以的
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                dp[i][0] = max(dp[i - 1][1] * nums[i], nums[i]);
                dp[i][1] = min(dp[i - 1][0] * nums[i], nums[i]);
            } else {
                dp[i][0] = max(dp[i - 1][0] * nums[i], nums[i]);
                dp[i][1] = min(dp[i - 1][1] * nums[i], nums[i]);
            }
            if (ret < dp[i][0]) {
                ret = dp[i][0];
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-2, 3, -2, 4};
    cout << s.maxProduct(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}