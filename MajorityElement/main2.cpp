#include <iostream>
#include <vector>

using namespace std;


// 著名的主元素问题
// 2. 每次删除两个不同的元素
class Solution {
public:
    int majorityElement(vector<int> &nums) {

        while (nums.size() > 1) {
            int n = nums.size();
            int a = nums[n - 1];
            int i = n - 2;
            while (nums[i] == a)
                i--;

            if (i >= 0 && i != (n - 2))
                swap(nums[i], nums[n - 2]);

            nums.pop_back();
            nums.pop_back();
        }

        return nums[0];
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 3, 4};
    cout << s.majorityElement(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}