#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int N;

    bool inArea(int i, int j) {
        return (i >= 0 && i < N) && (j >= 0 && j < N);
    }

    int roundArr[4][2] = {
            {-1, 0},
            {0, 1},
            {1, 0},
            {0, -1}
    };
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int res = 0;
        N = grid.size();
        if (N == 0)
            return res;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] >= 1) {
                    // 1. 当前单元格的表面积
                    int tmpArea = grid[i][j] * 6 - (grid[i][j] - 1) * 2;
                    // 2. 考虑周围被遮挡的情况
                    for (int k = 0; k < 4; ++k) {
                        int newI = i + roundArr[k][0];
                        int newJ = j + roundArr[k][1];
                        // 考虑旁边的高度
                        if (inArea(newI, newJ)) {
                            if (grid[newI][newJ] >= 1) {
                                tmpArea -= min(grid[i][j], grid[newI][newJ]); // 减去被遮挡的表面积
                            }
                        }
                    }
                    res += tmpArea;
                }
            }
        }
        return res;
    }
};


int main() {

    Solution s;
    vector<vector<int>> grid = {
            {1,1,1},
            {1,0,1},
            {1,1,1}
    };
    cout << s.surfaceArea(grid) << endl;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}