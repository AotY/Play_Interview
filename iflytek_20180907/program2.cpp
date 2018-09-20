#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

// 杀手
// 有n个杀手排成一行，每个杀手都有一个不同的编号(编号为1-n)，
// 在每个夜晚，杀手都会行动，如果某个杀手编号大于他右边的杀手的编号，
// 他就会杀死他右边的杀手，杀手是的行动是瞬间的，因此一个人可能某一个夜晚既杀死了别人又被别人杀死，
// 例如3,2,1这个顺序，在第一个夜晚2会杀死1，同时3也会杀死2。
// 显而易见，一段时间之后，就不会有人杀或被杀，平安夜也就到来了，请问在平安夜之前有多少个夜晚。

/**
 * 输入：
    输入第一行是一个整数n（1≤n≤100000）,表示杀手的数量。
    接下来一行有n个数，是一个1-n的全排列。

输出：
    输出包含一个整数，表示平安夜之前经历了多少个夜晚。
10
10 9 7 8 6 5 3 4 2 1

2

补充样例
输入样例2
6
1 2 3 4 5 6
输出样例2
0

样例解释：
样例1中杀手的变化为[10 9 7 8 6 5 3 4 2 1]->[10 8 4]->[10]，故答案为2。
 */

int tryKilling(vector<int> &nums, int n, vector<bool> &mark) {

    int res = 0;
    int lastCount = nums.size();
    while (true) {

        // 尝试杀人
        int left = 0;
        while (left < n && mark[left])
            left ++;

        int right = left + 1;
        while (right < n && mark[right])
            right ++;

        vector<int> erase_index;
        erase_index.clear();

        while (right < n && left < n) {

            if (nums[left] > nums[right]) {
                erase_index.push_back(right);
            }

            left = right;
            right ++;
            while (right < n && mark[right])
                right ++;
        }

        if (erase_index.size() == 0)
            break;

        for (int i = 0; i < erase_index.size(); ++i) {
            mark[erase_index[i]] = true;
        }
        res ++ ;

    }
    return res;
}


int main() {
    int n;

    cin >> n;

    vector<int> nums = vector<int>(n);

    vector<bool> mark = vector<bool>(n, false);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int res = tryKilling(nums, n, mark);

    cout << res << endl;
    return 0;
}