#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class Solution {
private:
    vector<vector<int>> memo;

    bool searchSum(vector<int>& nums, int findSum, int start) {
        if (findSum < 0 || start >= nums.size())
            return false;

        if (findSum == 0) {
            return true;
        }

        // 改为记忆化搜索
        if (memo[start][findSum] != -1)
            return memo[start][findSum] == 1;

        memo[start][findSum] = (searchSum(nums, findSum, start + 1) ||
                                searchSum(nums, findSum - nums[start], start + 1)) ? 1 : 0;

        return memo[start][findSum] == 1;
    }

public:

    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false; // 如果不能被2整除

        int findSum = sum / 2;
        memo = vector<vector<int>>(nums.size(), vector<int>(findSum + 1, -1));
        return searchSum(nums, findSum, 0);
    }

};

int main() {
    Solution s;
    vector<int> nums = {1, 5, 5, 11};
    cout << s.canPartitino(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}