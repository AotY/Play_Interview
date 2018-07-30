#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
283
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

 **/

class Solution {
public:
    void moveZeroes1(vector<int> &nums) {
        // using two index, l one zeroes, r zeroes
        int l = 0;
        int r = (int) nums.size() - 1;
        // [l, r]
        while (l < r) {
            if (nums[l] != 0)
                l++;
            else {
                if (nums[r] == 0)
                    r--;
                // move l - r
                for (int i = l; i < r; ++i) {
                    nums[i] = nums[i + 1];
                }
                nums[r] = 0;
            }
        }
    }

    //  更少的操作，不用移动
    void moveZeroes(vector<int> &nums) {
        int skipIndex = 0;

        // or
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i])
                swap(nums[skipIndex++], nums[i]);
        }

    }
};


int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution s;
//    s.moveZeroes1(nums);
    s.moveZeroes2(nums);

    cout << "[";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << (i == (nums.size() - 1) ? "" : " ");
    }
    cout << "]" << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
