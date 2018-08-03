#include <iostream>
#include <math.h>
using namespace std;


class Solution {
public:
    int getSum(int a, int b) {

        if ( b == 0)
            return a;

        int sum = a ^ b;
        int carry = a & b;
        carry = carry << 1;

        return getSum(sum, carry);
    }
};


int main() {
    Solution s;
    cout<<s.getSum(2, 1)<<endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}