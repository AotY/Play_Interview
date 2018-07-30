#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo;

    int max3(int a, int b, int c) {
        return max(max(a, b), c);
    }

public:
    int integerBreak(int n) {

        memo = vector<int>(n + 1, -1);

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i - 1; ++j) {
                memo[i] = max3(memo[i], j * (i - j), j * memo[i - j]);
            }

        }

        return memo[n];
    }
};

int main() {

    Solution s;
    cout << s.integerBreak(5) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}