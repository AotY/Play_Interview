#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <math.h>

using namespace std;

// 第一题
// 求整数之和

// 1. 忽略小数点
// 2. - 负号个数

// 所有整数之和
int main() {

    string str;
    cin >> str;

    str.push_back('E');

    int res = 0;

    int lastNumIndex = 0; // 上一次出现数字的位置
    bool lasthasNum = false; // 前面是否有数字
    bool isNegative = false; //  是否为负数

    vector<char> curChars;
    for (int i = 0; i < str.size(); ++i) {

        //  如果是数字，检查前面是否有负号
        if (str[i] >= '0' && str[i] <= '9') {

            if (lasthasNum) {
                // 如果之前有数字，比如  -11
                curChars.push_back(str[i]);

            } else { // 第一次出现数字

                int nCount = 0; //  负号个数
                int tmpIndex = i - 1;

                while (tmpIndex >= 0 && str[tmpIndex] == '-') {
                    nCount++;
                    tmpIndex --;
                }

                // 加入
                curChars.push_back(str[i]);

                if (nCount % 2 != 0)
                    isNegative = true;

                lasthasNum = true;
            }

        } else {
            // 其他

            if (curChars.size() == 0)
                continue;

            int curNum = 0;
            int powNum = 0;
            for (int j = curChars.size() - 1; j >= 0; --j) {
                curNum += (int) pow(10, powNum) * (curChars[j] - '0');
                powNum ++;
            }

            // 如果负数
            if (isNegative) {
                res -= curNum;
            } else {
                res += curNum;
            }

            curChars.clear();
            lasthasNum = false;
            isNegative = false;
        }

    }

    cout << res << endl;

    return 0;
}
// AB-11CD--2EF33
// -11 + 2 + 33 = 24