#include <iostream>
#include <vector>

using namespace std;

// 超时
class Solution {
private:
    vector<int> getSquareNumber(int n) {
        int i = 1;
        vector<int> squareNumbers;

        while (i * i <= n) {
            squareNumbers.push_back(i * i);
            i++;
        }
        return squareNumbers;
    }

public:
    int numSquares(int n) {
        if (n == 0 || n == 1)
            return 1;

        vector<int> squareNumbers = getSquareNumber(n);

        // 初始化
        vector<int> memo = vector<int>(n + 1, INT_MAX);
        for (int i = 0; i < squareNumbers.size(); ++i) {
            memo[squareNumbers[i]] = 1;
        }

        //
        for (int i = 2; i <= n; ++i) {
            if (memo[i] == INT_MAX) {
                for (int j = 1; j < i; ++j) {
                    memo[i] = min(memo[i], memo[i - j] + memo[i - (i - j)]);
                }
            }
        }

        return memo[n];
    }
};


int main() {

    Solution s;
    cout << s.numSquares(6337) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}