#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        // init
        vector<int> memo = vector<int>(n, INT_MIN);

        memo[0] = nums[0];
        bool lastLessZero = false;
        int lessZeroCount = 0;
        if (memo[0] < 0) {
            lastLessZero = true;
            lessZeroCount = 1;
        }

        for (int i = 1; i < n; ++i) {
            bool curLessZero = false;
            if (nums[i] < 0) {
                curLessZero = true;
                lessZeroCount++;
            }

            bool isAbs = false;
            if (lastLessZero && curLessZero && lessZeroCount == 2) {
                isAbs = true;
                lessZeroCount = 0;
            }
            lastLessZero = curLessZero;

            int mul1 = nums[i] * memo[i - 1];
            int mul2 = nums[i] * nums[i - 1];
            memo[i] = max(memo[i], mul1);
            memo[i] = max(memo[i], mul2);
//            if (mul < 0) {
//                if (isAbs)
//                    memo[i] = max(nums[i], mul * -1);
//                else
//                    memo[i] = mul;
//            } else {
//                memo[i] = max(nums[i], mul);
//            }
        }


        int res = memo[0];
        for (int i = 0; i < n; ++i) {
            res = max(res, memo[i]);
            res = max(res, nums[i]);
        }

        return res;

    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, -2, -9, -6};
    cout << s.maxProduct(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}