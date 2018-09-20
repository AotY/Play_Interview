#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

// 修改成绩
// 华老师的n个学生参加了一次模拟测验，考出来的分数很糟糕，
// 但是华老师可以将成绩修改为[0,100]中的任意值，所以他想知道，
// 如果要使所有人的成绩的平均分不少于X分，至少要改动多少个人的分数？

/**
 * 第一行一个数T，共T组数据（T≤10）
    接下来对于每组数据：
    第一行两个整数n和X。（1≤n≤1000, 0≤X≤100）
    第二行n个整数，第i个数Ai表示第i个学生的成绩。（0≤Ai≤100）
    输入：
2
5 60
59 20 30 90 100
5 60
59 20 10 10 100

1
5 60
59 20 30 90 100
输出： 共T行，每行一个整数，代表最少的人数。
1
2
 */

// 但是华老师可以将成绩修改为[0,100]中的任意值，所以他想知道，
int modifyCount(vector<int> &nums, int X, int curSum, int index) {
    if (curSum / nums.size() >= X)
        return 0;

    int count = 0;

    curSum += 100 - nums[index];


    count = 1 + modifyCount(nums, X, curSum, index + 1);

    return count;
}

int main() {


    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int n;
        int X;
        cin >> n >> X;
        vector<int> nums = vector<int>(n);
        int curSum = 0;
        for (int j = 0; j < n; ++j) {
            cin >> nums[j];
            curSum += nums[j];
        }

        // 计算如果要使所有人的成绩的平均分不少于X分，至少要改动多少个人的分数？
        // 从最小的成绩开始修改，并且，修改为最大分数
        sort(nums.begin(), nums.end());
        int res = modifyCount(nums, X, curSum, 0);

        cout << res << endl;
    }

    return 0;
}