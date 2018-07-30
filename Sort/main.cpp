#include <iostream>
#include <cassert>
#include <vector>
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "shell_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "head_sort.h"
#include "count_sort.h"
#include "bucket_sort.h"
#include "radix_sort.h"
#include "util.h"
using namespace std;

/**
 * 实现常用的各种排序算法 （十大经典算法）
 *
 *
 */



int main() {
//    int arr[] = {-1, 1, 3, -2, 5, 7, 4, 0, 2, 8};
    int arr[] = {8, 0, 1, 2, 3, 4, 2, 6, 3, 5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> vecArr (arr, arr + size);    // This is simplest and very efficient solution.
    Util::printVector(vecArr.begin(), vecArr.end());

    // bubble sort average：n^2
//    BubbleSort::bubbleSort(vecArr);

    // selection sot,  average：n^2
//    SelectionSort::selectionSort(vecArr);

    // insertion sort, average：n^2
//    InsertionSort::insertionSort(vecArr);

    // Shell sort, average: n^1.3
//    ShellSort::shellSort(vecArr);

    // merge sot, average：O(nlogn)
//    vecArr = MergeSort::mergeSort(vecArr);

    // quick sort, averge: O(nlogn)
//    QuickSort::quickSort(vecArr, 0, vecArr.size()-1);

    // head sort , averge: O(nlogn)
//    vecArr = HeadSort::headSort(vecArr);

    // count sort, averge: O(n + k)
//    vecArr = CountSort::countSort(vecArr);

    // bucket sort, averge: O(n + k)
//    vecArr = BucketSort::bucketSort(vecArr, 3);

//    radix_sort
    vecArr = RadixSort::radixtSort(vecArr, 3);





    Util::printVector(vecArr.begin(), vecArr.end());
//    Util::printVecotr(vecArr);

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}