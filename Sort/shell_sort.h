//
// Created by Leon Tao on 06/07/2018.
//

#ifndef SORT_SHELL_SORT_H
#define SORT_SHELL_SORT_H

#endif //SORT_SHELL_SORT_H

#include <vector>
#include <cassert>
#include <math.h>

namespace ShellSort {
    // 先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序
    void shellSort(std::vector<int> &nums) {

        // 划分
        int gap = 1;
        while (gap < (nums.size() / 3))
            gap = gap * 3 + 1;

        int swapValue;
        // 不同的间隔进行插入排序
        for (gap; gap > 0; gap = int(floor(gap / 3))) {

            for (int i = gap; i < nums.size(); ++i) {
                swapValue = nums[i];

                int j = i - gap;
                for (j ; j >= 0; j -= gap) {
                    if (nums[j] > swapValue)
                        nums[j + gap] = nums[j];
                    else
                        break;

                }
                nums[j + gap] = swapValue;
            }
        }
    }
}
