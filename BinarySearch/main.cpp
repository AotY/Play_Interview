#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/**
 * Binary Seaerch
 *
 * Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.
 */

static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    int search(vector<int> &nums, int target) {
        assert(nums.size() > 0);

        int l = 0;
        int r = (int) nums.size() - 1;

        // find target in [l, r ].
        // 当 l == r时,区间[l...r]依然是有效的

        while (l <= r) {
            int mid = (l + r) >> 1;
//            int mid = (l + r) / 2;
//            int mid = l + (r >> 1);
            if (nums[mid] == target)
                return mid;

            else if (nums[mid] < target)
                l = ++mid;
            else
                r = --mid;
        }

        return -1;
    }
};


int main() {
//    std::cout << "Hello, World!" << std::endl;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    Solution s;
    cout << s.search(nums, 0) << endl;

    return 0;

}