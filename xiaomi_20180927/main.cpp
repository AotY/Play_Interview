#include <iostream>
#include <vector>

using namespace std;

// mid - 要发放的奖金数
bool canSatisfied(vector<int> &nums, int mid, int n) {
    vector<int> rewards = vector<int>(n, 1);

    // 第一个为 1
    for (int i = 0; i < n; i++) {

        // left
        if (i - 1 >= 0 && nums[i] > nums[i - 1]) {
            if (rewards[i] <= rewards[i - 1])
                rewards[i] = rewards[i - 1] + 1;
        }

        if (i + 1 < n && nums[i] > nums[i + 1])
            if (rewards[i] <= rewards[i + 1])
                rewards[i] = rewards[i + 1] + 1;


    }
    int curSum = 0;
    for (int i = 0; i < n; ++i) {
        curSum += rewards[i];
    }

    return curSum <= mid;

}

int searchSolution(vector<int> &nums, int left, int right, int n) {

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (canSatisfied(nums, mid, n)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }


    return left;

}


int main() {

    int n;
    cin >> n;

    vector<int> nums = vector<int>(n);
    for (int i = 0; i < n; i++) {

        cin >> nums[i];
    }


    int res = searchSolution(nums, n, 1000 * 10, n);
    cout << res << endl;


    return 0;
}

// 10 60 76 66 76 85 55 61 71 84 62