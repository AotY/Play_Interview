#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;

// 在无权图中，从n到0的最短路径
// 最短路径问题的变形

class Solution {
public:
    int numSquares(int n) {
        if (is_square(n))
            return 1;

        while ((n & 3) == 0)
            n >>= 2;  //等效于n%4 == 0

        if ((n & 7) == 7)
            return 4; //等效于 n%8 == 7

        int sqrt_n = (int) (sqrt(n));

        for (int i = 1; i <= sqrt_n; i++) {
            if (is_square(n - i * i)) {
                return 2;
            }
        }

        return 3;
    }

private:
    int is_square(int n) {
        int sqrt_n = (int) (sqrt(n));
        return (sqrt_n * sqrt_n == n);
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