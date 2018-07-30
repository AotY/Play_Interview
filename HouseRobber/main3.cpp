#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    int rob(vector<int> &nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        if (n == 1)
            return nums[0];

        vector<int> memo(n, -1);

        // try robbing in [0, nums.size()-1]
        memo[0] = nums[0];
//
//        if (n == 2)
//            return max(memo[0], memo[1]);

        for (int i = 1; i < n; ++i) {
            memo[i] = memo[i - 1];
            if (i - 2 >= 0)
                memo[i] = max(memo[i], nums[i] + memo[i - 2]);
            else
                memo[i] = max(memo[i], nums[i]);
        }

        return memo[n - 1];
    }
};


int main() {

    Solution s;
    vector<int> nums = {1, 2};
    cout << s.rob(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}