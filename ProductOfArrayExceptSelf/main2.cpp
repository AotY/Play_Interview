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
        map<int, int> leftProductions;
        map<int, int> rightProductions;

        int left = -1;
        int right = n;

        for (int i = 0; i < n; ++i) {
            
            // left
            leftProductions[i] = i == 0 ? 1 : nums[i - 1] * leftProductions[i - 1];

            // right
            if (rightProductions.find(i) == rightProductions.end()) {
                int rp = 1;
                int tmpRight = n - 1;
                while (tmpRight >= i) {
                    rightProductions[tmpRight] = rp;
                    rp *= nums[tmpRight];
                    tmpRight --;
                }
                
            }

            res[i] = leftProductions[i] * rightProductions[i];
            
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
