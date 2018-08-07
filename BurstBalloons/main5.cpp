#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int divid(vector<int> &nums, vector<vector<int>> &dp, int low, int high) {
        if (low + 1 == high) return 0;
        if (dp[low][high] > 0) return dp[low][high];
        int ans = 0;
        for (int i = low + 1; i < high; i++)
            ans = max(ans, nums[low] * nums[i] * nums[high]
                           + divid(nums, dp, low, i) + divid(nums, dp, i, high));
        dp[low][high] = ans;
        return ans;
    }

    int maxCoins(vector<int> &nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        return divid(nums, dp, 0, nums.size() - 1);
    }

    int main() {
        vector<int> nums = {3, 1};

        Solution s;

        cout << s.maxCoins(nums) << endl;

        return 0;
    }