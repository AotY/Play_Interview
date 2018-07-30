#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class Solution {
private:
    vector<bool> isVisited;
    vector<vector<int>> results;


public:


    void searchPermutaions(vector<int> &nums, int index, vector<int> &p) {
        if (index == nums.size()) {
            results.push_back(p);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (!isVisited[i]) {
                isVisited[i] = true;
                p.push_back(nums[i]);
                searchPermutaions(nums, index + 1, p);
                // 重要的两步
                isVisited[i] = false;
                p.pop_back();
            }
        }

    }

    vector<vector<int>> permute(vector<int> &nums) {
        isVisited = vector<bool>(nums.size(), false);

        for (int i = 0; i < nums.size(); ++i) {
            isVisited[i] = true;
            vector<int> p;
            p.clear();
            p.push_back(nums[i]);
            searchPermutaions(nums, 1, p);
            isVisited[i] = false;
        }

        return results;
    }
};

int main() {

    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> results = s.permute(nums);

    for (auto result: results) {
        for (auto i: result) {
            cout << i << " ";
        }
        cout << endl;
    }


//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
