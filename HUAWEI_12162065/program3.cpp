#include<iostream>

using namespace std;

// 野蛮生长

int res(int M, int N) {
    int sum = 0;
    if (N <= 4) {
        sum = M + N * M;
    } else {
        sum += res(M, N - 4) + res(M, N - 1);
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int m, n;
        cin >> m >> n;
        cout << res(m, n) << endl;
    }

    return 0;
}