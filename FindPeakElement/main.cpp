#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int n = nums.size();
        if (n == 0 || n == 1)
            return 0;

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                if (nums[i] > nums[i + 1])
                    return i;
            } else if (i == (n - 1)) {
                if (nums[i] > nums[i - 1])
                    return i;
            } else {
                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                    return i;
            }
        }
        return -1;
    }

};

int main() {

    Solution s;
    vector<int> nums = {1,2,3,1};
    cout<<s.findPeakElement(nums)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}