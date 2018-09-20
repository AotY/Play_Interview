#include <iostream>
#include <vector>

using namespace std;

static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

int main() {

    int n;

    cin >> n;

    vector<int> nums = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int maxsum = INT_MIN;
    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum > maxsum) {
            maxsum = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        sum = max(sum, nums[i]);
    }

    cout << sum << endl;

    return 0;
}
