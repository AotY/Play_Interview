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
#include <deque>

using namespace std;


//  使用双向队列的思路
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> res;
            int n = nums.size();
            if (n == 0 || n < k)
                return res;


            deque<int> indexDeque;
            for (int i = 0; i < n; i ++) {
            
                if (!indexDeque.empty() && indexDeque.front() == i - k ) {
                    // 说明此时滑动窗口的大小已经为k 
                    indexDeque.pop_front();
                } 

                // 移除队列中比 nums[i] (新元素) 小的元素的index
                while (!indexDeque.empty() && nums[i] > nums[indexDeque.back()]) 
                    indexDeque.pop_back();

                // 加入当前的i
                indexDeque.push_back(i);

                if (i >= k - 1)
                    res.push_back(nums[indexDeque.front()]);
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
