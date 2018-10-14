#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
       vector<int> res ;
       int n = nums.size();
       if (n < 2)
           return res;

       int left = 0;
       int right = n - 1;

       while (left < right) {
            if (nums[left] + nums[right] == target) {
                res.push_back(left + 1);
                res.push_back(right + 1);
                return res;
            }
            else if (nums[left] + nums[right] < target)
                left ++ ;
            else 
                right --;
       }

       throw invalid_argument("The nums has no Solution.");
    }
};


int main() {
    Solution s;
    
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res = s.twoSum(nums, target);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << ", ";
    }
    cout << endl;

}
