#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:

    //
    bool searchPartition(const vector<int> &nums, vector<int> &groups, int index, int target) {
        if (index < 0)
            return true;

        int val = nums[index--];
        for (int i = 0; i < groups.size(); ++i) {
            if (groups[i] + val <= target) {
                groups[i] += val;

                if (searchPartition(nums, groups, index, target))
                    return true;

                groups[i] -= val;
            }

            if (groups[i] == 0)
                break;
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {

        int n = nums.size();

        if (n < k)
            return false;

        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }

        if (sum % k != 0)
            return false;


        sort(nums.begin(), nums.end()); // , greater<int>()


        int target = sum / k;

        int index = n - 1;
        while (index >= 0 && nums[index] == target) {
            index--;
            k--;
        }

        vector<int> groups(k);
        searchPartition(nums, groups, index, target);

        return true;

    }
};


int main() {
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    Solution s;
    cout << s.canPartitionKSubsets(nums, 4) << endl;
    return 0;
}