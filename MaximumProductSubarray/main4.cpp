#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        int maxNow = nums[0];
        int minNow = nums[0];

        int maxRes = INT_MIN;

        for (int i = 1; i < n; i++) {
        
            int tmpMax = maxNow * nums[i];
            int tmpMin = minNow * nums[i];

            maxNow = max(nums[i], max(tmpMax, tmpMin));
            minNow = min(nums[i], min(tmpMin, tmpMax));

            maxRes = max(maxRes, maxNow);
        }

        return maxRes;

    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 3, -2, 4};
    cout << s.maxProduct(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
