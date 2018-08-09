#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int unmatchedColors(vector<vector<int>> &colors, int n, int m, int c) {

    int res = 0;

    for (int i = 1; i <= c; ++i) {
        int colorSize = colors[i].size();
        if (colorSize <= 1)
            continue;

        bool isAdd = false;
        // 环形
        if (colors[i][colorSize - 1] == n) {
            colors[i].push_back(colors[i][0]);
            colorSize += 1;
            isAdd = true;
        }

        int des = 0;
        for (int j = 1; j < colorSize; ++j) {
            if (j == colorSize - 1 && isAdd) {
                des = colors[i][j] + n - colors[i][j - 1];
            } else {
                des = colors[i][j] - colors[i][j - 1];
            }
            if (des < m) {
                res++;
                break;
            }

        }
    }

    return res;
}


int main() {

    int n, m, c;

    cin >> n >> m >> c;

    int num;
    int color;

    vector<vector<int>> colors = vector<vector<int>>(c + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        for (int j = 0; j < num; ++j) {
            cin >> color;

            // 每个颜色出现的串珠
            colors[color].push_back(i);
        }
    }

    int res = unmatchedColors(colors, n, m, c);

    cout << res << endl;

    return 0;
}