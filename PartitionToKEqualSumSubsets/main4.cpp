#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if (sum % k != 0)
            return false;

        vector<int> book(nums.size(), false);

        return backtrack(nums, book, k, sum / k, 0, 0);
    }

    bool backtrack(vector<int> &nums, vector<int> &book, int k, int target, int idx, int subSum) {
        if (k == 0) {
            return true;
        }
        if (subSum == target)
            return backtrack(nums, book, k - 1, sum, 0, 0);

        if (subSum > target)
            return false;

        for (int i = idx; i < nums.size(); i++) {
            if (!book[i]) {
                book[i] = true;

                if (backtrack(nums, book, k, target, i + 1, subSum + nums[i]))
                    return true;

                book[i] = false;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    Solution s;
    cout << s.canPartitionKSubsets(nums, 4) << endl;
    return 0;
}