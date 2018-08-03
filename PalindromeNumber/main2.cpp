#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int y{0};

        if (x < 0)
            return false;
        if (x % 10 == 0 && x != 0)
            return false;

        while (y < x) {
            y = 10 * y + x % 10;
            x = x / 10;
        }
        if (x == y)
            return true;
        else if (x == (y / 10))
            return true;
        else
            return false;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(1001) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}