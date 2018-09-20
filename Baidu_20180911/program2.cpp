#include <iostream>
#include <vector>
#include <math.h>

typedef long long II;

using namespace std;


// A0 - An 的整数序列，满足  A0 = An = 1, 1 <= Ai <= M 且 Ai != A(i - 1) (1 <= i < N)

// 输出： 满足条件的序列个数对 10^9 + 7 取模的结果

const int MODE = (int)(pow(10, 9) + 7);


II searchSeqNum(vector<int> &nums, int N, int M, int index) {

    if (index >= N)
        return 1;

    II res = 0;

    for (int i = 1; i <= M; ++i) {
        if (i == 1 && (index == N-1 || index == 1)) {
            continue;
        }

        // next search
        if (i != nums[index-1]) { // nums[index] == -1 &&

            nums[index] = i;
            res += searchSeqNum(nums, N, M, index + 1)  % MODE;
//            nums[index] = -1;
        }
    }

    return res;

}

int main() {



    int N, M;

    cin >> N >> M;

    vector<int> nums = vector<int>(N + 1);
    nums[0] = 1;
    nums[N] = 1;
    II res = searchSeqNum(nums, N, M, 1);

    cout << res << endl;

    return 0;
}