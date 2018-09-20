#include <iostream>
#include <vector>

using namespace std;

// hard
// 并查集，有向连接

/**
 *  There are two cases for the tree structure to be invalid.

    Case 1: No duplicate parents, return the first edge that creates the loop. Same to Redundant Connection I.

    Case 2: A node v has two parents {u1, u2}
        - 2.1 return the second edge that creates duplicate parents.
        - 2.2 return {u1, v} or {u2, v} that creates the loop.

    Solution: Union find
    Time complexity: O(nlog*n) ~ O(n)
    Space complexity: O(n)
 */
class Solution {
private:
    vector<int> parents;
    vector<int> sizes;
    vector<int> roots;


    int findRoot(int u) {
        if (u != roots[u]) {
            u = findRoot(roots[u]);
        }
        return roots[u];
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {

        // check if has duplicate parents
        int n = edges.size();


        vector<int> candidate1;
        vector<int> candidate2;

        parents = vector<int>(n + 1, 0);
        sizes = vector<int>(n + 1, 1);

        roots = vector<int>(n + 1);



        // check
        for (int i = 0; i < n; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (parents[v] > 0) {

                // it has duplicate parents.
                candidate1 = {parents[v], v};
                candidate2 = edges[i];

                edges[i][0] = edges[i][1] = -1; // delete edge
            }

            parents[v] = u;

        }

        // init roots
        for (int i = 0; i < n; ++i) {
            roots[i] = i;
        }

        // union
        for (int i = 0; i < n; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (u == -1 && v == -1)
                continue; // this edge has deleted

            // try union
            int pu = findRoot(u);
            int pv = findRoot(v);

            if (pu == pv) {
                //
                return candidate1.empty() ? edges[i] : candidate1;

            } else {

                // union
                if (sizes[pv] > sizes[pu])
                    swap(pv, pu);

                roots[pu] = pv;
                sizes[pu] += sizes[pv];
            }

        }


        return candidate2;

    }

};

int main() {


    return 0;
}

