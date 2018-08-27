#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        if (n == 0)
            return 0;

        vector<int> memo = vector<int>(n);

        // 从底到顶
        int res = INT_MAX;
        for (int j = 0; j < triangle[n - 1].size(); ++j) {

            memo[n - 1] = triangle[n - 1][j];

            int lastIndex = j;

            for (int i = n - 2; i >= 0; --i) {
                if (lastIndex < triangle[i].size()) {
                    memo[i] = memo[i + 1] + triangle[i][lastIndex];
                }

                if (lastIndex - 1 >= 0) {
                    int tmp = memo[i + 1] + triangle[i][lastIndex - 1];
                    if (tmp < memo[i]) {
                        lastIndex -= 1;
                        memo[i] = tmp;
                    }

                }

//                if (lastIndex + 1 < triangle[i].size()) {
//                    int tmp = memo[i + 1] + triangle[i][lastIndex + 1];
//                    if (tmp < memo[i]) {
//                        lastIndex += 1;
//                    }
//                }


            }


            res = min(res, memo[0]);

        }

        return res;
    }
};

int main() {
    Solution s;

    vector<vector<int>> triangle = {
            {-1},
            {2, 3},
            {1, -1, -3}
    };

    cout << s.minimumTotal(triangle) << endl;
    return 0;
}