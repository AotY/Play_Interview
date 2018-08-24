#include <stdio.h>
#include <stdlib.h>

//2 <= N <= 100, 2 <= M <= 1e6
int Map[100][100];
int resultMap[100][100];
int N, M;

int MAX_VALUE = 9999999;

int min(int a, int b) {
    return a < b ? a : b;
}

int minPath(int start, int des, int curNode, int curIndex, int curValue) {

    if (curIndex >= M) {
        if (curNode == des)
            return curValue;
        return MAX_VALUE;
    }
    int res = MAX_VALUE;

    for (int i = 0; i < N; ++i) {
        if (i != curNode) {
            res = min(minPath(start, des, i, curIndex + 1, curValue + Map[curNode][i]), res);
        }
    }


    return res;
}

int main() {


    scanf("%d", &N);
    scanf("%d", &M);


    int n1, n2;
    scanf("%d %d", &n1, &n2);
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            scanf("%d", &Map[i][j]);
        }
    }

    // 对于每一个顶点，计算经过M条边的最短路径

    // 本身到本身
    for (int i = 0; i < N; ++i) {
        int value = minPath(i, i, i, 0, 0);
        resultMap[i][i] = value;

    }

    // 0 到其他顶点
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int value = minPath(i, j, i, 0, 0);
            resultMap[i][j] = value;
            resultMap[j][i] = value;
        }
    }


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j != N - 1)
                printf("%d ", resultMap[i][j]);
            else
                printf("%d", resultMap[i][j]);
        }
        printf("\n");
    }

    return 0;
}


/*
 *

 输入:
输入范例 例如下面表示总共3个节点和：
3    (表示N=3)
2    (M=2)
下面是N*N的矩阵（此处是一个3*3的矩阵）
3 3
0 2 3
2 0 1
3 1 0
输出:
输出是一个N*N的矩阵（此处根据输入得到是一个3*3的矩阵）
4 4 3
4 2 5
3 5 2
输入范例:
3
2
3 3
0 2 3
2 0 1
3 1 0
输出范例:
4 4 3
4 2 5
3 5 2
 */