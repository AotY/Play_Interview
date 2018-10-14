#include <iostream>
#include <vector>


using namespace std;


class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n = nums.size();
            if (n == 0)
                throw invalid_argument("This array(nums) has no solution.");

            // 使用滑动窗口思路, left, right。[left, right]
            int left = 0;
            int right = -1;
            int curSum = 0;
            int res = 0;
            while (right < n) {

                if ((right + 1) < n ) {
                    curSum += nums[right + 1];
                }

                right ++;
            }


            return res;
        }
};

int main() {

    // vector<int> nums = {1, 1, 2, 3, 1, 5, 1};
    vector<int> nums = {1, 2, 3};
    int k = 3;
    Solution s;
    int res = s.subarraySum(nums, k);
    cout << res << endl;
    return 0;
}
