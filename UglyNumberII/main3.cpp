#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

// 得用动态规划这个。。。
class Solution {
    int min3(int a, int b, int c) {
        return min(a, min(b, c));
private:
    }

public:
    int nthUglyNumber(int n) {
        if (n == 1)
            return 1;

        vector<int> memo = vector<int>(n);
        memo[0] = 1;

        int t2 = 0; //  使用2的次数
        int t3 = 0;
        int t5 = 0;
        for (int i = 1; i < n; ++i) {
            memo[i] = min3(memo[t2] * 2, memo[t3] * 3, memo[t5] * 5);

            if (memo[t2] * 2 == memo[i])
                t2 ++;

            if (memo[t3] * 3 == memo[i])
                t3 ++;

            if (memo[t5] * 5 == memo[i])
                t5 ++;
        }


        return memo[n-1];
    }
};

int main() {

    Solution s;
    cout << s.nthUglyNumber(10) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}