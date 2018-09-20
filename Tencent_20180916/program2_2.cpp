#include <iostream>
#include <vector>
#include <math.h>

typedef long long II;

using namespace std;


int main() {

    II x, y; // 小Q, 牛牛的分数

    cin >> x >> y;

    // 输出最少的轮次

    II sum = x + y;

    double a = Math.sqrt(sum * 8 + 1);

    if (a - (long) a != 0) {
        cout << -1 << endl;
    } else {
        II n = ((II) a - 1) / 2;

        if (x <= n) {
            cout << 1 << endl;
            return;
        }
        II result = -1;
        II count = 0;

        for (II i = n; i > 0; i--) {
            count += i;
            if (count >= x) {
                result = n - i + 1;
                break;
            }
        }
        cout << result << endl;
    }

    return 0;
}
