#include <iostream>
#include <vector>

using namespace std;

// 一次遍历

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int n = nums.size();
        if (nums.size() < 2)
            return;

        // [ zeroIndex, oneIndex,,, twoIndex]
        int zeroIndex = 0;
        int twoIndex = n - 1;
//        int oneIndex = 0;


        for (int i = 0; i < n; ) {
            if (i > twoIndex)
                break;
            if (nums[i] == 1) {
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[twoIndex--]);
            } else {
                // 0 ，这里很重要，与其交换的是 1， 或者当i=0是为0，所以i 需要++
                swap(nums[zeroIndex++], nums[i++]);
            }
        }
    }
};


int main() {

    Solution s;
    vector<int> nums = {2,0,2,1,1,0};
    s.sortColors(nums);
    for (int i: nums) {
        cout << i << ", ";
    }
    cout << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}