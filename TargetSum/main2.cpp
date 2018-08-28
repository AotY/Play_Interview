#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


// nums总和（全为+号）为sum, 全为-号为-sum,
// 将nums[i]的符号由-变正，和增加了 2*nums[i]
// 和由-sum到S增加了（S+sum），需要变换n个数，这n个数sum的2倍等于（S+sum）

class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }

        int target = sum + S;

        if (S > sum || S < -sum || target % 2)
            return 0;

        //target /= 2;

        // 从nums中找出和为target的数字组合, 和为0的时候有一种组合
        vector<int> dp(sum + 1, 0);

        dp[0] = 1;

        // 这里是01背包问题的一维数组解法.

        // dp(i,j) = dp(i−1,j) + dp(i−1, j−nums[i])；
        // dp(i,j) 表示考虑前i个数，表达式的值为j的方法总数
        for (int i = 0; i < nums.size(); i++)
            for (int j = sum; j >= nums[i]; j--)
                dp[j] += dp[j - nums[i]];

        return dp[target / 2];
    }
};

int main() {

    Solution s;

    vector<int> nums = {1, 1, 1, 1, 1};
    int S = 3;
    cout << s.findTargetSumWays(nums, S) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}