#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> memo;

    int max3(int a, int b, int c) {
        return max(max(a, b), c);
    }

    int searchHelper(int n) {

        if (n == 1) {
            return 1;
        }

        if (memo[n] != -1)
            return memo[n];
        int result = -1;
        for (int i = 1; i <= n - 1; ++i) {
            result = max3(result, i * (n - i), i * searchHelper(n - i));
        }
        memo[n] = result;
        return result;
    }

public:
    int integerBreak(int n) {

        memo = vector<int>(n + 1, -1);

        return searchHelper(n);
    }
};

int main() {

    Solution s;
    cout << s.integerBreak(10) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}