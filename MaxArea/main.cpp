/*
 * main.cpp
 * Copyright (C) 2018 LeonTao <LeonTao@Leons-MacBook-Pro.local>
 *
 * Distributed under terms of the MIT license.
 */

/* #include "main.h" */
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>


using namespace std;

// timeout 
class Solution {
    private:
        int searchArea(vector<int> &nums, int left, int right) {
            if (left >= right) {
                return 0;
            }
            int curArea = min(nums[left], nums[right]) * (right - left);

            int res = max(searchArea(nums, left, right-1), curArea);

            res = max(searchArea(nums, left + 1, right), res);

            return res;
        }
    public:
        int maxArea(vector<int>& nums) {

            //
            int n = nums.size();

            if (n == 2)
                return min(nums[0], nums[1]) * 1;

            int left = 0;
            int right = n - 1;

            int res = 0;

            res = searchArea(nums, left, right);
            return res;
        }
};





int main() {

    vector<int> nums = {1,8,6,2,5,4,8,3,7};

    Solution s;

    int res = s.maxArea(nums);

    cout << res << endl;

    return 0;
}
