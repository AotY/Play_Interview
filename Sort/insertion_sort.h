//
// Created by Leon Tao on 06/07/2018.
//

#ifndef SORT_INSERTION_SORT_H
#define SORT_INSERTION_SORT_H

#endif //SORT_INSERTION_SORT_H

#include <vector>
#include <cassert>

namespace InsertionSort {

    void insertionSort(std::vector<int> &nums) {
        int insertValue;
        int insertIndex;
        for (int i = 1; i < nums.size(); i++) {
            insertValue = nums[i];
            insertIndex = i;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] < nums[j])
                    insertIndex = j;
                    // 可以减少比较
                else
                    break;
//                if (j - 1 >= 0 && nums[i] > nums[j - 1])
//                    break;
            }

            if (insertIndex != i) {
                for (int k = i; k > insertIndex; k--) {
                    nums[k] = nums[k - 1];
                }
                nums[insertIndex] = insertValue;
            }
        }
    }
}