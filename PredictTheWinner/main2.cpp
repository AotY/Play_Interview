#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:

    int searchWinner(const vector<int> &nums, int left, int right ) {
        if (left == right)
            return nums[left];

        int res = max(nums[left] - searchWinner(nums, left + 1, right),
                        nums[right] - searchWinner(nums, left, right - 1));

        return res;
    }
public:
    bool PredictTheWinner(vector<int>& nums) {

        int res = searchWinner(nums, 0, nums.size() - 1);

        // 判断差
        return res >= 0;
    }
};

int main() {

    Solution s;
    vector<int> nums = {1, 3, 7, 2};
    cout << s.PredictTheWinner(nums) << endl;

    return 0;
}


