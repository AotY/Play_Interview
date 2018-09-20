#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;

    cin >> n;

    vector<int> nums = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int res = -9999999;

    vector<int> memo = vector<int>(n, INT_MIN);

    //
    for (int i = 0; i < n; i++) {
        memo[i] = nums[i];
        for (int j = i + 1; j < n; ++j) {
            memo[j] = nums[j] + memo[j - 1];
            res = max(res, memo[j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        res = max(res, nums[i]);
    }
    cout << res << endl;

    return 0;
}
