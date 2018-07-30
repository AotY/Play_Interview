//
// Created by Leon Tao on 06/07/2018.
//

#ifndef SORT_MERGE_SORT_H
#define SORT_MERGE_SORT_H

#endif //SORT_MERGE_SORT_H

#include <vector>
#include <cassert>


namespace MergeSort {

    std::vector<int> __merge(std::vector<int> part1, std::vector<int> part2) {
        std::vector<int> result;

        while (part1.size() > 0 && part2.size() > 0) {
            if (*part1.begin() > *part2.begin()) {
                result.push_back(*part2.begin());
                part2.erase(part2.begin());
            } else {
                result.push_back(*part1.begin());
                part1.erase(part1.begin());
            }
        }

        while (part1.size()) {
            result.push_back(*part1.begin());
            part1.erase(part1.begin());
        }

        while (part2.size()) {
            result.push_back(*part2.begin());
            part2.erase(part2.begin());
        }
        return result;
    }

    std::vector<int> mergeSort(std::vector<int> nums) {

        if (nums.size() > 1) {

            int mid = floor(nums.size() / 2);

            std::vector<int>::const_iterator beginIterator = nums.begin();
            std::vector<int>::const_iterator midIterator = nums.begin() + mid;
            std::vector<int>::const_iterator lastIterator = nums.begin() + nums.size();

            std::vector<int> left(beginIterator, midIterator);
            std::vector<int> right(midIterator, lastIterator);

            return __merge(mergeSort(left), mergeSort(right));
        } else {
            return nums;
        }

    }
}