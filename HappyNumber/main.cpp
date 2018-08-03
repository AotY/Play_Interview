#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {

private:
    vector<int> n2Digits(int n) {
        vector<int> digits;
        while (n != 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        return digits;
    }

    bool happy(unordered_set<int> sumsSet, int n) {
        if (n == 0)
            return false;

        if (n == 1)
            return true;

        if (sumsSet.count(n)) {
            return false;
        } else {
            sumsSet.insert(n);
        }

        int res = false;
        vector<int> digits = n2Digits(n);
        int sum = 0;
        for (int i = 0; i < digits.size(); ++i) {
            sum += digits[i] * digits[i];
        }

        res = happy(sumsSet, sum);

        return res;
    }

public:
    bool isHappy(int n) {


        unordered_set<int> sumsSet;
        return happy(sumsSet, n);
    }
};


int main() {

    Solution s;
    cout << s.isHappy(7) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}