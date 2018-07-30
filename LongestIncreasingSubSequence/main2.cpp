#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {

private:
    vector<vector<int>> memo;

    int tryLIS(vector<int> &nums, int index) {

        int result = 1;
        for (int i = 0; i <= index - 1; ++i) {
            if (nums[index] > nums[i])
                result = max(result, 1 + tryLIS(nums, i));
        }

        return result;
    }

public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        memo = vector<vector<int>>(n, vector<int>(n, -1));

        // find LIS in [0, nums.size() -1]
        int result = 1;
        for (int i = 0; i < n; ++i) {
            // 以 nums[i]为结尾的最大上升序列
            result = max(result, tryLIS(nums, i));
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1};

    cout << s.lengthOfLIS(nums) << endl;


    return 0;
}