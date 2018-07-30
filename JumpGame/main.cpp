#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


// 可以只对0位置进行判断
// 标1法，速度太慢
// 搜索法
// 动态规划法
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return true;

        vector<int> markArr(n, 0);
        markArr[0] = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (markArr[i] && nums[i] > 0) {
                for (int j = 1; j <= nums[i]; ++j) {
                    if (i + j < n && markArr[i + j] != 1)
                        markArr[i + j] = 1;
                    if (markArr[n - 1])
                        return true;

                }
            }
        }

        return markArr[n - 1] != 0;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << s.canJump(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}