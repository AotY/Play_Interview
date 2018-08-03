#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:
    bool binarySearch(vector<int> &nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;

        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;

        for (int i = 0; i < m; ++i) {
            if (matrix[i][n - 1] == target)
                return true;
            else if (matrix[i][0] < target) {
                continue;
            } else {
                // matrix[i][0] > target
                if (binarySearch(matrix[i], target))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}