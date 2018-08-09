#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int lli;

// 没有银弹，两层循环
class Solution {

private:
    const int MAX_VALUE = 99999999;
public:
    lli maxValueByInterval(vector<int> &nums, int n) {
        if (n == 0)
            return 0;

        int left = 0;
        int right = 0;

        lli res = 0;
        while (left < n) {
            lli sum = 0;
            int minVal = nums[left];
            while (right < n) {
                sum += nums[right];
                minVal = min(minVal, nums[right]);

                res = max(res, sum * minVal);

                right ++;
            }

            left ++;
            right = left;
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
//        cin >> val;
        scanf("%d", &val);
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
6 2 1

 *
 */