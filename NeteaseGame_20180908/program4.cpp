#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int n = 10;

// 典型回溯法
int main() {

    vector<vector<char>> chess = vector<vector<char>>(10, vector<char>(10));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> chess[i][j];
        }
    }

    int curI;
    int curJ;

    cin >> curI >> curJ;

    //
//    int res = searchPath(chess, curI, curJ);
//    cout << res << endl;
    return 0;
}