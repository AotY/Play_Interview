#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <set>

using namespace std;


// 第一题， 暴力方法，时间超时
int main() {

    int n, k; // 课持续分钟，k

    cin >> n >> k;

    // 对每分钟可的兴趣
    vector<int> scoreMintues = vector<int>(n);

    for (int i = 0; i < n; ++i) {
        cin >> scoreMintues[i];
    }


    // 对每分钟是否会睡着
    vector<int> isSleeps = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> isSleeps[i];
    }


    // 16  保证 k 窗口内的值最大

    int left = 0;
    int right = left + k - 1;
    int maxScore = 0;
    int maxLeft = 0;
    int maxRight = 0;


    //  尝试每一次位置叫醒
    for (int i = 0; i < n - k + 1; ++i) {
        // 叫醒 i ... i + k位置
        int tmpScore = 0;

        for (int j = 0; j < n; ++j) {
            if (j >= i && j < i + k) {
                tmpScore += scoreMintues[j];
            } else {
                if (isSleeps[j] == 1)
                    tmpScore += scoreMintues[j];
            }
        }

        maxScore = max(maxScore, tmpScore);
    }

    // 可以叫醒一次，输出最大兴趣值

    cout << maxScore << endl;

    return 0;
}



/*
6 3
1 3 5 2 5 4
1 1 0 1 0 0
*/