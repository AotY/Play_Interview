#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> memo(n, 1);

//        memo[0] = 1;
        // find LIS in [0, nums.size() -1]
        for (int i = 1; i < n; ++i) {
            // 以 nums[i]为结尾的最大上升序列
            for (int j = 0; j <= i - 1; ++j) {
                if (nums[i] > nums[j])
                    memo[i] = max(memo[i], 1 + memo[j]);
            }
        }

        int result = memo[0];
        for (int k = 1; k < n; ++k) {
            if (memo[k] > result)
                result = memo[k];
        }
        return result;
//        sort(memo.begin(), memo.end());
//        return memo[n - 1];

    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};

    cout << s.lengthOfLIS(nums) << endl;


    return 0;
}