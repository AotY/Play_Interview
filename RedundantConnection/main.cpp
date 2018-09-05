#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:
    // union find
    vector<int> nums;

    vector<int> ranks;

    int find(int u) {
        if (nums[u] != u) {
            nums[u] = find(nums[u]);
        }

        return nums[u];
    }


    bool canUnionEdges(int e1, int e2) {

        int p1 = find(e1);

        int p2 = find(e2);

        if (p1 != p2) {

            if (ranks[p1] < ranks[p2]) {
                nums[p1] = p2;
            } else if (ranks[p2] < ranks[p1]) {
                nums[p2] = p1;
            } else {
                // ranks[p1] == ranks[p2]
                nums[p2] = p1;
                ranks[p1] += 1;
            }

            return true;
        } else {
            // p1 == p2

            // 形成环路
//            if ((e1 == p1 || e2 == p1) || )
                return false;
        }
//        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        nums = vector<int>(n + 1);
        for (int i = 0; i <= n; ++i) {
            nums[i] = i;
        }

        ranks = vector<int>(n + 1, 1);

        vector<int> res;
        // try union
        for (int i = 0; i < n; ++i) {
            vector<int> edge = edges[i];

            if (!canUnionEdges(edge[0], edge[1])) {
                res = edge;
            }
        }

        return res;
    }
};

int main() {

    Solution s;
    vector<vector<int>> edges = {{1,2}, {1,3}, {2,3}};
    vector<int> res = s.findRedundantConnection(edges);
    cout << res[0] << ", " << res[1] << endl;

    return 0;
}