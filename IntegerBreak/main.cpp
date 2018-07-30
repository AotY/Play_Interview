#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:

    int max3(int a, int b, int c) {
        return max(max(a, b), c);
    }

    int searchHelper(int n) {

        if (n == 1) {
            return 1;
        }

        int result = -1;
        for (int i = 1; i <= n - 1; ++i) {
            result = max3(result, i * (n - i), i * searchHelper(n - i));
        }
        return result;
    }

public:
    int integerBreak(int n) {
        return searchHelper(n);
    }
};

int main() {

    Solution s;
    cout << s.integerBreak(2) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}