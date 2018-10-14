#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
  
        int n = nums.size();

        int left = 0;
        int right = -1;

        int res = n + 1;

        int curSum = 0;
        while (left < n) {
            if (right + 1 < n && curSum < s) {
                curSum += nums[++right];
            } else {
                // curSum >= s, and right + 1 > n
                curSum -= nums[left++];
            }
            
            if (curSum >= s)
                res = min(res, right - left + 1) ;
        }

        if (res == n + 1)
            return 0;

        return res;
    }
};


int main() {

    int s = 7;
    vector<int> nums = {2,3,1,2,4,3};
    Solution solution;
    int res = solution.minSubArrayLen(s, nums);
    cout << res << endl;
}
