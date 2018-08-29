#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <complex>

using namespace std;


//  第二题  多项式卷积乘法


int maxRank = 4;

// (a+bi)(c+di)= (ac-bd)+(bc+ad)i.
int readAdd(vector<int> &c1, vector<int> &c2) {
    return c1[0] * c2[0] - c1[1] * c2[1];
}


int imagAdd(vector<int> &c1, vector<int> &c2) {
    return c1[1] * c2[0] + c1[0] * c2[0];
}


int main() {


    // 4 3 2 1 0 的系数
    vector<vector<int>> multinomial1 = vector<vector<int>>(10, vector<int>(2, 0));
    vector<vector<int>> multinomial2 = vector<vector<int>>(10, vector<int>(2, 0));


    // 输入两个4阶多项式的系数序列，高阶先输入
    // 先实部，后虚部
    // 为零则输入零

    for (int i = 0; i <= maxRank; ++i) {
        cin >> multinomial1[i][0];
        cin >> multinomial1[i][1];
    }

    for (int i = 0; i <= maxRank; ++i) {
        cin >> multinomial2[i][0];
        cin >> multinomial2[i][1];
    }

    // 计算卷积多项式系数，先输出最高阶 cn
    // (a+bi)(c+di)= (ac-bd)+(bc+ad)i.

    for (int k = 0; k <= (maxRank + maxRank) ; ++k) {
        
        int realCk; //
        int imagCk; //

        // 计算复数乘法
        for (int i = 0; i <= k; ++i) {
            realCk += readAdd(multinomial1[i], multinomial2[k - i]);
            imagCk += imagAdd(multinomial1[i], multinomial2[k - i]);
        }

        cout << realCk << endl;
        cout << imagCk << endl;
    }


    return 0;
}