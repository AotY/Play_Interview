#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) {
            return 0;
        }

        bool a[n];//是素数

        memset(a, false, n);
        int count = 0;

        for (int i = 2; i < n; i++) {
            if (!a[i]) { // 是素数
                count++;
                for (int j = 2; j * i < n; j++) {
                    a[j * i] = true;
                }
            }
        }
        return count;
    }
};

int main() {

    Solution s;

    cout << s.countPrimes(10) << endl;
    return 0;
}