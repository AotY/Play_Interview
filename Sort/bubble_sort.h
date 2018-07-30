//
// Created by Leon Tao on 06/07/2018.
//

#ifndef SORT_BUBBLE_SORT_H
#define SORT_BUBBLE_SORT_H

#endif //SORT_BUBBLE_SORT_H

#include <iostream>
#include <cassert>
#include <vector>

//using namespace std;

namespace BubbleSort {

    void bubbleSort(std::vector<int>& nums) {
        // 将[0, nums.size())的元素排序
        for (int i = 0; i < nums.size()-1; i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    std::swap(nums[j], nums[j + 1]);
                }
            }
        }
    }

}