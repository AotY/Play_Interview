#include <iostream>
#include <vector>

using namespace std;

// 最优分割

// 依次给出n个正整数A1，A2，… ，An，将这n个数分割成m段，
// 每一段内的所有数的和记为这一段的权重， m段权重的最大值记为本次分割的权重。
// 问所有分割方案中分割权重的最小值是多少？

//第一行依次给出正整数n，m，单空格切分；(n <= 10000, m <= 10000, m <= n)
//第二行依次给出n个正整数单空格切分A1，A2，… ，An  (Ai <= 10000)

// 分割权重的最小值


bool canPartition(vector<int> &nums, int mid, int n, int m) {
    int count = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + nums[i] > mid) //累加和大于 mid，进行一次划分
        {
            sum = nums[i];
            count++;
            if (count > m - 1)    //划分次数大于 m-1,不满足划分
            {
                return false;
            }
        } else {
            sum += nums[i];
        }
    }

    return true;
}

int searchSolution(vector<int> &nums, int left, int right, int n, int m) {

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (canPartition(nums, mid, n, m)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }


    return left;

}

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> nums = vector<int>(n);
    int sum = 0;
    int maxNum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        sum += nums[i];
        maxNum = max(maxNum, nums[i]);
    }


    int res = searchSolution(nums, maxNum, sum, n, m);
    cout << res << endl;

    return 0;
}

/**
5 3
1 4 2 3 5

5

分割成 1  4 |   2   3  |   5  的时候，3段的权重都是5，得到分割权重的最小值。
*/