//
// Created by Leon Tao on 06/07/2018.
//

#ifndef SORT_UTIL_H
#define SORT_UTIL_H

#endif //SORT_UTIL_H

#include <iostream>
#include <vector>
#include <cassert>

namespace Util {

// print vecotr

    void printVecotr(std::vector<int> &arr) {
        for (std::vector<int>::const_iterator i = arr.begin(); i < arr.end(); ++i) {
            std::cout << *i << " ";

        }
    }

    void printVector(std::vector<int>::const_iterator beg, std::vector<int>::const_iterator end) {
        while (beg != end) {
            std::cout << *beg++;
            if (beg != end)
                std::cout << " ";
        }
        std::cout << std::endl;
    }

}