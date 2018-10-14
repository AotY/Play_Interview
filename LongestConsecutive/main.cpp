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


using namespace std;



class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {

            int n = nums.size();
            if (n == 0 )
                return 0;

            unordered_set<int> numSet;
            int minNum = nums[0];
            int maxNum = nums[0];
            numSet.insert(nums[0]);
            for (int i = 1; i < n; ++i) {
                numSet.insert(nums[i]);
                minNum = min(minNum, nums[i]);
                maxNum = max(maxNum, nums[i]);
            }

            int maxLen = 1;
            int curLen = 1;

            while (minNum < maxNum) {
                if(numSet.find(minNum + 1) != numSet.end()) {
                    curLen++;
                } else {
                    curLen = 0;
                }
                maxLen = max(maxLen, curLen);
                minNum ++;
            }

            return maxLen;
        }
};



int main() {


    Solution s;
    vector<int> nums = {0, -1};
    int res = s.longestConsecutive(nums);

    cout << res << endl;
    return 0;
}
