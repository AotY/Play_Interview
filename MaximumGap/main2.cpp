#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maximumGap(vector<int> &nums) {
        int n = nums.size();

        if (n <= 1)
            return 0;

        int res = 0;


        // 排序
        sort(nums.begin(), nums.end());

        // 找相邻两个元素的最大差
        int res = 1 << 31;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] > res)
                res = nums[i + 1] - nums[i];
        }

        return res;
    }
};

int main() {

    Solution s;

    vector<int> nums = {3, 6, 9, 1};
    cout << s.maximumGap(nums) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}