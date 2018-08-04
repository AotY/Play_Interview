#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long p;

        if (n < 0) {
            p = (-1LL) * n;
            x = 1 / x;
        } else {
            p = n;
        }

        while (p) {
            if (p & 1)
                ans *= x;
            x *= x;

            p >>= 1;
        }
        return ans;
    }
};


int main() {
    Solution s;
    cout << s.myPow(2, -1) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}