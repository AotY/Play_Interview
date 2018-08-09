//#include <vector>
#include <iostream>
//#include <algorithm>

//#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x;
    int y;
};

//const int MAX_SIZE = 500000 + 1;
Point points[500001];

void maxPoints(int n) {

    cout << points[n - 1].x << " " << points[n - 1].y << endl;
    int maxX = points[n - 1].x;
    for (int i = (n - 2); i >= 0; i--) {
        if (points[i].x > maxX) {
            maxX = points[i].x;
            cout << points[i].x << " " << points[i].y << endl;
        }
    }
}

// 按 y 升序排序
bool pointCompare(const Point &point1, const Point &point2) {
    if (point1.y == point2.y)
        return point1.x < point2.x;
    else
        return point1.y < point2.y;
}


int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
//        cin >> points[i].x >> points[i].y;
        scanf("%d%d", &points[i].x, &points[i].y); // 这个不超时
    }

    sort(points, points + n, pointCompare);

    maxPoints(n);
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
