#include <iostream>
#include <vector>
#include <ctime>
#include <map>
#include <unordered_map>

using namespace std;


// 著名的主元素问题，map计数
static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    int majorityElement(vector<int> &nums) {
        map<int, int> M;
        map<int, int>::iterator it;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            it = M.find(nums[i]);

            if (it == M.end())
                M.insert(map<int, int>::value_type(nums[i], 1));
            else
                it->second++;

            if ((it->second) > n / 2)
                return it->first;
        }
        return nums[0];

    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 3, 4, 1, 1, 1, 4, 3, 1};
    cout << s.majorityElement(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}