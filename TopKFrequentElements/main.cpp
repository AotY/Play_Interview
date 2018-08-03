#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;


bool countPairCompare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
}

// 有复数，不能用桶方法，可以试试 map
class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector<int> results;

        int n = nums.size();

        if (n == 0 || n < k)
            return results;

        unordered_map<int, int> countUnorderedMap;

        for (int i = 0; i < n; ++i) {
            if (countUnorderedMap.count(nums[i]))
                countUnorderedMap[nums[i]]++;
            else
                countUnorderedMap[nums[i]] = 1;
        }

        vector<pair<int, int>> pairVectors;
        for (auto iter = countUnorderedMap.begin(); iter != countUnorderedMap.end();
             ++iter) {
            pairVectors.push_back(make_pair(iter->first, iter->second));
        }

        sort(pairVectors.begin(), pairVectors.end(), countPairCompare);

        for (int i = 0; i < k; ++i) {
            results.push_back(pairVectors[i].first);
        }
        return results;
    }
};

int main() {

    Solution s;
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    s.topKFrequent(nums, 2);
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}