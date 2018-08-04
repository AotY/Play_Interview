#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;

// 在无权图中，从n到0的最短路径
// 最短路径问题的变形
static vector<short> table(1,0);

class Solution {
public:
    int numSquares(int n) {
        while (table.size() <= n) {
            int m = table.size(), value = n;
            for (int i = 1; m >= i * i; i++)
                value = min(value, table[m - i * i] + 1);

            table.push_back(value);
        }
        return table[n];
    }
};


int main() {

    clock_t t0 = clock();
    Solution s;
    cout << s.numSquares(12) << endl;

    clock_t t1 = clock();
    cout << (t1 - t0) / CLOCKS_PER_SEC << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}