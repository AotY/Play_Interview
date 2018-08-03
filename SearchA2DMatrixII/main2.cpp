#include <iostream>
#include <vector>

using namespace std;


// 更高效的做法
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = matrix.size();
        if (!row) {
            return false;
        }
        int col = matrix[0].size();
        if (!col) {
            return false;
        }

        int startRow = 0;
        int startCol = col - 1; //

        while (true) {
            if (matrix[startRow][startCol] == target) {
                return true;
            } else if (matrix[startRow][startCol] < target) {
                startRow++;
                if (startRow >= row) {
                    return false;
                }
            } else {
                // target < matrix[startRow][startCol]
                startCol--;
                if (startCol < 0) {
                    return false;
                }
            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}