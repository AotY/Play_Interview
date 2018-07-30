#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    int searchPos(int arr[], int target, int left, int right) {
        if (target > arr[right])
            return right + 1;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (arr[mid] == target)
                return mid;
            else if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

public:

    int lengthOfLIS(vector<int> &nums) {//O(nlogn)
        int n = nums.size();
        if (!n)
            return 0;
        int searchArr[n];
        int l;

        // 初始化
        searchArr[0] = nums[0];
        l = 0;
        for (int i = 1; i < n; ++i) {
            int pos = searchPos(searchArr, nums[i], 0, l);
            searchArr[pos] = nums[i];
            l = max(l, pos);
        }
        return l + 1;
    }

};

int main() {
    Solution s;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << s.lengthOfLIS(nums) << endl;


    return 0;
}