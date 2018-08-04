#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>

using namespace std;

// 看来不能超过 nlog(n)
class Solution {
public:
    int numSquares(int n) {
        assert(n > 0);

        if (n == 1)
            return 1;

        // 初始化
        vector<int> memo = vector<int>(n + 1, INT_MAX);

        int s = 1;
        int square = s * s;
        while (square <= n) {
            memo[square] = 1;
            s++;
            square = s * s;
        }

        //
        if (memo[n] == 1)
            return 1;
        int tmpSquare = 1;
        for (int i = 2; i <= n; ++i) {
            if (memo[i] != 1) {
                for (int j = i - tmpSquare; j < i; ++j) {
                    memo[i] = min(memo[i], memo[i - j] + memo[i - (i - j)]);
                    if (memo[i] == 2)
                        break;
                }
            } else {
                tmpSquare = i;
            }
        }

        return memo[n];
    }
};


int main() {

    clock_t t0 = clock();
    Solution s;
    cout << s.numSquares(8935) << endl;

    clock_t t1 = clock();
    cout << (t1 - t0) / CLOCKS_PER_SEC << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}