#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> integer2Arr(int n) {
        vector<int> res;
        int index = 0;
        while (n != 0) {
            res.push_back(n % 10);
            n = n / 10;
        }
        return res;
    }

public:
    bool isPalindrome(int x) {
        if (x >= 0 && x < 10)
            return true;

        if (x < 0)
            return false;

        vector<int> partArr = integer2Arr(x);
        int len = partArr.size();
        int mid = len / 2;
        for (int i = 0; i < mid; ++i) {
            if (partArr[i] != partArr[len - i - 1])
                return false;
        }
        return true;
    }
};


int main() {
    Solution s;
    cout << s.isPalindrome(121) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}