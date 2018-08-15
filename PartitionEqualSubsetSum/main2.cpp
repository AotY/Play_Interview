#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 使用动态规划思想


static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


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

        vector<bool> memo(findSum + 1);

        // 第一步，初始化，是否只考虑第一个元素就能填充满
        for (int i = 0; i <= findSum; ++i) {
            memo[i] = (i == nums[0]) ;
        }

        //
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = findSum; j >= nums[i]; j--) {
                memo[j] = (memo[j] || memo[j - nums[i]]);
            }
            if (memo[findSum])
                break;
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