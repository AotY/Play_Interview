//
// Created by Leon Tao on 07/07/2018.
//

#ifndef SORT_BUCKET_SORT_H
#define SORT_BUCKET_SORT_H

#endif //SORT_BUCKET_SORT_H

//#include "insertion_sort.h"
#include <vector>
#include <cassert>
#include <math.h>


namespace BucketSort {

    std::vector<int> bucketSort(std::vector<int> nums, int bucketSize) {

        int DEFAULT_BUCKET_SIZE = 5;            // 设置桶的默认数量为5

        assert(nums.size() > 0);

        std::vector<int>  result;

        std::vector<int>::iterator max = std::max_element(nums.begin(), nums.end());
        int maxValue = nums[std::distance(nums.begin(), max)];

        std::vector<int>::iterator min = std::min_element(nums.begin(), nums.end());
        int minValue = nums[std::distance(nums.begin(), min)];

        bucketSize = bucketSize || DEFAULT_BUCKET_SIZE;

        int bucketCount = floor((maxValue - minValue) / bucketSize + 1);

        std::vector<std::vector<int>> bucket(bucketCount, std::vector<int>(bucketSize, -1));

        // 利用映射函数将数据分配到各个桶中
        for (int i = 0; i < nums.size(); ++i) {
            int bucketIndex = floor((nums[i] - minValue) / bucketSize);
            bucket[bucketIndex].push_back(nums[i]);
        }

        // 每个桶分别排序

        for (int j = 0; j < bucketCount; ++j) {
            InsertionSort::insertionSort(bucket[j]);
        }

        for (int i = 0; i < bucketCount; ++i) {
            for (int j = 0; j < bucket[i].size(); ++j) {
                if (bucket[i][j] != -1)
                    result.push_back(bucket[i][j]);
            }
        }
        return result;
    }
}