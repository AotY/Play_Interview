#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//#include <set>

using namespace std;


// 第一题，不超时解法，哎，笔试慌了
// 还是应该按照滑动窗口的方法来解，找大小为k的区间内 isSleeps为0的和的最大值，然后记录 left 和 right的位置
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


    int maxLeft = 0;
    int maxRight = 0;


    int maxZeroScore = 0;

    while (right < n) {

        // 找区间内 0 对于的值最大的
        int zeroScore = 0;
        for (int i = left; i <= right; ++i) {
            if (isSleeps[i] == 0)
                zeroScore += scoreMintues[i];
        }

        if (zeroScore > maxZeroScore) {
            maxZeroScore = zeroScore;
            maxLeft = left;
            maxRight = right;
        }

        left++;
        right++;
    }


    // 计算总得分
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (i >= maxLeft && i <= maxRight)
            res += scoreMintues[i];
        else {
            if (isSleeps[i] == 1)
                res += scoreMintues[i];
        }
    }


    // 可以叫醒一次，输出最大兴趣值

    cout << res << endl;

    return 0;
}



/*
6 3
1 3 5 2 5 4
1 1 0 1 0 0

8 3
1 3 5 2 5 4 10 6 6
1 1 0 1 0 0 1 0 0
*/