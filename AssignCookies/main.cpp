#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {

        // 贪心思想，先满足最贪心的孩子

        int ng = g.size();
        int ns = s.size();

        if (ng == 0 || ns == 0)
            return 0;

        int res = 0;

        // 大到小
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int gIndex = 0;
        int sIndex = 0;
        while (gIndex < ng && sIndex < ns) {
            // 满足
            if (s[sIndex] >= g[gIndex]) {
                res++;
                gIndex++;
                sIndex++;
            } else {
                // 不满足
                gIndex++;
            }


        }

        return res;
    }
};


int main() {

    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};

    Solution S;

    cout << S.findContentChildren(g, s) << endl;

    return 0;
}