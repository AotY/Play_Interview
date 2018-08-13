#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// 用搜索的方法试试。当 maxA > minB的时候，只有一种选择就是同时向a和b移动一位；如果是maxA < minB是，有两种选择，一种是
// r同时向右移动一位（l）不变，另一种是l向右移动一位

int search(const vector<int> &aArr, const vector<int> &bArr, int maxA, int minB, int left, int right) {
    if (left >= aArr.size()) //  || right >= aArr.size()
        return 0;

    int res = 0;


    if (maxA >= minB) {
        if (left + 1 < aArr.size()) {
            maxA = aArr[left + 1];
            minB = bArr[left + 1];
        }
        res += search(aArr, bArr, maxA, minB, left + 1, right + 1);

    } else {
        // maxA < minB
        res++;
        // 两种搜索策略
        // 1. 向右扩展一位
        if (right < aArr.size() - 1) {
            int tmpMaxA = maxA;
            int tmpMinB = minB;
            if (right + 1 < aArr.size()) {
                tmpMaxA = max(tmpMaxA, aArr[right + 1]);
                tmpMinB = min(tmpMinB, bArr[right + 1]);
            }
            res += search(aArr, bArr, tmpMaxA, tmpMinB, left, right + 1);
        } else {
            // 只有当right不能继续时才有这个策略
            if (left + 1 < aArr.size()) {
                maxA = max(maxA, aArr[left + 1]);
                minB = min(minB, bArr[left + 1]);
            }
            res += search(aArr, bArr, maxA, minB, left + 1, right);
        }
    }


    return res;
}

int main() {

    int n;

    cin >> n;
    vector<int> aArr = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> aArr[i];
    }

    vector<int> bArr = vector<int>(n);
    for (int i = 0; i < n; ++i) {
        cin >> bArr[i];
    }

    int res = search(aArr, bArr, aArr[0], bArr[0], 0, 0);
    cout << res << endl;

    return 0;
}

/*

4
3 2 1 2
3 3 3 3

5


3
3 2 1
3 3 3

a序列区间的最大值小于b序列区间的最小值


 */