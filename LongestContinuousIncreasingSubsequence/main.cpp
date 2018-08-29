#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        if (n == 1)
            return 1;

        int res = 0;

        int curLen = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                curLen++;
            } else {
                res = max(res, curLen);

                curLen = 1;
            }
        }

        res = max(res, curLen);

        return res;
    }
};


int main() {

    vector<int> nums = {1, 3, 5, 4, 7};

    Solution s;
    cout << s.findLengthOfLCIS(nums) << endl;

    return 0;
}