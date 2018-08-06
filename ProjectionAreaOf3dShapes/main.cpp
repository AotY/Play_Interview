#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

/*
 * 1 <= grid.length = grid[0].length <= 50
 * 0 <= grid[i][j] <= 50
 */
class Solution {
public:
    int projectionArea(vector<vector<int>> &grid) {
        int res = 0;
        int len = grid.size();
        if (len == 0)
            return 0;

//        unordered_map<pair<int, int>, int> pointsMap;

        int xy = 0;
        int zx = 0;
        int zy = 0;

        // zx，对于每一个y，取其最大的高度
        int zxs[51] = {0};
        int zys[51] = {0};

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {

                int v = grid[i][j];
                if (v  != 0) {
                    xy ++;

                    zxs[j] = max(zxs[j], v);

                    zys[i] = max(zys[i], v);
                }

            }
        }


        // zx，对于每一个y，取其最大的高度

        for (int k = 0; k < 51; ++k) {
            zx += zxs[k];
            zy += zys[k];
        }

        res = xy + zx + zy;

        return res;

    }
};

int main() {

    vector<vector<int>> grid = {
            {1, 2},
            {3, 4}
    };

    Solution s;
    cout<<s.projectionArea(grid)<<endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}