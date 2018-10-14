#include <iostream>
#include <vector>

using namespace std;

// solution 1, using division, O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res = vector<int>(n);

        int zeroCount = 0;
        long productSum = 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0)
                productSum *= nums[i];
            else
                zeroCount = zeroCount + 1;
            
        }

        for (int i = 0; i < n; ++i) {
            if (zeroCount == 1) {
                if (nums[i] == 0)
                    res[i] = (int) (productSum);
                else
                    res[i] = 0;
            }else if (zeroCount == 0) {
                res[i] = (int) (productSum / nums[i]);
            } else {
                // zeroCount > 1
                res[i] = 0;
            } 
            
        }

       return res; 
    }
};
