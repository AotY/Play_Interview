#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool PredictTheWinner(vector<int> &nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }

        for (int det = 1; det < n; det++) {
            for (int i = 0; i + det < n; i++) {
                dp[i][i + det] =
                        max(nums[i] - dp[i + 1][i + det], nums[i + det] - dp[i][i + det - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};

int main() {

    Solution s;
    vector<int> nums = {1, 3, 7, 2};
    cout << s.PredictTheWinner(nums) << endl;

    return 0;
}






