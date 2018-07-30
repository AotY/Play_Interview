#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {

private:
    const int MAX_COUNT = 99999;

    int tryChange(vector<int> &nums, int m) {
        if (m == 0)
            return 0;

        int c = MAX_COUNT;
        for (int i = 0; i < nums.size(); ++i) {
            if (m >= nums[i]) {
                c = min(1 + tryChange(nums, m - nums[i]), c);
            }
        }
        return c;
    }

public:
    int coinChange(vector<int> &coins, int amount) {
        assert(coins.size() > 0);

        // 从大到小排序
        sort(coins.begin(), coins.end(), std::greater<int>());
        int result = tryChange(coins, amount);
        return result == MAX_COUNT ? -1 : result;
    }
};

int main() {

    Solution s;
    vector<int> nums = {186, 419, 83, 408};
    cout << s.coinChange(nums, 6249) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}