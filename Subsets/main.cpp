#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class Solution {
private:
    vector<vector<int>> results;

    void searchSubset(vector<int> &nums, int index, vector<int>& sub) {

        results.push_back(sub);

        for (int i = index + 1; i < nums.size(); ++i) {
            sub.push_back(nums[i]);
            searchSubset(nums, i, sub);
            sub.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {

        int n = nums.size();

        results.push_back(vector<int>());
        if (n == 0)
            return results;

        for (int i = 0; i < n; ++i) {
            vector<int> sub;
            sub.push_back(nums[i]);
            searchSubset(nums, i, sub);
        }
        return results;
    }

};

int main() {
//    std::cout << "Hello, World!" << std::endl;
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    cout << s.subsets(nums).size() << endl;
    return 0;
}