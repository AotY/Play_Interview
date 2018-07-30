#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// 填1法改进
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        vector<int> memo(n);
        memo[0] = 1;
        // memo[i] 表示[0,...i]可以到达的位置
        int curPos = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == 0 || memo[i] == 0) //i < curPos ||
                continue;

            for (int j = 1; j <= nums[i]; ++j) {
                if (i + j < n) {
                    memo[i + j] = 1;
                    curPos = i + j;
                    if (curPos == (n - 1))
                        return true;
                }
            }

        }


        return memo[n - 1] == 1;

    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 5, 0, 0};
    cout << s.canJump(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}