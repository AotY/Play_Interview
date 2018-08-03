#include <iostream>
#include <math.h>
using namespace std;


// 时间超时
class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;

        int arr[1] = {0};

        for (int i = 0; i < abs(a); ++i) {
            if(a > 0)
                arr[0] ++;
            else
                arr[0] --;
        }

        for (int i = 0; i < abs(b); ++i) {
            if(b > 0)
                arr[0] ++;
            else
                arr[0] --;
        }


        return arr[0];
    }
};


int main() {
    Solution s;
    cout<<s.getSum(-1, -1)<<endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}