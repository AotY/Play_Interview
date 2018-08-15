#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {

        int n = nums.size();

        if (n < k)
            return false;

        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }

        int target = sum / k;

        if (sum % k != 0 || nums[n- 1] > target)
            return false;

        sort(nums.begin(), nums.end()); // , greater<int>()


        int twiceN = 1 << n;

        vector<bool> memo = vector<bool>(twiceN);
        memo[0] = true;

        vector<int> total = vector<int> (twiceN);


        for (int state = 0; state < twiceN; ++state) {
            if (!memo[state])
                continue;

            for (int i = 0; i < n; ++i) {
                int future = state | (1 << i);

                if (state != future && !memo[future]) {
                    if (nums[i] <= target - (total[state] % target)) {
                        memo[future] = true;
                        total[future] = total[state] + nums[i];
                    } else
                        break;
                }
            }

        }

        return memo[twiceN - 1];

    }
};


int main() {
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    Solution s;
    cout << s.canPartitionKSubsets(nums, 4) << endl;
    return 0;
}