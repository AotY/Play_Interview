#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 动态规划法
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        vector<int> memo(n, 0);
        memo[0] = nums[0];

        for (int i = 1; i < n - 1; ++i) {
            if (memo[i - 1] >= i)
                memo[i] = max(memo[i - 1], nums[i] + i); //
        }

        return memo[n - 2] >= (n - 1);

    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 0};
    cout << s.canJump(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}