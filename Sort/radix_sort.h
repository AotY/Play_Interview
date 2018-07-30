//
// Created by Leon Tao on 07/07/2018.
//

#ifndef SORT_RADIX_SORT_H
#define SORT_RADIX_SORT_H

#endif //SORT_RADIX_SORT_H

#include <vector>
#include <cassert>
#include <math.h>


namespace RadixSort {

    std::vector<int> radixtSort(std::vector<int> nums, int bucketSize) {

        assert(nums.size() > 0);

        std::vector<int>  result;

        std::vector<int>::iterator max = std::max_element(nums.begin(), nums.end());
        int maxValue = nums[std::distance(nums.begin(), max)];


        int bucketCount = 10;
        bucketSize = (floor(nums.size() / 10) + 5) || bucketSize;

        std::vector<std::vector<int>> bucket(bucketCount, std::vector<int>(bucketSize, -1));

        int mod = 10;
        int div = 1;
        while ( floor(maxValue / div) > 0) {

            for (int j = 0; j < nums.size(); ++j) {
                int bucketIndex = ( nums[j] % mod ) / div;
                bucket[bucketIndex].push_back(nums[j]);

            }
            mod *= 10;
            div *= 10;
//            maxValue = maxValue / div;
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