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

// unordered_set
class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {

            int n = nums.size();

            if (n == 0) {
                return 1;
            }

            unordered_set<int> numSet;
            for (int i = 0; i < n ; i ++) {
                numSet.insert(nums[i]);
            }

            int minNum = 1;

            while (numSet.find(minNum) != numSet.end())
                minNum ++;

            return minNum;
        }
};



int main() {

    Solution s;
    vector<int> nums = {3,4,-1,1};
    int res = s.firstMissingPositive(nums);
    cout << res << endl;

    return 0;
}
