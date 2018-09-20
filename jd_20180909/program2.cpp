#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <queue>

using namespace std;

// 第二题
// 给定一张包含N个点、M条边的无向图，每条边连接两个不同的点，
// 且任意两点间最多只有一条边。对于这样的简单无向图，
// 如果能将所有点划分成若干个集合，
// 1. 使得任意两个同一集合内的点之间没有边相连，
// 2. 任意两个不同集合内的点之间有边相连，
// 则称该图为完全多部图。
// 现在你需要判断给定的图是否为完全多部图

// 第一行输入一个整数T表示数据组数，1≤T≤10。
// 每组数据格式为：
// 第一行包含两个整数N和M，1≤N≤1000，0≤M≤N(N-1)/2；
// 接下来M行，每行包含两个整数X和Y，表示第X个点和第Y个点之间有一条边，1≤X，Y≤N。

// 每组输出占一行，如果给定的图为完全多部图，输出Yes，否则输出No。


// 判断uMap是否为完全多部图
// 感觉只能二分
//0为白色，1为黑色

const int N = 1010;

int color[N];
int graph[N][N];


bool bfs(int s, int n) {
    queue<int> q;
    q.push(s);
    color[s] = 1;
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (graph[from][i] && color[i] == -1) {
                q.push(i);
                color[i] = !color[from];//染成不同的颜色
            }
            if (graph[from][i] && color[from] == color[i])//颜色有相同，则不是二分图
                return false;
        }
    }
    return true;
}

int main() {

    int T;
    cin >> T;

    for (int k = 0; k < T; ++k) {

        int n, m, a, b, i, j;

//        memset(color, -1, sizeof(color));

        cin >> n >> m;

        for (i = 1; i <= n; ++i) {
            color[i] = -1;
            for (j = 1; j <= n; ++j) {
                graph[i][j] = 0;
            }
        }


        for (i = 0; i < m; i++) {
            cin >> a >> b;
            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        bool flag = false;

        for (i = 1; i <= n; i++)
            if (color[i] == -1 && !bfs(i, n)) {
                //遍历各个连通分支
                flag = true;
                break;
            }

        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }

    return 0;
}
/*

2
5 7
1 3
1 5
2 3
2 5
3 4
4 5
3 5
4 3
1 2
2 3
3 4


Yes
No
*/