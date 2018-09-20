#include <iostream>
#include <vector>

using namespace std;


class NumArray {
public:
    vector<int> nums;
    vector<int> BIT;

    NumArray(vector<int> nums) {
        this->nums = nums;

        BIT = vector<int>(nums.size() + 1);

        for (int i = 0; i < nums.size(); i++)
            change(i + 1, nums[i]);
    }

    int lowbit(int x) {
        return (x & (-x));
    }

    void update(int i, int val) {
        int delta = val - nums[i];
        nums[i] = val;
        if (delta) {
            change(i + 1, delta);
        }
    }

    void change(int i, int val) {
        while (i < BIT.size()) {
            BIT[i] += val;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += BIT[i];
            i -= lowbit(i);
        }
        return sum;
    }

    int sumRange(int i, int j) {
        return query(j + 1) - query(i);
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