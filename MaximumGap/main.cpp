#include <iostream>
#include <vector>

using namespace std;


// 超内存
class Solution {
private:

    const int MAX_SIZE = 99999999 + 1;

    vector<int> bulk = vector<int>(MAX_SIZE, 0);

    vector<int> bulkSort(const vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            bulk[nums[i]]++;
        }

        vector<int> sortNums;

        for (int j = 0; j < MAX_SIZE; ++j) {
            while (bulk[j]-- > 0)
                sortNums.push_back(j);
        }

        return sortNums;
    }

public:
    int maximumGap(vector<int> &nums) {
        int n = nums.size();

        if (n <= 1)
            return 0;

        int res = 0;


        // 排序，需要线性时间，并且保证元素非负，可以考虑使用桶排序
        vector<int> sortNums = bulkSort(nums);

        // 找相邻两个元素的最大差
        for (int i = 0; i < sortNums.size() - 1; ++i) {
            res = max(res, sortNums[i + 1] - sortNums[i]);
        }

        return res;
    }
};

int main() {

    Solution s;

    vector<int> nums = {3, 6, 9, 1};
    cout << s.maximumGap(nums) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}