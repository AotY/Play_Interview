#include <iostream>
#include <string>
#include <vector>

using namespace std;

//int maxCharCount()

int main() {

    string str;
    int m;

    int countArr[26] = {0};

    cin >> str >> m;

    int len = str.size();

    vector<vector<int>> charPoss = vector<vector<int>>(26, vector<int>());

    // init

    for (int i = 0; i < len; ++i) {
        int index = str.at(i) - 'a';
        int pos = i;
        // 记录所有可能的位置
        charPoss[index].push_back(pos);
    }

    int maxCount = 0;

    for (int i = 0; i < 26; ++i) {
        int n = charPoss[i].size();
        if (n < maxCount || n == 0)
            continue;

        // 记录每一个词最大的连续次数
        int mid = (n - 1) / 2;

        //  取中间的距离感觉是对的
//        int midPos = (charPoss[i][0] + charPoss[i][n - 1]) >> 1;
//        int mid = 0;
//        int minDes = charPoss[i][n - 1];
//        for (int j = 0; j < n; ++j) {
//            int des = abs(charPoss[i][j] - midPos);
//            if (des < minDes) {
//                minDes = des;
//                mid = j;
//            }
//        }


        int changeCount = 0;
        int count = 1; // 默认 mid 位置上的已经选择

        // 左
        for (int left = mid - 1; left >= 0; --left) {
            changeCount += charPoss[i][mid] - charPoss[i][left] - (mid - left);
            if (changeCount <= m)
                count++;
        }

        // 右
        for (int right = mid + 1; right <= n-1; ++right) {
            changeCount += charPoss[i][right] - charPoss[i][mid] - (right - mid);

            if (changeCount <= m)
                count++;
        }

        maxCount = max(maxCount, count);

    }


    cout << maxCount << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// hkdbqojqvxlfulshrhpysezhlyzolb 20