#include <iostream>
#include <vector>
#include <set>
#include <map>


using namespace std;


class Solution {
private:
    vector<vector<int>> results;

    bool isVectorEqual(const vector<int> &v1, const vector<int> &v2) const {
        if (v1.size() != v2.size())
            return false;
        else {

            map<int, int> map1;
            map<int, int> map2;
            for (int i = 0; i < v1.size(); ++i) {
                if (map1.find(v1[i]) == map1.end()) {
                    map1.insert(make_pair(v1[i], 1));
                } else {
                    map1[v1[i]] += 1;
                }
            }

            for (int i = 0; i < v2.size(); ++i) {
                if (map2.find(v2[i]) == map2.end()) {
                    map2.insert(make_pair(v2[i], 1));
                } else {
                    map2[v2[i]] += 1;
                }
            }

            return map1 == map2;
        }
    }

    bool checkSubset(const vector<int> &sub) {
        for (int i = 0; i < results.size(); ++i) {
            if (isVectorEqual(sub, results[i]))
                return false;
        }

        return true;
    }

    void searchSubset(vector<int> &nums, int index, vector<int> &sub) {

        // 检查是否已经包含该子集
        if (checkSubset(sub))
            results.push_back(sub);

        for (int i = index + 1; i < nums.size(); ++i) {
            sub.push_back(nums[i]);
            searchSubset(nums, i, sub);
            sub.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {

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
    Solution s;
    vector<int> nums = {1, 1, 2, 2};

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