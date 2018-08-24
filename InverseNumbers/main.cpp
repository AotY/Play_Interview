#include <iostream>
#include <vector>

using namespace std;

/**
 * 获取排列的逆序数
 * @param nums 输入nums排列
 * @return 排列的逆序数
 */
int getInverseNumber(const vector<int> &nums, int n) {
    int res = 0;

    // 每次比较一个区间 [i, j] (j 大于 i)，判断[i, j]是否是逆序，也即是是否nums[i] > nums[j]
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] > nums[j])
                res ++;
        }
    }

    // 返回结果
    return res;
}

int main() {

    // 表示该排列有n个数, n <= 100000
    int n;

    cin >> n;

    // 构造一个数组 nums，用于存储排列数据
    vector<int> nums = vector<int>(n);

    // 输入n 个数，保存到数组nums中
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // 调用 getInverseNumber 方法获取排列的逆序数

    int res = getInverseNumber(nums, n);

    cout << res << endl;
    return 0;
}