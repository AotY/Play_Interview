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

			unordered_map<int, bool> bookMap;

			int maxLen = 1;
			for (int i = 0; i < n; i ++ ){
				if (maxLen == n)
					break;

				if (bookMap[nums[i]])
					continue;

				int minNum = nums[i];
				int maxNum = nums[i] + min(INT_MAX - nums[i], n);
				int curLen = 1;

				while (minNum < maxNum) {
					if(numSet.find(minNum + 1) != numSet.end()) {
						bookMap[(minNum + 1)] = true;
						curLen++;
					} else {
						break;
					}
					maxLen = max(maxLen, curLen);
					minNum += 1;
				}
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
