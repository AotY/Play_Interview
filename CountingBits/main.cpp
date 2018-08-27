#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> memo = vector<int>(num + 1);

        memo[0] = 0;

        for (int i = 1; i <= num; ++i) {
            if (i % 2 == 0)
                memo[i] = memo[ i / 2];
            else
                memo[i] = memo[ i / 2] + 1;
        }

        return memo;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}