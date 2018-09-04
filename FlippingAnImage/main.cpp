#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {

        int n = A.size();

        int m = A[0].size();


        // flip
        int mid = m >> 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < mid; ++j) {
                swap(A[i][j], A[i][m - j - 1]);
            }
        }

        // invert

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                A[i][j] = !A[i][j];
            }
        }

        return A;
    }
};


int main() {

    vector<vector<int>> A = {
            {1, 1, 0},
            {1, 0, 1},
            {0, 0, 0}
    };
    Solution s;
    s.flipAndInvertImage(A);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}