#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:

    bool tryPartition(vector<int> &partitions, const vector<int> &nums, int index, int target) {

        // 搜索结束
        if (index < 0)
            return true;

        // 尝试使用 nums[index]的值
        int curVal = nums[index];

        // 尝试去填充partitions中的每一个位置
        for (int i = 0; i < partitions.size(); ++i) {
            if (partitions[i] + curVal <= target) {
                partitions[i] += curVal;
                // 搜索下一个位置填充
                bool res = tryPartition(partitions, nums, index - 1, target);
                if (res)
                    return true;

                partitions[i] -= curVal;
            }


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

        sort(nums.begin(), nums.end());

        int target = sum / k;

        if (sum % k != 0 || nums[n - 1] > target)
            return false;


        // 寻找要划分的个数，排除nums[i] == target的位置
        int index = n - 1;


        while (nums[index] == target && index > 0) {
            index--;
            k--;
        }

        vector<int> partitions = vector<int>(k, 0);

        // 从后往前搜索
        bool res = tryPartition(partitions, nums, index, target);

        return res;

    }
};


int main() {
    vector<int> nums = {7, 2, 2, 2, 2, 2, 2, 2, 3}; // 7
    Solution s;
    cout << s.canPartitionKSubsets(nums, 3) << endl;
    return 0;
}