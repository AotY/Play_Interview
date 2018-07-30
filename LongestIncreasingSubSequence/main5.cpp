#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int upperbound(int dp[], int x, int left, int right) {
        if (x > dp[right])
            return right + 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (x <= dp[mid])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    int lengthOfLIS(vector<int> &nums) {//O(nlogn)
        int n = nums.size();
        if (!n)
            return 0;

        int dp[n], l = 0;
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int pos = upperbound(dp, nums[i], 0, l);
            dp[pos] = nums[i];
            l = max(l, pos);
        }
        return l + 1;
    }

};

int main() {
    Solution s;
    vector<int> nums = {2,5, 3,7};

    cout << s.lengthOfLIS(nums) << endl;


    return 0;
}