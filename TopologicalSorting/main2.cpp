#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;


class Solution {

public:
    // 按照每个节点的入度数量变化来解决该问题，先输出总是先输出入度为零的节点
    vector<int> topological_sort(vector<pair<int, int>> edges) {
        vector<int> res;

        int n = edges.size();

        if (n == 0)
            return res;

        map<int, int> degreeMap;
        map<int, vector<int>> edgeChildrenMap;

        set<int> vectorSet;
        // 1. 记录每个节点的入度个数； 2，记录每个顶点的后继节点
        for (int i = 0; i < n; ++i) {
            int v1 = edges[i].first;
            int v2 = edges[i].second;

            vectorSet.insert(v1);
            vectorSet.insert(v2);

            degreeMap[v2] += 1;

            if (edgeChildrenMap.find(v1) == edgeChildrenMap.end()) {
                vector<int> vs;
                vs.push_back(v2);
                edgeChildrenMap.insert(make_pair(v1, vs));
            } else {
                edgeChildrenMap[v1].push_back(v2);
            }
        }

        queue<int> vectorQueue;

        for (auto v: vectorSet) {
            vectorQueue.push(v);
        }


        vector<bool> mark = vector<bool>(vectorSet.size(), false);

        int index = 0;
        while (!vectorQueue.empty()) {

            int v = vectorQueue.front();
            vectorQueue.pop();

            if (degreeMap.find(v) == degreeMap.end() || degreeMap[v] == 0) {

                // 找到一个根节点，尝试遍历其他节点
                if (!mark[v]) {
                    // 之前没有被访问过

                    if (edgeChildrenMap.find(v) != edgeChildrenMap.end()) {
                        for (int i = 0; i < edgeChildrenMap[v].size(); ++i) {
                            degreeMap[edgeChildrenMap[v][i]] -= 1;
                        }
                    }

                    res.push_back(v);

                    mark[v] = true;
                }

            } else { // 入度不为零的话，重新加入到队列中
                vectorQueue.push(v);
            }

        }


        return res;
    }

};


int main() {

    Solution s;
    vector<pair<int, int>> edges;
    edges.push_back({0, 1});
    edges.push_back({0, 2});
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({2, 4});
    vector<int> res = s.topological_sort(edges);

    for (int i = 0; i < res.size(); ++i) {

        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << endl;


    return 0;
}