#include <iostream>
#include <vector>

using namespace std;

// hard
// 并查集，有向连接
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> root(n + 1, 0), first, second;
        for (auto &edge : edges) {
            if (root[edge[1]] == 0) {
                root[edge[1]] = edge[0];
            } else {
                first = {root[edge[1]], edge[1]};
                second = edge;
                edge[1] = 0;
            }
        }
        for (int i = 0; i <= n; ++i) root[i] = i;
        for (auto &edge : edges) {
            if (edge[1] == 0) continue;
            int x = getRoot(root, edge[0]), y = getRoot(root, edge[1]);
            if (x == y) return first.empty() ? edge : first;
            root[x] = y;
        }
        return second;
    }

    int getRoot(vector<int> &root, int i) {
        return i == root[i] ? i : getRoot(root, root[i]);
    }
};

int main() {


    return 0;
}

