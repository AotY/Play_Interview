#include <iostream>
#include <vector>

using namespace std;

static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        // 
        for (int a : nums) {
            if (a <= m1)
                m1 = a;
            else if (a <= m2)
                m2 = a;
            else
                return true;
        }
        return false;
    }
};

int main() {

    Solution s;
    vector<int> nums = {5,4,3,6,1};
    cout << s.increasingTriplet(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}