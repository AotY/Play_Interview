//
// Created by Leon Tao on 06/07/2018.
//

#ifndef SORT_QUICK_SORT_H
#define SORT_QUICK_SORT_H

#endif //SORT_QUICK_SORT_H

#include <vector>
#include <cassert>
#include <math.h>

namespace QuickSort {

    int get_partition(std::vector<int> &nums, int left, int right) {
        int mid = left + floor(right - left) / 2;
        std::swap(nums[left], nums[mid]);

        // set pivot
        int pivot = nums[left];

        // 将[left, right]里的元素分为两部分
        int i = left, j = right;
        while (i < j) {
            while (nums[j] > pivot && j > i)
                j--;

            while (nums[i] < pivot && i < j)
                i++;

            if (i != j)
                std::swap(nums[i], nums[j]);
        }
        nums[i] = pivot;

        return i;

    }

    void quickSort(std::vector<int> &nums, int left, int right) {

        if (left >= right)
            return;

        // get partition
        int partition = get_partition(nums, left, right);

        quickSort(nums, left, partition - 1);

        quickSort(nums, partition + 1, right);

    }
}