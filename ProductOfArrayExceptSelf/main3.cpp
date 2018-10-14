#include <iostream>
#include <vector>
#include <map>

using namespace std;

// solution 2
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res = vector<int>(n);

        // left production, right production

        int lp = 1;
        vector<int> rps = vector<int>(n);
        
        int tmpRight = n - 1;
        int rp = 1;
        while(tmpRight >= 0) {
            rps[tmpRight] = rp;
            rp *= nums[tmpRight];
            tmpRight --;
        }

        for (int i = 0; i < n; ++i) {
            
            // left
            lp = i == 0 ? 1 : lp * nums[i - 1];

            // right

            res[i] = lp * rps[i];
            
        }

       return res; 
    }
};

int main() {

    Solution s;

    vector<int> nums = {1, 2, 3, 4};

    vector<int> res = s.productExceptSelf(nums);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
        
    }
    cout << endl;
    return 0;

}
