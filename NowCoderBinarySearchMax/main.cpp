#include <iostream>
#include <vector>

int BinarySearchMax(const std::vector<int> &data, int target) {

    int left = 0;

    int right = data.size();
    // [left, right )区间 查找target
    while (left < right) {

        int mid = (left + right) / 2;

        if (data[mid] == target) {
            // 判断，搜索最右边的元素
            int tmpIndex = mid + 1;
            while (data[tmpIndex] == target)
                tmpIndex++;
            return tmpIndex - 1;
        } else if (data[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;

}


int main() {

    std::vector<int> nums = {1, 2, 2, 2, 4, 5, 9};
    std::cout << BinarySearchMax(nums, 2) << std::endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}