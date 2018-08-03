#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int countArr[3] = {0};
        for (int i = 0; i < nums.size(); ++i) {
            countArr[nums[i]]++;
        }

        int index = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < countArr[i]; ++j) {
                nums[index++] = i;
            }
        }

    }
};


int main() {

    Solution s;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    for (int i: nums) {
        cout << i << ", ";
    }
    cout << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}