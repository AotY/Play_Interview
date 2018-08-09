#include <iostream>
#include <vector>

using namespace std;

typedef long long int lli;

// 认为当前是最小值，向两边扩展
int main() {

    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int left = 0;
    int right;

    lli res = 0;

    lli sum;

    // 以nums[left] 作为最小值，向两边扩展
    while (left < n) {
        sum = nums[left];

        // 左
        for (int i = left - 1; i >= 0; --i) {
            if (nums[i] < nums[left])
                break;

            sum += nums[i];
        }

        // 右
        for (int j = left + 1; j < n; ++j) {
            if (nums[j] < nums[left])
                break;
            sum += nums[j];
        }

        lli mul = sum * nums[left];

        if (res < mul)
            res = mul;

        left++;
    }

    cout << res << endl;
    return 0;
}

/*
测试用例:
100
94 11 62 89 28 74 11 45 37 6 95 66 28 58 47 47 87 88 90 15 41 8 87 31 29 56 37 31 85 26 13 90 94 63 33 47 78 24 59 53 57 21 89 99 0 5 88 38 3 55 51 10 5 56 66 28 61 2 83 46 63 76 2 18 47 94 77 63 96 20 23 53 37 33 41 59 33 43 91 2 78 36 46 7 40 3 52 43 5 98 25 51 15 57 87 10 10 85 90 32

对应输出应该为:

23055

3
6 2 1

 *
 */