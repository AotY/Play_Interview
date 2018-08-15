#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int dp(vector<int> &aArr, vector<int> &bArr, int n) {

    vector<vector<int>> memoA = vector<vector<int>>(n, vector<int>(n));
    vector<vector<int>> memoB = vector<vector<int>>(n, vector<int>(n));

    // 换为两个一位数组
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i == j) {
                memoA[i][j] = aArr[j];
                memoB[i][j] = bArr[j];
            } else {
                memoA[i][j] = max(aArr[j], memoA[i][j - 1]);
                memoB[i][j] = min(bArr[j], memoB[i][j - 1]);
            }

            if (memoA[i][j] < memoB[i][j])
                res++;
        }
    }


    return res;

}

int main() {

    int n;

    cin >> n;
    vector<int> aArr = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> aArr[i];
    }

    vector<int> bArr = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> bArr[i];
    }

    int res = dp(aArr, bArr, n);
    cout << res << endl;

    return 0;
}

/*

4
3 2 1 2
3 3 3 3

5


3
3 2 1
3 3 3

a序列区间的最大值小于b序列区间的最小值


 */