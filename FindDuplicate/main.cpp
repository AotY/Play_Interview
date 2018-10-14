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



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        if (n == 2 || n == 1) 
            return nums[0];

        // sort
        sort(nums.begin(), nums.end());

        // search
        int duplicateNum = nums[0];

        for (int i = 1; i < n; i ++){
            if (duplicateNum == nums[i])
                return duplicateNum;
            else {
                duplicateNum = nums[i];
            }
        }
       
        throw invalid_argument("This nums has no solution.");
    }
};


int main() {


    vector<int> nums = {1,3,4,2,2};
    
    Solution s;
    int res = s.findDuplicate(nums);

    cout << res <<endl;
    return 0;
}
