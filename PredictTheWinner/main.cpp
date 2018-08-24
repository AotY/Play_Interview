#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:

    vector<int> memo;

    // 1 - 本次玩家获胜， 2 - 另一个的玩家获胜 ， 3 - 1玩家获胜总是获胜
    bool searchWinner(const vector<int> &nums, int curSum, int state) {

        if (curSum < 0)
            return false; //先手已经获胜

        if (curSum == 0) {
            cout << true << endl;
            exit(0);
        }


        if (memo[state] != -1)
            return memo[state] == 1;

        bool nexRes = false;
        // 选择最左的数
        int left = 0;
        while (state & (1 << left) && left < nums.size())
            left++;

        // The next player can not win, current player wins
        if (left != nums.size()) {
//            if (nums[left] > (curSum / 2))
//                return true; // 该手获胜

            nexRes = searchWinner(nums, curSum - nums[left], state | (1 << left));
        }

        if (nexRes) {

            int right = nums.size() - 1;
            while (state & (1 << right) && right > 0)
                right--;

            if (right != -1) {
//                if (nums[right] > (curSum / 2))
//                    return true; // 该手获胜

                nexRes = searchWinner(nums, curSum - nums[right], state | (1 << right));
            }

        }


        // 如果另一个玩家可能失败时
        if (!nexRes) {
            memo[state] = 1;
            return true;
        }

        memo[state] = 0;
        return false;
    }


public:
    bool PredictTheWinner(vector<int> &nums) {
        int n = nums.size();
        if (n == 1)
            return true;

        int sum = nums[0];
        int maxNum = nums[0];
        for (int i = 1; i < n; ++i) {
            sum += nums[i];
            maxNum = max(maxNum, nums[i]);
        }

        // >= half 就能获胜
//        int desiredNum = (sum + 1) / 2;

        memo = vector<int>(1 << maxNum, -1);
        int state = 0;
        bool res = searchWinner(nums, sum, state);

        return res;

    }
};


int main() {

    Solution s;
    vector<int> nums = {100, 100};
    cout << s.PredictTheWinner(nums) << endl;

    return 0;
}