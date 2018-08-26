#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <math.h>

using namespace std;

// 合法表达式 数字0-9组成的字符串
// 若X为合法标识符，则X为合法表达式
// 若X为合法标识符，则(X)为合法表达式
// 若X为合法标识符，则X-Y, X+Y为合法表达式


const int MODE_NUM = 1000000007;


// 数字0-9组成 （ 多个前导0）

int res = 0;


int main() {

    int n; // 长度
    cin >> n;

    vector<int> memo = vector<int>(1000 + 1, -1);

    memo[1] = 10;
    memo[2] = 100;
    memo[3] = 1210;


    int baseCount = 1000;
    for (int i = 4; i <= n; ++i) {
        baseCount *= (baseCount * 10) % MODE_NUM;
        memo[i] = baseCount+  (memo[i - 1 - 1] * memo[i - 1 - 2] * 2 + memo[i - 2]) % MODE_NUM;
    }

    cout << memo[n] % MODE_NUM << endl;

    return 0;
}