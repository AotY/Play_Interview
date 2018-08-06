#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        // init
        vector<set<int>> memo = vector<set<int>>(n, set<int>());

        memo[0].insert(nums[0]);
        int res = nums[0];
        for (int i = 1; i < n; ++i) {

            for (set<int>::iterator it = memo[i - 1].begin(); it != memo[i - 1].end(); it++) {
                memo[i].insert((*it) * nums[i]);
                res = max(res, (*it) * nums[i]);
            }
            memo[i].insert(nums[i] * nums[i - 1]);
            memo[i].insert(nums[i]);
            res = max(res, nums[i] * nums[i - 1]);
            res = max(res, nums[i]);
        }
        return res;

    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, -2, 4};
    cout << s.maxProduct(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}