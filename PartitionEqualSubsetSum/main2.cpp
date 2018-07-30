#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 使用动态规划思想

class Solution {

public:

    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        } // 如果不能被2整除

        int findSum = sum / 2;

        vector<bool> memo(findSum + 1, false);

        // 第一步
        for (int j = 0; j <= findSum; ++j) {
            memo[j] = (j == nums[0]) ;
        }

        for (int i = 1; i < nums.size(); ++i) {
            for (int j = findSum; j >= nums[i]; j--) {
                memo[j] = (memo[j] || memo[j - nums[i]]);
            }
        }

        return memo[findSum];
    }

};

int main() {
    Solution s;
    vector<int> nums = {1, 5, 5, 11};
    cout << s.canPartition(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}