#include <iostream>
#include <vector>

using namespace std;


class Solution {

private:
    int binarySearch(vector<int> &nums, int target, int left, int right) {

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;

        }
        return -1;
    }

public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0)
            return -1;

        int pivot = 1;
        int startVal = nums[0];

        while (nums[pivot] >= startVal) {
            startVal = nums[pivot];
            pivot++;
        }

        int res = -1;
        res = binarySearch(nums, target, pivot, n - 1);
        if (res != -1)
            return res;

        res = binarySearch(nums, target, 0, pivot - 1);
        return res;

    }
};


int main() {

    Solution s;
    vector<int> nums = {1};
    cout << s.search(nums, 1) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}