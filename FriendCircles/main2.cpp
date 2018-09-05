#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

static int x = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {

private:
    int m_tree[1110];
    int cnt = 0;

public:
    int findRoot(int x) {
        if (m_tree[x] == -1) {
            return x;
        } else {
            int temp = findRoot(m_tree[x]);
            m_tree[x] = temp;
            return temp;
        }
    }

    int findCircleNum(vector<vector<int>> &M) {
        int m = (int) M.size();
        for (int i = 0; i < m; ++i) {
            m_tree[i] = -1;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (M[i][j] == 1) {
                    int a = i, b = j;

                    a = findRoot(a);
                    b = findRoot(b);

                    if (a != b) {
                        m_tree[b] = a;
                    }
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            if (m_tree[i] == -1) {
                cnt++;
            }
        }

        return cnt;
    }

};


int main() {

    Solution s;

//    vector<vector<int>> M = {
//            {1, 0, 0, 1},
//            {0, 1, 1, 0},
//            {0, 1, 1, 1},
//            {1, 0, 1, 1}
//    };

    vector<vector<int>> M = {{1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                             {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
                             {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                             {0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
                             {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
                             {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
                             {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                             {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}
    };

    cout << s.findCircleNum(M) << endl;

    return 0;
}
