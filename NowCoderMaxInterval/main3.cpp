#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int lli;

// 动态规划方法
// 超内存
class Solution {

private:
    const int MAX_VALUE = 99999999;

    lli searchMaxValue(vector<int> &nums, int left, int right) {

        int minValue = MAX_VALUE;
        lli sum = 0;
        for (int i = left; i <= right; ++i) {
            sum += nums[i];
            minValue = min(minValue, nums[i]);
        }
        lli res = sum * minValue;
        return res;
    }

    lli max3(lli a, lli b, lli c) {
        return max(max(a, b), c);
    }

public:
    lli maxValueByInterval(vector<int> &nums, int n) {
        if (n == 0)
            return 0;

        vector<vector<lli>> memo = vector<vector<lli>>(n, vector<lli>(n , 0));
        memo[n - 1][n - 1] = nums[n - 1] * nums[n - 1];

        lli res = 0;
        // M(i, j) 以 (i, j) 的区间能得到的最大值
        for (int left = n - 2; left >= 0; --left) {
            for (int right = left + 1; right < n; ++right) {
                memo[left][right] = max3(searchMaxValue(nums, left, right),
                                         nums[left] * nums[left], memo[left + 1][right]);
                res = max(res, memo[left][right]);
            }
        }
        return res;
    }

};

int main() {

    int n;
    cin >> n;
    vector<int> nums;

    int val;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        nums.push_back(val);
    }

    Solution s;
    lli res = s.maxValueByInterval(nums, n);

    cout << res << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/*
测试用例:
100
94 11 62 89 28 74 11 45 37 6 95 66 28 58 47 47 87 88 90 15 41 8 87 31 29 56 37 31 85 26 13 90 94 63 33 47 78 24 59 53 57 21 89 99 0 5 88 38 3 55 51 10 5 56 66 28 61 2 83 46 63 76 2 18 47 94 77 63 96 20 23 53 37 33 41 59 33 43 91 2 78 36 46 7 40 3 52 43 5 98 25 51 15 57 87 10 10 85 90 32

对应输出应该为:

23055

3
6 1 2

 *
 */