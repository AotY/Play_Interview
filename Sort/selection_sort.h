//
// Created by Leon Tao on 06/07/2018.
//

#ifndef SORT_SELECTION_SORT_H
#define SORT_SELECTION_SORT_H

#endif //SORT_SELECTION_SORT_H

#include <vector>
#include <assert.h>

namespace SelectionSort {

    // 引用传递vector
//    void selectionSort(std::vector<int>& nums) {
//        // 将[0...nums.size())的元素排序
//        for (int i = 0; i < nums.size()-1; ++i) {
//            for (int j = i+1; j < nums.size(); ++j) {
//                if (nums[i] > nums[j]) {
//                    std::swap(nums[i], nums[j]);
//                }
//            }
//        }
//    }


    // 引用传递vector，记录要交换的位置
    void selectionSort(std::vector<int>& nums) {
        // 将[0...nums.size())的元素排序
        int swapIndex;
        for (int i = 0; i < nums.size()-1; ++i) {
            swapIndex = i;

            for (int j = i+1; j < nums.size(); ++j)
                if (nums[swapIndex] > nums[j])
                    swapIndex = j;

            if (i != swapIndex)
                std::swap(nums[i], nums[swapIndex]);
        }
    }
}

