#include <iostream>
#include <vector>
#include <ctime>
#include <map>
#include <unordered_map>

using namespace std;


// 著名的主元素问题，map计数
static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int cnt = 0;
        int vote;
        // 这个思路很棒。
        for (int i = 0; i < nums.size(); i++) {

            if (cnt == 0)
                vote = nums[i]; //

            if (vote == nums[i])
                cnt++;
            else
                cnt--;

        }

        cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == vote)
                cnt++;
        }

        if (cnt >= (nums.size() / 2))
            return vote;
        else
            return 0;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 3, 1, 1, 3};
    cout << s.majorityElement(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}