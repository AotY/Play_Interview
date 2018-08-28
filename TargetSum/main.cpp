#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;



class Solution {

private:

    // dp[index][curSum]
    map<pair<int, int>, int> dp;

    int searchSum(const vector<int> &nums, int index, int curSum, int S) {

        if (index >= nums.size()) {
            if (curSum == S)
                return 1; // 找到满足题意的路径
            return 0 ;
        }


        map<pair<int, int>, int>::iterator it = dp.find(make_pair(index, curSum));
        if (it != dp.end())
            return (*it).second;

        int res = 0;

        // +
        res = res + searchSum(nums, index + 1, nums[index] + curSum, S);

        // -
        res = res + searchSum(nums, index + 1, -nums[index] + curSum, S);


        dp.insert(make_pair(make_pair(index, curSum), res));

        return res;
    }

public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int n = nums.size();
        if (n == 0)
            return 0;


        // dp[index][curSum] ： 从 index...n 满足curSum的个数
//        dp = vector<vector<int>>(n, vector<int>(S + 1, -1));

        int res = searchSum(nums, 0, 0, S);

        return res;

    }
};

int main() {

    Solution s;

    vector<int> nums = {1, 1, 1, 1, 1};
    int S = 3;
    cout << s.findTargetSumWays(nums, S) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}