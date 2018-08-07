#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<bool> mark;

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

        int res = 0;
        if (choose == 0) {
            curCoin += nums[choose] * tmpValue1;
        } else if (choose == nums.size() - 1) {
            curCoin += nums[choose] * tmpValue2;
        } else {
            curCoin += tmpValue1 * nums[choose] * tmpValue2;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (!mark[i]) {
                mark[i] = true;
                res = max(res, searchCoin(nums, i, curCoin));
                mark[i] = false;
            }
        }

        return res == 0 ? curCoin : res;
    }

public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int res = 0;
        mark = vector<bool>(n, false);

        for (int i = 0; i < n; ++i) {
            mark[i] = true;
            res = max(res, searchCoin(nums, i, 0));
            mark[i] = false;
        }

        return res;
    }
};

int main() {
    vector<int> nums = {7, 9, 8, 0, 7, 1, 3, 5, 5, 2, 3};
    Solution s;
    cout << s.maxCoins(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}