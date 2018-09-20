#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main() {

    int N;
    cin >> N;

    vector<int> nums = vector<int>(N);
    map<int, int> numsMap;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        numsMap[nums[i]] += 1;
    }


    vector<pair<int, int>> res;

    // [left, right] 为满足题意的区间
    int left = 0;
    int right = 0;

    map<int, int> curMap;
    while (right < N) {
        curMap[nums[right]] += 1;

        if (curMap.size() == numsMap.size()) {
            // 尝试移动left, 得到最小的区间

            int tmpLeft = left;
            if (curMap[nums[tmpLeft]] - 1 > 0) {
                curMap[nums[tmpLeft]] -= 1;
                tmpLeft++;
            }

            res.push_back(make_pair(tmpLeft + 1, right + 1));

            if (tmpLeft == left) {
                if (curMap[nums[left]] <= 0)
                    curMap.erase(nums[left]);

                left++;
            } else {
                left = tmpLeft;
            }
        }
        right++;
    }


    // 删除一些区间
    int lastLeft = -1;
    for (int i = 0; i < res.size(); ++i) {
        if (lastLeft == res[i].first)
            continue;
        cout << "[" << res[i].first << "," << res[i].second << "]";
        if (i != res.size() - 1)
            cout << " ";
        lastLeft = res[i].first;
    }
    cout << endl;

    return 0;
}