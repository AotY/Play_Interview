#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

// 第二题

/**
6
1 0
1 1
2 0
2 1
2 2
6 4

0 0
0 0
0 0
0 0
0 0
0 2
 */


int getMinCount(int n, int k) {
    int res = 0;

    return res;
}


int getMaxCount(int n, int k) {

    int res = 0;

    int half = n / 2;

    if (k <= half ) {
        res = k - 1;
    } else {
        res = n - k;
    }

    return res;
}


int main() {


    int t;

    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n; // n 个房子
        int k; // k 个住户

        cin >> n;
        cin >> k;


        if(n <= 1 || k <= 1) {
            cout << "0 0" << endl;
            continue;
        }

            // 输出 最小满足的房子数
        int minCount = getMinCount(n, k);

        // 最大满足的房子数

        int maxCount = getMaxCount(n, k);

        cout << minCount << " " << maxCount << endl;
    }


    return 0;
}