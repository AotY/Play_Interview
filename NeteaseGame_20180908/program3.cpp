#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <math.h>

using namespace std;

// 尝试分解为两个相等的数

map<char, int> numMap = {
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'A', 10},
        {'B', 11},
        {'C', 12},
        {'D', 13},
        {'E', 14},
        {'F', 15}
};


int trySplit(int x, int y, string  &z, int index) {

    // left
    int leftNum = 0;
    int powNum = 0;
    for (int i = index; i >= 0; --i) {
        // based on x
        int num = numMap[z[i]];
        if (num >= x) {
            return trySplit(x, y, z, index - 1);
        } else {
            leftNum += (int) pow(x, powNum) * num;
            powNum ++;
        }

    }


    // right

    int rightNum = 0;
    powNum = 0;
    for (int i = z.size()-1; i > index; --i) {
        // based on y
        int num = numMap[z[i]];
        if (num >= y) {
            return trySplit(x, y, z, index + 1);
        } else {
            rightNum += (int) pow(y, powNum) * num;
            powNum ++;
        }
    }


    if (leftNum == rightNum)
        return leftNum;
    else {
        return trySplit(x, y, z, index + 1);
    }
}

int main() {
    int T;
    cin >> T;


    for (int i = 0; i < T; ++i) {
        int x;
        int y;
        string z;

        cin >> x;
        cin >> y;
        cin >> z;



        int res = trySplit(x, y, z, 0);

        cout << res << endl;

    }

    return 0;
}

/*
1
13 7 1016


 */