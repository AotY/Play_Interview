#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);

        n += 2;

        vector<vector<int>> memo(n, vector<int>(n, 0));


        for (int k = 2; k < n; ++k) {
            for (int left = 0; left < n - k; ++left) {
                int right = left + k;
                for (int i = left + 1; i < right; ++i) {
                    int curCoin = nums[left] * nums[i] * nums[right];
                    int lastCurCoin = memo[left][i] + memo[i][right];
                    memo[left][right] = max(memo[left][right], curCoin + lastCurCoin);
                }
            }
        }
        return memo[0][n - 1];
    }

};


int main() {
    vector<int> nums = {3, 1};

    Solution s;

    cout << s.maxCoins(nums) << endl;

    return 0;
}