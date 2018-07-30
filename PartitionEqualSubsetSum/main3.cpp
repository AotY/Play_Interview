#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 使用动态规划思想,

class Solution {

private:
    bool search(vector<int> &nums, int findSum, int index) {
        // [left, right]
        if (findSum == nums[index])
            return true;

        if (findSum < nums[index])
            return false;
        // 确实，使用 || ，只要运算前面的部分为真就好了。 一个小trick。
        return search(nums, findSum - nums[index], index + 1) || search(nums, findSum, index + 1);
    }

public:

    bool canPartition(vector<int> &nums) {

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        } // 如果不能被2整除

        int findSum = sum >> 1;


        // greater: 从小到大， 是可以提高效率
        sort(nums.rbegin(), nums.rend());

        return search(nums, findSum, 0);
    }

};

int main() {
    Solution s;
    vector<int> nums = {3, 3, 3, 4, 5};
    cout << s.canPartition(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}