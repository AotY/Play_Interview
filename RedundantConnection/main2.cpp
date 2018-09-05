#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        vector<int> parent(2001, 0);

        for (int i = 0; i < 2001; i++)
            parent[i] = i;

        for (int i = 0; i < edges.size(); i++) {

            int p1 = find(parent, edges[i][0]);
            int p2 = find(parent, edges[i][1]);

            if (p1 == p2)
                return edges[i];
            else
                parent[p1] = p2;
        }
        return vector<int>{0, 0};
    }

    int find(vector<int> &parent, int k) {
        if (parent[k] != k) {
            parent[k] = find(parent, parent[k]);
        }
        return parent[k];
    }
};

int main() {

    Solution s;
    vector<vector<int>> edges = {{1, 2},
                                 {1, 3},
                                 {2, 3}};
    vector<int> res = s.findRedundantConnection(edges);
    cout << res[0] << ", " << res[1] << endl;

    return 0;
}