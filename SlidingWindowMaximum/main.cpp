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
#include <unordered_set>
#include <map>
#include <unordered_map>


using namespace std;


// 使用滑动窗口，然后更新最值，主要是判断是否是nums[left] 为当前的最大值；
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> res;
            int n = nums.size();
            if (n == 0 || n < k)
                return res;

            // [left, right]
            int left = 0;
            int right = -1;

            int curMax = nums[0];
            int curMaxIndex = 0;

            while ( left <= (n - k) && right < n) {
                if (right - left + 1 < k ) {
                    // update curMax
                    curMax = max(curMax, nums[++right]);
                } else {
                    res.push_back(curMax);
                    right ++;
                    if (curMax == nums[left++]) {
                        //
                        int tmpLeft = left;
                        curMax = nums[tmpLeft ++];
                        while (tmpLeft <= right && tmpLeft < n) {
                            curMax = max(curMax, nums[tmpLeft]);
                            tmpLeft ++;
                        }
                    }
                    else {
                        curMax = max(curMax, nums[right]);
                    }
                }
            }

            return res;
        }
};


int main() {

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    Solution s;

    int k = 3;
    vector<int> res = s.maxSlidingWindow(nums, k);

    for (int i = 0; i < res.size(); i++ ){
        cout << res[i] << " ,";
    }
    cout << endl;

    return 0;
}
