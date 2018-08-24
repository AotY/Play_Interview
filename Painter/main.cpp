#include <iostream>
#include <vector>

using namespace std;

// 墙的大小
int n;

// 当前位置，包括其上，右，下，左 都会改变颜色
int paintArr[5][2] = {
        {0,  0},
        {-1, 0},
        {0,  1},
        {1,  0},
        {0,  -1}
};

bool isInWall(int i, int j) {
    return (i >= 0 && i < n) && (j >= 0 && j < n);
}

// 涂画i, j
void paintPosition(vector<vector<char>> &wall, int curI, int curJ) {
    for (int k = 0; k < 5; ++k) {
        int newI = curI + paintArr[k][0];
        int newJ = curJ + paintArr[k][1];

        if (isInWall(newI, newJ)) {
            wall[newI][newJ] = wall[newI][newJ] == 'w' ? 'y' : 'w';
        }
    }
}

// 取c的第j位，j从0开始
int getBit(int num, int j) {

    return (num >> j) & 1;
}


// 尝试涂画
int tryPainting(vector<vector<char>> &wall, int n) {


    // 记录涂画最少次数
    int minCount = INT_MAX;

    // 从第一行开始，选择涂画几个位置
    // 这里需要枚举第一行的所有可能，每个位置都有两种状态，涂或者不涂。故，第一行有2^n中填涂可能
    for (int num = 0; num < (1 << n); ++num) {

        // 记录此次涂画需要的次数
        int curCount = 0;
        // 是否能完成涂画
        bool isFinished = true;

        vector<vector<char>> tmpWall = wall;

        // 第一行
        for (int j = 0; j < n; j++) {
            if (getBit(num, j) == 1) { // 1, 需要涂画
                paintPosition(tmpWall, 0, j);
                curCount++;
            }
        }

        // 第二行到最后一行
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // 如果上一行的这个位置没有被涂画为黄色的话，涂画该位置
                if (tmpWall[i - 1][j] == 'w') {
                    paintPosition(tmpWall, i, j);
                    curCount++;
                }
            }
        }


        // 判断最后一行是否全部为黄色
        for (int j = 0; j < n; ++j) {
            if (tmpWall[n - 1][j] != 'y') {
                isFinished = false;
                break; // 继续尝试涂画
            }
        }

        // 如果全部为黄色，记录最受填涂次数
        if (isFinished)
            minCount = min(minCount, curCount);
    }

    return minCount;
}

int main() {


    cin >> n;

    vector<vector<char>> wall = vector<vector<char>>(n, vector<char>(n));

    // “w”表示白砖，“y”表示黄砖。
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> wall[i][j];
        }
    }

    int res = tryPainting(wall, n);

    if (res == INT_MAX)
        cout << "inf" << endl;
    else
        cout << res << endl;


    return 0;
}