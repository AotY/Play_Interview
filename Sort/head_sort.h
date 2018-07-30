//
// Created by Leon Tao on 06/07/2018.
//

#ifndef SORT_HEAD_SORT_H
#define SORT_HEAD_SORT_H

#endif //SORT_HEAD_SORT_H

#include <vector>
#include <cassert>
#include <math.h>

namespace HeadSort {






    void adjust_recursive_node(std::vector<int>& nums, int node) {

        int swapIndex;
        int j = node;

        bool isSwap = true;

        while ((j * 2 + 1) <= (nums.size() - 1) && isSwap) {

            swapIndex = j;

            int l = j * 2 + 1;
            int r = j * 2 + 2;

            if (nums[l] < nums[swapIndex]) {
                swapIndex = l;
            }

            if (r <= (nums.size() - 1) && nums[r] < nums[swapIndex]) {
                swapIndex = r;
            }

            if (j != swapIndex) {
                std::swap(nums[node], nums[swapIndex]);
                j = swapIndex;
                isSwap = true;
            }
            else
                isSwap = false;
        }


    }

    void buildHead(std::vector<int>& nums) {

        // 调整节点， leftChild , rightChild

        int startNode = floor((nums.size() - 1 - 1) / 2);

        // recursive
        for (int i = startNode; i >= 0; i--) {

            adjust_recursive_node(nums, i);

        }
    }

    std::vector<int> headSort(std::vector<int>& nums) {
        assert(nums.size() > 0);

        // build head
        buildHead(nums);

        std::vector<int> result;


        int len = nums.size() - 1;

        // sort
        for (int i = 0; i < len; ++i) {
//            result.push_back(nums[0]);
            result.push_back(*nums.begin());
            nums.erase(nums.begin());
//            adjust_recursive_node(nums, 0);
            buildHead(nums);

        }

        result.push_back(*nums.begin());

        return result;

    }

}