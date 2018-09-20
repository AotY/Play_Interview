#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1)
            return 0;

        int res = 0;


        for (int i = 2; i < n; ++i) {
            bool isPrime = true;
            for (int j = 2; j <= (int)sqrt(i); ++j) {
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime)
                res ++ ;
        }

        return res;
    }
};



int main() {

    Solution s;

    cout << s.countPrimes(10) << endl;
    return 0;
}