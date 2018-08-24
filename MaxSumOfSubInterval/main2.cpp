#include <iostream>
#include <vector>

using namespace std;

// n^2
class Solution {
private:
    int max3(int a, int b, int c) {
        return max(max(a, b), c);
    }


public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        vector<int> memo = vector<int>(n, INT_MIN);

        int res = INT_MIN;

        //
        for (int i = 0; i < n; i++) {
            memo[i] = nums[i];
            for (int j = i + 1; j < n; ++j) {
                memo[j] = nums[j] + memo[j - 1];
                res = max(res, memo[j]);
            }
        }

        for (int i = 0; i < n; ++i) {
            res = max(res, nums[i]);
        }

        return res;
    }
};

int main() {

    Solution s;
    vector<int> nums = {4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(nums) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}