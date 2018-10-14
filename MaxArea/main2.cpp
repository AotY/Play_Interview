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

//对撞指针方法，初始时使left,right分别置于两边，此时weight差值最大
//left或right他们自己两个中最小的那个向着最大的那个靠近
//
class Solution {
    public:
        int maxArea(vector<int>& nums) {

            //
            int n = nums.size();

            if (n == 2)
                return min(nums[0], nums[1]) * 1;

            int left = 0;
            int right = n - 1;

            int res = 0;

            while (left < right ) {
                
                int curArea = min(nums[left], nums[right]) * (right - left);

                if (nums[left] < nums[right])
                    left ++;
                else 
                    right --;

                res = max(res, curArea);
            }
            
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
