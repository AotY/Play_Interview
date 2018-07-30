#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        const int n = nums.size();
        // set_count = n ^ 2
        int set_count = 1 << n;
        vector<vector<int>> res;
        vector<int> t;

        for (int i = 0; i < set_count; i++) {
            t.clear();

            int idx = 0;
            for (int j = i; j > 0; j >>= 1) {
                if ( (j & 1) == 1) // 最后一位为1
                    t.push_back(nums[idx]);
                idx++;
            }
            res.push_back(t);
        }
        return res;
    }
};

int main() {
//    std::cout << "Hello, World!" << std::endl;
    Solution s;
    vector<int> nums = {1, 2, 3};
    cout << s.subsets(nums).size() << endl;
    return 0;
}