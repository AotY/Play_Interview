#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    vector<int> nums;
    vector<int> res;
public:
    NumArray(vector<int> nums) {

        if (!nums.empty()) {
            res.push_back(nums[0]);

            for (int i = 1; i < nums.size(); ++i)
                res.push_back(res[i - 1] + nums[i]);
        }

    }

    int sumRange(int i, int j) {

        if (res.empty() || i >= res.size())
            return 0;

        if (i > 0)
            return res[j] - res[i - 1];
        else
            return res[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

int main() {

    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);

    cout << numArray.sumRange(2, 5) << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}