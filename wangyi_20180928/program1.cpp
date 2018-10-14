#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int k;
    for (i = 0; i < k; ++i) {
       int n;
       cin >> n;

       vector<int> nums = vector<int>(n);
       int sum = 0;
       int maxNum = -999999;
       for (int j = 0; j < n ; j ++ ) {
           cin >> nums[j]; 
           sum += nums[j];
           maxNum = max(maxNum, nums[j]);
       }

       // 进行一次加或者减操作(x)，然后使得nums中的所有值相等。

       
    }
}
