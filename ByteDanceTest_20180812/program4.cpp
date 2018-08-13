#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

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


    int res = 0;
    // 如果只取一个数
//    for (int i = 0; i < n; ++i) {
//        if (aArr[i] < bArr[i])
//            res++;
//    }

    // 考虑多个数，在[l, r]区间里满足 a的最大值小b的最小值
    int l = 0;
    int r = 0;

    int maxA;
    int minB;
    while (l < n) {

        maxA = -999999999;
        minB = 999999999;

        for (int i = l; i <= r; ++i) {
            maxA = max(maxA, aArr[i]);
            minB = min(minB, bArr[i]);
        }

        if (maxA < minB) {
            res++;
            r++;
            if (r >= n) {
                r = n - 1;
                l++;
            }
        } else {
            // A 大了
            // && aArr[l + 1] < maxA
            l++;
            r = l;
        }
    }


    cout << res << endl;

    return 0;
}