#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


static int xx = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
private:
    bool happy(unordered_set<int> sumsSet, int n) {
        if (n == 0)
            return false;

        if (n == 1)
            return true;

        if (sumsSet.find(n) != sumsSet.end())
            return false;
        else
            sumsSet.insert(n);

        int res = false;
        int sum = 0;

        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
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