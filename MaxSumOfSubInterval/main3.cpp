#include <iostream>
#include <vector>

using namespace std;

// n
class Solution {

public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int right = 0;
        int curSum = 0;
        int maxSum = INT_MIN;
        while (right < n) {

            //  当right 小于0时，我们就得到了一个新的区间
            curSum += nums[right];

            maxSum = max(maxSum, curSum);
            if (curSum < 0)
                curSum = 0;

            right ++;

        }

        return maxSum;
    }
};

int main() {

    Solution s;
    vector<int> nums = {2, -1, 3};
    cout << s.maxSubArray(nums) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}