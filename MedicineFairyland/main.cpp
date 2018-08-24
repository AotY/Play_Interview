#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 搜索问题，并且需要路径最短，使用BFS，可以使用递归或者使用栈

// M 表示迷阵行数, N 表示迷阵列数
int M, N;

// 上，右，下，左
int moveArr[4][2] = {
        {-1, 0},
        {0,  1},
        {1,  0},
        {0,  -1}
};

bool isInIsland(int i, int j) {
    return (i >= 0 && i < M) && (j >= 0 && j < N);
}

int searchMedicine(const vector<vector<char>> &island, vector<vector<bool>> &mark, int curI, int curJ, int curStep) {
    if (island[curI][curJ] == '*')
        return curStep; // 返回当前的步数


    // 标记当前点已经访问
    mark[curI][curJ] = true;

    // 从四个方向上前进，获取最小值
    int res = INT_MAX;
    for (int i = 0; i < 4; ++i) {
        int newI = curI + moveArr[i][0];
        int newJ = curJ + moveArr[i][1];
        if (isInIsland(newI, newJ) && !mark[newI][newJ] && (island[newI][newJ] == '.' || island[newI][newJ] == '*')) { // 是否能前进
            res = min(res, searchMedicine(island, mark, newI, newJ, curStep + 1));
        }
    }

    // 重要一步，当一条路径搜索完毕是，将当前点置为没有访问过，因为下一条路径在搜索时还可能会访问该点
    mark[curI][curJ] = false;

    return res;
}


int main() {

    while (true) {
        cin >> M >> N;
        // 退出条件
        if (M == 0 && N == 0)
            break;

        // island记录迷阵
        vector<vector<char>> island = vector<vector<char>>(M, vector<char>(N));

        // mark记录某一点是否已经访问过了
        vector<vector<bool>> mark = vector<vector<bool>>(M, vector<bool>(N, false));

        // 记录出发位置
        int startI, startJ;

        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> island[i][j];
                if (island[i][j] == '@') {
                    startI = i;
                    startJ = j;
                }
            }
        }

        int res = searchMedicine(island, mark, startI, startJ, 0);

        // 没有找到
        if (res == INT_MAX)
            res = -1;

        cout << res << endl;

    }

    return 0;
}

/*
8 8
.@##...#
#....#.#
#.#.##..
..#.###.
#.#...#.
..###.#.
...#.*..
.#...###

6 5
.*.#.
.#...
..##.
.....
.#...
....@

3 3
@.#
..#
*.#

*/