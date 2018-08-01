#include <iostream>
#include <vector>

using namespace std;

static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// 动态规划
class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int n = nums.size();
        if (n < 3)
            return false;

        vector<int> memo(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    memo[i] = max(memo[i], 1 + memo[j]);
                    if (memo[i] >= 3)
                        return true;
                }
            }
        }


        return false;
    }
};

int main() {

    Solution s;
    vector<int> nums = {0, 1, 2,1,5,0,3};
    cout<<s.increasingTriplet(nums)<<endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}