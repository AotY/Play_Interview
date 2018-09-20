#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>


using namespace std;


int res = 99999999;

bool searchSolution(int x, int y, int turn, int wx, int wy) {

    if (x < 0 || y < 0)
        return false;

    if (x == 0 && y == 0) {
        cout << wx << endl;
        res = min(res, wx);
        return true;
    }

    if (searchSolution(x - turn, y, turn + 1, wx + 1, wy)) {
        return true;
    }

    return searchSolution(x, y - turn , turn + 1, wx, wy + 1);
}


int main() {

    int x, y; // 小Q, 牛牛的分数

    cin >> x >> y;


    // 输出最少的轮次

    bool flag = searchSolution(x, y, 1, 0, 0);

    if (flag) {
        cout << res << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}