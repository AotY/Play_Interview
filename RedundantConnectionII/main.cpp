#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// hard
// 并查集，有向连接

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        vector<int> temp(edges.size() + 1, 0);
        vector<int> sec(edges.size() + 1, 0);
        deque<int> d;
        for (int i = 0; i < edges.size(); i++) {
            d.push_back(i);
            temp[edges[i][0]]++;
            temp[edges[i][1]]++;
            sec[edges[i][1]]++;
        }
        int t = 1;
        while (t) {
            int len = d.size();
            t = 0;
            for (int i = 0; i < len; i++) {
                int n = d.front();
                d.pop_front();
                if (temp[edges[n][0]] == 1 || temp[edges[n][1]] == 1) {
                    temp[edges[n][0]]--;
                    temp[edges[n][1]]--;
                    t++;
                } else {
                    d.push_back(n);
                }
            }
        }

        int ans = 0;
        int tt = -1;
        for (auto n : d) {
            if (n > ans)
                ans = n;
            if (sec[edges[n][1]] == 2 && n > tt)
                tt = n;
        }

        if (tt != -1)
            ans = tt;

        return edges[ans];
    }
};

int main() {


    return 0;
}