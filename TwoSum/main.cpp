#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <unordered_map>

using namespace std;




/**
 * 1 Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 */

class Solution {
public:

    vector<int> myMethod(vector<int> &nums, int target){
        assert(nums.size() > 0);


        int index_arr[nums.size()];
        bool mark_arr[nums.size()];

        for (int i = 0; i < nums.size(); ++i) {
            index_arr[i] = nums[i];
            mark_arr[i] = false;
        }

        sort(nums.begin(), nums.end(), std::less<int>());

        int l = 0;
        int r = (int) nums.size() - 1;

        // l can't  equals to r
        while (l < r) {
            int sum = nums[l] + nums[r];

            if (sum == target)
                break;

            else if (sum < target)
                l++;
            else
                r--;
        }

        vector<int> result;
        bool is_find1 = false;
        // 保证index不能出错
        for (int j = 0; j < nums.size(); ++j) {
            if (index_arr[j] == nums[l] && !mark_arr[j] && !is_find1) {
                result.push_back(j);
                mark_arr[j] = true;
                is_find1 = true;
            }

            if (index_arr[j] == nums[r] && !mark_arr[j])
                result.push_back(j);

            if (result.size() == 2)
                break;
        }

        return result;
    }

    vector<int> map_method(vector<int>& nums, int target) {
        //   因为题目保证了只有唯一的解
        unordered_map<int, int> indexMap;

        vector<int> result ;
        for (int i = 0; i < nums.size(); ++i) {
            int sub = target - nums[i];
            if (indexMap.count(sub)) {
                result.push_back(i);
                result.push_back(indexMap[sub]);
                return result;
            }
            indexMap[nums[i]] = i; // cool index[nums[i]] = i
        }
    }



    vector<int> twoSum(vector<int> &nums, int target) {
//        return myMethod(nums, target);
        return map_method(nums, target);
    }

};


int main() {

    vector<int> nums = {2, 7, 11, 15};
    Solution s;
    vector<int> result = s.twoSum(nums, 9);
    for (int i = 0; i < result.size(); ++i) {
        // a > b ? a : b
        cout << result[i] << (i == (result.size() - 1) ? "" : " ");
    }

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
