#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:

    vector<int> memo;

    int tryRobbing(vector<int> &nums, int start, int end) {
        if (nums.size() == 0)
            return 0;

        if (start > end)
            return 0;

        if (memo[start] != -1)
            return memo[start];

        int result = max(nums[start] + tryRobbing(nums, start + 2, end), tryRobbing(nums, start + 1, end));

        memo[start] = result;

        return result;
    }

public:
    int rob(vector<int> &nums) {
        memo = vector<int> (nums.size(), -1);
        // try robbing in [0, nums.size()-1]
        return tryRobbing(nums, 0, nums.size() - 1);
    }
};


int main() {

    Solution s;
    vector<int> nums = {1, 2, 3, 1, 5};
    cout << s.rob(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}