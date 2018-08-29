#include <iostream>
#include <vector>

using namespace std;

// Input:[ [4,10,15,24,26], [0,9,12,20], [5,18,22,30] ]
// Output: [20,24]
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        vector<int> res;
        int n = nums.size();
        if (n == 0)
            return res;


        // 暴力思路，找到最小值和最大值，然后用双指针向中心滑动
        int minNum = INT_MAX;
        int maxNum = INT_MIN;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                if (nums[i][j] > maxNum)
                    maxNum = nums[i][j];

                if (nums[i][j] < minNum)
                    minNum = nums[i][j];
            }
        }


        int left = minNum;
        int right = maxNum;


        int maxLeft;
        int minRight;

        bool isFit;
        while (left < right) {

            for (int i = 0; i < n; ++i) {
                isFit = false;
                for (int j = 0; j < nums[i].size(); ++j) {
                    if (nums[i][j] >= left && nums[i][j] <= right) {
                        isFit = true;
                        break;
                    }
                }

                if (!isFit)
                    break;
            }

            if (isFit) {
                maxLeft = left;
                minRight = right;
            }

            left ++;
            right -- ;
        }

        res.push_back(maxLeft);
        res.push_back(minRight);
        return res;
    }
};


int main() {

    Solution s;
    vector<vector<int>> nums = {
            {4,10,15,24,26},
            {0,9,12,20},
            {5,18,22,30}
    };

    vector<int> res = s.smallestRange(nums);

    cout << res[0] << ", " << res[1] << endl;

    return 0;
}