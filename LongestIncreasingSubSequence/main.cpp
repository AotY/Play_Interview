#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {

    int max3(int a, int b, int c) {
        return max(max(a, b), c);
    }

private:

    int tryLIS(vector<int> &nums, int start, int end, int lastNum, int count) {

        if (start > (end - 1))
            return count;

        int result = 0;
        for (int i = start; i < end; ++i) {
            //大于
            if (nums[i] > lastNum)
                result = max3(result,
                              tryLIS(nums, i + 1, end, nums[i], count + 1),
                              tryLIS(nums, i + 1, end, lastNum, count));
            else
                //  小于
                result = max3(result,
                              tryLIS(nums, i + 1, end, lastNum, count),
                              tryLIS(nums, i + 1, end, nums[i], 1));
        }

        return result;
    }

public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return 1;

        // find LIS in [0, nums.size() -1]
        return tryLIS(nums, 0, nums.size(), -99999, 0);
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, 7, 101};
    cout << s.lengthOfLIS(nums) << endl;

    return 0;
}