#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

static auto m_vec = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    vector<int> tmp = {1};

    int x = 0, y = 0, z = 0, a = 2, b = 3, c = 5, m;

    for (register int j = 1; j <= 1690; ++j) {
        m = min(min(a, b), c);
        tmp.push_back(m);
        if (a == m)
            a = 2 * tmp[++x];
        if (b == m)
            b = 3 * tmp[++y];
        if (c == m)
            c = 5 * tmp[++z];
    }
    return tmp;

}();

class Solution {
public:
    int nthUglyNumber(int n) {
        return m_vec[n - 1];
    }
};

int main() {

    Solution s;
    cout << s.nthUglyNumber(10) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}