#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 *  输入描述:
    输入包括五行。
    第一行包括一个整数n(2 <= n <= 50), 表示矩形的个数。
    第二行包括n个整数x1[i](-10^9 <= x1[i] <= 10^9),表示左下角的横坐标。
    第三行包括n个整数y1[i](-10^9 <= y1[i] <= 10^9),表示左下角的纵坐标。
    第四行包括n个整数x2[i](-10^9 <= x2[i] <= 10^9),表示右上角的横坐标。
    第五行包括n个整数y2[i](-10^9 <= y2[i] <= 10^9),表示右上角的纵坐标。

    输出描述:
    输出一个正整数, 表示最多的地方有多少个矩形相互重叠,如果矩形都不互相重叠,输出1。
 */


struct Rect {
    int x1;
    int y1;

    int x2;
    int y2;

    int overlappingCount; // 重叠次数

    set<int> rectIndexSet;

    Rect() : x1(0), y1(0), x2(0), y2(0), overlappingCount(0) {};
};


int getOverlappingCount(vector<Rect> &rects, int n) {
    if (n <= 1)
        return 1;

    vector<Rect> overlappingRects;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;

            int overX1 = max(rects[i].x1, rects[j].x1);
            int overY1 = max(rects[i].y1, rects[j].y1);

            int overX2 = min(rects[i].x2, rects[j].x2);
            int overY2 = min(rects[i].y2, rects[j].y2);

            // 不相交
            if (overX1 > overX2 || overY1 > overY2)
                continue;

            // 相交
            Rect overRect;
            overRect.x1 = overX1;
            overRect.y1 = overY1;

            overRect.x2 = overX2;
            overRect.y2 = overY2;

            if (overRect.rectIndexSet.find(i) != overRect.rectIndexSet.end()) {
                overRect.overlappingCount++;
                overRect.rectIndexSet.insert(i);

            }

            if (overRect.rectIndexSet.find(j) != overRect.rectIndexSet.end()) {
                overRect.overlappingCount++;
                overRect.rectIndexSet.insert(j);
            }

            overlappingRects.push_back(overRect);
        }

    }

    int res = 0;

    for (int k = 0; k < overlappingRects.size(); ++k) {
        res = max(res, overlappingRects[k].overlappingCount);
    }

    return res;
}

bool rectCompare(const Rect &r1, const Rect &r2) {
    if (r1.x1 != r2.x1)
        return r1.x1 < r2.x1;
    else
        return r1.y1 < r2.y1;
}


int main() {

    int n;
    cin >> n;

    vector<Rect> rects = vector<Rect>(n, Rect());
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0)
                cin >> rects[j].x1;
            else if (i == 1)
                cin >> rects[j].y1;
            else if (i == 2)
                cin >> rects[j].x2;
            else
                cin >> rects[j].y2;
        }
    }

    sort(rects.begin(), rects.end(), rectCompare);
    int res = getOverlappingCount(rects, n);

    cout << res << endl;
    return 0;
}