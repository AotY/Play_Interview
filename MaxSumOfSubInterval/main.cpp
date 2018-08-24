#include <iostream>
#include <vector>

using namespace std;


// n^2   内存超
class Solution {
private:
    int max3(int a, int b, int c) {
        return max(max(a, b), c);
    }

public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        // 尝试用n^2 动态规划的方法解决
        vector<vector<int>> memo = vector<vector<int>>(n, vector<int>(n, INT_MIN));

        // 初始化
        for (int i = 0; i < n; ++i) {
            memo[i][i] = nums[i];
        }

        //
        for (int i = 0; i < n; i++) {
            for (int j = i+ 1; j < n; ++j) {
                memo[i][j] = memo[i][j-1] + nums[j];
            }
        }


        int res = memo[0][0];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, memo[i][j]);
            }
        }

        return res;
    }
};

int main() {

    Solution s;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << s.maxSubArray(nums) << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}