#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % 2)
            return false;

        sum = sum / 2;

        sort(nums.begin(), nums.end());

        bool result[sum + 1];

        for (int i = 0; i < sum + 1; i++)
            result[i] = false;

        result[0] = true;

        int curSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int t = (curSum + nums[i]) < sum ? (curSum + nums[i]) : sum;
            for (int j = t; j >= nums[i]; j--) {
                result[j] = result[j] || result[j - nums[i]];
            }
            if (result[sum])
                return true;
            curSum += nums[i];
        }
        return result[sum];
    }
};


int main() {
    Solution s;
    vector<int> nums = {3, 3, 3, 4, 5};
    cout << s.canPartition(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}