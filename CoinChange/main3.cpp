#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {

private:
    const int MAX_COUNT = 99999;

public:
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0)
            return 0;
        int n = coins.size();
        assert(n > 0);

        // 从大到小排序
        sort(coins.begin(), coins.end(), std::greater<int>());

        // 比最小的coin还要小
        if (amount < coins[n - 1])
            return -1;

        vector<int> memo(amount + 1, MAX_COUNT);

        // 最小面值的coin，最少需要一个
        for (int i = 0; i < n; ++i) {
            if (coins[i] <= amount)
                memo[coins[i]] = 1;
        }

        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > coins[j])
                    memo[i] = min(memo[i], 1 + memo[i - coins[j]]);
            }
        }

        int result = memo[amount];
        return result == MAX_COUNT ? -1 : result;
    }
};

int main() {

    Solution s;
    vector<int> nums = {1};
    cout << s.coinChange(nums, 0) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}