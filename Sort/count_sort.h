//
// Created by Leon Tao on 07/07/2018.
//

#ifndef SORT_COUNT_SORT_H
#define SORT_COUNT_SORT_H

#endif //SORT_COUNT_SORT_H

#include <vector>
#include <cassert>
#include <algorithm>


namespace CountSort {

    std::vector<int> countSort(std::vector<int> nums) {

        assert(nums.size() > 0);
        std::vector<int>  result;

        std::vector<int>::iterator max = std::max_element(nums.begin(), nums.end());
        int maxValue = nums[std::distance(nums.begin(), max)];

        std::vector<int> bucket(maxValue + 1, 0); // maxValue + 1: start from zero, so add one here

        for (int i = 0; i < nums.size(); ++i) {
            bucket[nums[i]] += 1;
        }

        for (int j = 0; j < bucket.size(); ++j) {
            int count = bucket[j];
            for (int i = 0; i < count; ++i) {
                result.push_back(j);
            }
        }
        return result;
    }
}