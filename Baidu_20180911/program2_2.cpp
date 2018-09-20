#include <iostream>
#include <vector>
#include <math.h>

typedef long long II;

using namespace std;


// A0 - An 的整数序列，满足  A0 = An = 1, 1 <= Ai <= M 且 Ai != A(i - 1) (1 <= i < N)

// 输出： 满足条件的序列个数对 10^9 + 7 取模的结果

const int MODE = (int) (pow(10, 9) + 7);


II searchSeqNum(int N, int M) {

    II res;
    if (N <= 2)
        res = 1;
    else if (N == 3)
        res = M - 1;
    else {
        II left = (M - 1) % MODE;
        II number1 = (long) pow(left, N - 2) % MODE;
        II number2 = ((long) pow(left, N - 3) * 3) % MODE;
        II number3 = ((long) pow(left, N - 4) * 3) % MODE;
        res = (number1 - number2 + number3) % MODE;

    }
    return res;

}

int main() {


    int N, M;

    cin >> N >> M;

    II res = searchSeqNum(N, M);

    cout << res << endl;

    return 0;
}