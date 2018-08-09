#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 回溯法，求其组合数，然后求按规则能得到的最大值
// 超时
class Solution {

private:
    const int MAX_VALUE = 99999999;
    vector<int> results;

    void searchMaxValue(vector<int> &subInterval) {

        int minValue = MAX_VALUE;
        int sum = 0;
        for (int i = 0; i < subInterval.size(); ++i) {
            sum += subInterval[i];
            minValue = min(minValue, subInterval[i]);
        }
        int res = sum * minValue;
        results.push_back(res);

        return;
    }

public:
    int maxValueByInterval(vector<int> &nums, int n) {
        if (n == 0)
            return 0;

        for (int i = 0; i < n; ++i) {
            vector<int> subInterval;
            subInterval.push_back(nums[i]);
            searchMaxValue(subInterval);
            for (int j = i + 1; j < n; ++j) {
                subInterval.push_back(nums[j]);
                searchMaxValue(subInterval);
            }
        }

        sort(results.begin(), results.end());

        return results[results.size() - 1];
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
    int res = s.maxValueByInterval(nums, n);

    cout << res << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/*
3
6 1 2

 *
 */