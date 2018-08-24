#include <iostream>
#include <vector>
#include <set>
#include <map>


using namespace std;
// 先排序，就可以使用set 进行去重了

class Solution {

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        if (nums.empty())
            return vector<vector<int>>();

        set<vector<int>> resultsSet;
        resultsSet.insert(vector<int>());

        sort(nums.begin(), nums.end());

        vector<int> sub;
        int begin = 0;

        subsetsWithDupCore(nums, sub, resultsSet, begin);

        return vector<vector<int>>(resultsSet.begin(), resultsSet.end());
    }

private:
    void subsetsWithDupCore(const vector<int> &nums, vector<int> &sub, set<vector<int>> &resultsSet, int begin) {

        for (int i = begin; i < nums.size(); ++i) {
            sub.push_back(nums[i]);
            resultsSet.insert(sub);
            subsetsWithDupCore(nums, sub, resultsSet, i + 1);
            sub.pop_back();
        }
    }
};


int main() {
    Solution s;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> results = s.subsetsWithDup(nums);

    for (int i = 0; i < results.size(); ++i) {
        for (int j = 0; j < results[i].size(); ++j) {
            cout << results[i][j];
        }
        cout << endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}