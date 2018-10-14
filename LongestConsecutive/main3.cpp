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
        int longestConsecutive(vector<int>& nums) {

            int n = nums.size();
            if (n == 0 )
                return 0;

            unordered_set<int> numSet(nums.begin(), nums.end());


            int maxLen = 1;
            for (int i = 0; i < n; i ++ ){
                if (maxLen == n)
                    break;

                // 左右查找，删除set中的元素
                if (numSet.find(nums[i]) == numSet.end())
                    continue;

                int curLen = 1;

                int curNum = nums[i] + 1;
                while (numSet.find(curNum) != numSet.end()) {
                    curLen++;
                    numSet.erase(curNum++);
                }

                curNum = nums[i] - 1;
                while (numSet.find(curNum) != numSet.end()) {

                    curLen ++;
                    numSet.erase(curNum--);

                }

                numSet.erase(nums[i]);
                maxLen = max(maxLen, curLen);
            }
            return maxLen;
        }
};



int main() {


    Solution s;
    vector<int> nums = {2147483646,-2147483647,0,2,2147483644,-2147483645,2147483645};
    int res = s.longestConsecutive(nums);

    cout << res << endl;
    return 0;
}
