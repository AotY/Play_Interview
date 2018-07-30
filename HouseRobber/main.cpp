#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
    int tryRobbing(vector<int> &nums, int start, int end) {
        if (nums.size() == 0)
            return 0;

        if (start > end)
            return 0;

        int result = max(nums[start] + tryRobbing(nums, start + 2, end), tryRobbing(nums, start + 1, end));

        return result;
    }

public:
    int rob(vector<int> &nums) {
        // try robbing in [0, nums.size()-1]
        return tryRobbing(nums, 0, nums.size() - 1);
    }
};


int main() {

    Solution s;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << s.rob(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}