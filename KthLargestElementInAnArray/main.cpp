#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {

private:

    void downwardAdjustment(vector<int> &nums, int curIndex, int n) {
        bool isSwap = true;
        while (isSwap && curIndex * 2 + 1 <= n) {
            // has left, right ?
            int leftChildIndex = curIndex * 2 + 1;
            int rightChildIndex = curIndex * 2 + 2;

            int maxValue = nums[curIndex];
            int swapIndex = curIndex;
            if (leftChildIndex <= n && nums[leftChildIndex] > maxValue) {
                maxValue = nums[leftChildIndex];
                swapIndex = leftChildIndex;
            }

            if (rightChildIndex <= n && nums[rightChildIndex] > maxValue) {
                swapIndex = rightChildIndex;
            }

            if (swapIndex != curIndex) {
                swap(nums[swapIndex], nums[curIndex]);
                curIndex = swapIndex;
                isSwap = true;
            } else {
                isSwap = false;
            }
        }
    }

    void buildHead(vector<int> &nums, int n) {
        int startIndex = (n - 1) / 2;

        for (int i = startIndex; i >= 0; --i) {
            // downward adjustment
            downwardAdjustment(nums, i, n);
        }
    }

    int getKLargest(vector<int> &nums, int k) {
        int res = nums[0];
        for (int i = 0; i < k; ++i) {
            res = nums[0];
            swap(nums[0], nums[nums.size() - 1]);
            nums.pop_back();
            downwardAdjustment(nums, 0, nums.size() - 1);
        }

        return res;
    }

public:
    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size() - 1;
        assert(n >= 0 && n >= (k - 1));

        int res = nums[0];

        // 1. 构建堆
        // 用最大堆
        // build a heap in [0, ... n]
        buildHead(nums, n);


        // 2. 取k次堆顶元素
        res = getKLargest(nums, k);


        return res;
    }
};


int main() {
    Solution s;

    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << s.findKthLargest(nums, 4) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}