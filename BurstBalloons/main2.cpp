#include <iostream>
#include <vector>

using namespace std;

// main 超时，搜索太多
class Solution {
private:
    vector<bool> mark;
    vector<vector<int>> memo;

    int searchCoin(vector<int> &nums, int choose, int curCoin) {
        if (choose == -1 || choose == nums.size())
            return curCoin;

        int tmpIndex1;
        int tmpIndex2;
        int tmpValue1;
        int tmpValue2;

        //
        tmpIndex1 = choose + 1;
        while (tmpIndex1 < nums.size() && mark[tmpIndex1])
            tmpIndex1++;
        if (tmpIndex1 == nums.size())
            tmpValue1 = 1;
        else
            tmpValue1 = nums[tmpIndex1];

        //
        tmpIndex2 = choose - 1;
        while (tmpIndex2 >= 0 && mark[tmpIndex2])
            tmpIndex2--;
        if (tmpIndex2 == -1)
            tmpValue2 = 1;
        else
            tmpValue2 = nums[tmpIndex2];

        if (memo[tmpIndex1 + 1][tmpIndex2 + 1] != -1)
            return memo[tmpIndex1 + 1][tmpIndex2 + 1];
        int tmpCoin = curCoin;
        if (choose == 0) {
            tmpCoin += nums[choose] * tmpValue1;
        } else if (choose == nums.size() - 1) {
            tmpCoin += nums[choose] * tmpValue2;
        } else {
            tmpCoin += tmpValue1 * nums[choose] * tmpValue2;
        }


        int res = tmpCoin;

        for (int i = 0; i < nums.size(); ++i) {
            if (!mark[i]) {
                mark[i] = true;
                res = max(res, searchCoin(nums, i, tmpCoin));
                mark[i] = false;
            }
        }

        memo[tmpIndex1 + 1][tmpIndex2 + 1] = res;
        return res;
    }

public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int res = 0;
        mark = vector<bool>(n, false);

        memo = vector<vector<int>>(n + 2, vector<int>(n + 2, -1));

        for (int i = 0; i < n; ++i) {
            mark[i] = true;
            res = max(res, searchCoin(nums, i, 0));
            mark[i] = false;
        }

        return res;
    }
};

int main() {
    vector<int> nums = {3, 1, 5, 8};

    Solution s;

    cout << s.maxCoins(nums) << endl;

    return 0;
}