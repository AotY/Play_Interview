#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

const int MAX_SIZE = 500000 + 1;


class Solution {
public:
    int maxPoints(Point points[], int n, Point res[]) {
        if (n == 1) {
            res[0].x = points[0].x;
            res[0].y = points[0].y;
            return 1;
        }
        int count = 0;
        int maxY = -9999999;
        for (int i = (n - 1); i >= 0; i--) {
            if (points[i].y > maxY) {
                maxY = points[i].y;
                res[count].x = points[i].x;
                res[count].y = points[i].y;
                count++;
            }
        }
        return count;
    }
};

bool pointCompare(const Point &point1, const Point &point2) {
    if (point1.x == point2.x)
        return point1.y < point2.y;
    else
        return point1.x < point2.x;
}


int main() {

    int n;
    cin >> n;

    Point *points = new Point[n];
    Point *res = new Point[n];
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points, points + n, pointCompare);
    Solution s;

    int count = s.maxPoints(points, n, res);

    for (int i = count - 1; i >= 0; i--) {
        cout << res[i].x << " " << res[i].y << endl;
    }

    delete[] points;
    delete[] res;
    return 0;
}

/*
 *
5
5 3
1 2
9 0
4 6
7 5
 */
