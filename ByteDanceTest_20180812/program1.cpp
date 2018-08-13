#include<iostream>
#include<deque>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;


const int CHOOSE_COUNT = 3;

typedef struct Position {
    int x;
    int y;
};

pair<int, int> getMaxCount(int **arr, int M, int N) {
    int num = 0;
    int max = 0;
    pair<int, int> result = {0, 0};

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1) {
                num++;
                deque<Position> bfsDeque;
                int size = 1;
                int m = i;
                int n = j;
                Position tmpPosition;
                tmpPosition.x = i;
                tmpPosition.y = j;
                arr[i][j] = 0;
                bfsDeque.push_back(tmpPosition);
                while (bfsDeque.size() != 0) {
                    for (int k = 0; k < CHOOSE_COUNT; k++)
                        for (int t = 0; t < CHOOSE_COUNT; t++) {
                            if (!(k == 1 && t == 1)) {
                                if (m - 1 + k >= 0 &&
                                    m - 1 + k < M &&
                                    n - 1 + t >= 0 &&
                                    n - 1 + t < N &&
                                    arr[m - 1 + k][n - 1 + t] == 1
                                        ) {
                                    Position tmpPosition2;
                                    tmpPosition2.x = m - 1 + k;
                                    tmpPosition2.y = n - 1 + t;
                                    bfsDeque.push_back(tmpPosition2);
                                    ++size;
                                    arr[m - 1 + k][n - 1 + t] = 0;

                                }
                            }
                        }
                    Position newPosition = bfsDeque.back();
                    m = newPosition.x;
                    n = newPosition.y;
                    bfsDeque.pop_back();

                }
                if (size > max)
                    max = size;
            }
        }
    }

    result.first = num;
    result.second = max;

    return result;
}


int main() {
    int M, N;
    scanf("%d, %d", &M, &N);
    int **arr = new int *[M];

    char comma;
    getchar();
    for (int i = 0; i < M; i++) {
        arr[i] = new int[N];
        char ch;
        for (int j = 0; j < N - 1; j++) {
            scanf("%c", &ch);
            arr[i][j] = ch - '0';
            scanf("%c", &comma);
        }
        scanf("%c", &ch);
        arr[i][N - 1] = ch - '0';
        getchar();
    }

    pair<int, int> result = getMaxCount(arr, M, N);

    cout << result.first << "," << result.second;
    return 0;
}