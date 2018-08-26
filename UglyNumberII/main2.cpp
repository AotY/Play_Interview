#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

// 用堆 ，对。类似 top k 问题
class Solution {

private:
    const int MAX_SIZE = 30;

    int primeFactor[3] = {2, 3, 5};

    // 向下调整
    void adjustIndex(vector<int> &nums, int index, bool isMaxHeap) {
        int size = nums.size();
        bool isSwap = true;
        int tmpI = index;
        while (isSwap && (tmpI * 2 + 1) < size) {

            int swapIndex = tmpI;
            int swapNum = nums[tmpI];

            int leftChildIndex = tmpI * 2 + 1;
            int rightChildIndex = tmpI * 2 + 2;

            // 左孩子
            if (isMaxHeap) {
                // 最大堆
                if (nums[leftChildIndex] > swapNum) {
                    swapIndex = leftChildIndex;
                    swapNum = nums[leftChildIndex];
                }

            } else {
                // 最小堆
                if (nums[leftChildIndex] < swapNum) {
                    swapIndex = leftChildIndex;
                    swapNum = nums[leftChildIndex];
                }

            }

            // 右孩子
            if (rightChildIndex < size) {
                if (isMaxHeap) {
                    // 最大堆
                    if (nums[rightChildIndex] > swapNum) {
                        swapIndex = rightChildIndex;
                    }

                } else {
                    // 最小堆
                    if (nums[rightChildIndex] < swapNum) {
                        swapIndex = rightChildIndex;
                    }

                }
            }
            // 是否进行交换
            if (swapIndex != tmpI) {
                swap(nums[tmpI], nums[swapIndex]);
                tmpI = swapIndex;
            } else
                isSwap = false;

        }
    }

    // 建立堆
    void buildHeap(vector<int> &nums, bool isMaxHeap) {
        int size = nums.size();

        int startAdjustIndex = (size - 2) / 2;
        for (int i = startAdjustIndex; i >= 0; --i) {

            adjustIndex(nums, i, isMaxHeap);
        }


    }

    int findNthNum(vector<int> &nums, int n, bool isMaxHeap) {

        int res;
        for (int i = 0; i < n; ++i) {
            res = nums[0];
            // 删除堆顶元素
            nums.erase(nums.begin());
            // 向下调整堆
            adjustIndex(nums, 0, isMaxHeap);
        }


        return res;
    }

    // 搜索所以的解空间
    void searchNums(int curNum, unordered_set<int> &numsSet) {

        //  应该用队列来实现
        queue<int> searchQueue;
        searchQueue.push(curNum);

        while (true) {

            int num = searchQueue.front();
            searchQueue.pop();

            numsSet.insert(num);
            int curSize = numsSet.size();
            if (curSize >= MAX_SIZE)
                break;


            for (int i = 0; i < 3; ++i) {
                searchQueue.push(num * primeFactor[i]);
            }
        }

        return;
    }

public:
    int nthUglyNumber(int n) {
        if (n == 1)
            return 1;

        // 默认建立最小堆
        bool isMaxHeap = false;
        // 建立最大堆
        if (n > (MAX_SIZE / 2 + 1))
            isMaxHeap = true;

        // 获取所有可能的元素

        unordered_set<int> numsSet;
        searchNums(1, numsSet);

        vector<int> nums(numsSet.begin(), numsSet.end());

        // build a heap
        buildHeap(nums, isMaxHeap);

        // find top n num
        if (isMaxHeap)
            n = MAX_SIZE - n;

        int res = findNthNum(nums, n, isMaxHeap);


        return res;
    }
};

int main() {

    Solution s;
    cout << s.nthUglyNumber(10) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}