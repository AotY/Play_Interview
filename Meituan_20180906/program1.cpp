#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


//  第一题
// 1. 图的遍历
//第一行包含一个整数N，1≤N≤105。

//接下来N-1行，每行包含两个整数X和Y，表示X号节点和Y号节点之间有一条边，1≤X，Y≤N。
// 路径最小值
int N;
int res = 9999999;
vector<vector<bool>> mark;

void searchPath(vector<vector<int>> &roadMap, int curPoint, map<int, int> &pointMap, int curRes) {
    //  如果所有点都已经访问
//    cout << "size: " << pointMap.size() << endl;
    if (pointMap.size() == N) {
        res = min(res, curRes);
        return;
    }

    for (int j = 1; j <= N; ++j) {
        // 尝试访问其他点
        if (!mark[curPoint][j] && roadMap[curPoint][j] == 1) {
            // 标记
            if (pointMap.find(j) != pointMap.end()) {
                pointMap[j] += 1;
            } else {
                pointMap.insert(make_pair(j, 1));
            }

            mark[curPoint][j] = true;

            searchPath(roadMap, j, pointMap, curRes + 1);

            // 回溯
            mark[curPoint][j] = false;

            pointMap[j] -= 1;

            if (pointMap[j] <= 0) {
                pointMap.erase(j);
            }
        }
    }
    return;
}




int main() {

    cin >> N;
    vector<vector<int>> roadMap = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

    int e1;
    int e2;

    for (int i = 0; i < N-1; ++i) {
        // 两边可达
        cin >> e1 >> e2;
        roadMap[e1][e2] = 1;
        roadMap[e2][e1] = 1;
    }

    mark = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));

    // 从 1 号节点出发，访问所有到所有节点

    int curPoint = 1;
    map<int, int> pointMap;
    pointMap.insert(make_pair(curPoint, 1));
    int curRes = 0;

    searchPath(roadMap, curPoint, pointMap, curRes);

    cout << res << endl;

    return 0;
}


