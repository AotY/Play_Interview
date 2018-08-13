#include<iostream>
#include<deque>

using namespace std;
typedef struct pos {
    int x;
    int y;
} p;

void calculate(int **arr, int M, int N) {
    int num = 0;
    int max = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1) {
                num++;
                deque<p> bfs;
                int size = 1;
                int m = i;
                int n = j;
                p tmp;
                tmp.x = i;
                tmp.y = j;
                arr[i][j] = 0;
                bfs.push_back(tmp);
                while (bfs.size() != 0) {
                    for (int k = 0; k < 3; k++)
                        for (int t = 0; t < 3; t++) {
                            if (!(k == 1 && t == 1)) {
                                if (m - 1 + k >= 0 && m - 1 + k < M && n - 1 + t >= 0 && n - 1 + t < N &&
                                    arr[m - 1 + k][n - 1 + t] == 1) {
                                    p tmp;
                                    tmp.x = m - 1 + k;
                                    tmp.y = n - 1 + t;
                                    bfs.push_back(tmp);
                                    ++size;
                                    arr[m - 1 + k][n - 1 + t] = 0;

                                }
                            }
                        }
                    p new_pos = bfs.back();
                    m = new_pos.x;
                    n = new_pos.y;
                    bfs.pop_back();

                }
                if (size > max) max = size;
            }

        }
    }
    cout << num << "," << max;
}


int main() {
    int M, N;
    char sym;
    scanf("%d,%d", &M, &N);
    getchar();
    int **a = new int *[M];
    for (int i = 0; i < M; i++) {
        a[i] = new int[N];
        char tmp;
        for (int j = 0; j < N - 1; j++) {
            scanf("%c", &tmp);
            a[i][j] = tmp - '0';
            scanf("%c", &sym);
        }
        scanf("%c", &tmp);
        a[i][N - 1] = tmp - '0';
        getchar();

    }

    calculate(a, M, N);
    return 0;
}