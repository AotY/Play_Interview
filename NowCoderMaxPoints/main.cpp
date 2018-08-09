#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> maxPoints(const vector<pair<int, int>> &points, int n) {
        if (n == 1)
            return points;
        vector<pair<int, int>> res;
        for (int i = 0; i < n; i++) {
            pair<int, int> curPoint = points[i];
            bool isMax = true;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (points[j].first >= curPoint.first && points[j].second >= curPoint.second) {
                        isMax = false;
                        break;
                    }
                }
            }
            if (isMax)
                res.push_back(curPoint);
        }
        return res;
    }
};

bool pointCompare(const pair<int, int> &point1, const pair<int, int> &point2) {
    if (point1.first == point2.first)
        return point1.second < point2.second;
    else
        return point1.first < point2.first;
}


int main() {

    int n;
    cin >> n;
    int x, y;
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }
    Solution s;
    sort(points.begin(), points.end(), pointCompare);
    // 还要按照 x  从小到大排序。。。[Facepalm]
    vector<pair<int, int>> res = s.maxPoints(points, n);
    //sort(res.begin(), res.end(), pointCompare);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << " " << res[i].second << endl;
    }
    return 0;
}

