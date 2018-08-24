#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // dp[i]表示当前状态为i时下一个做决策的player能否获胜，最终返回结果就是dp[0]
    // 状态i的二进制表示 1...maxChoosableInteger 的数中哪些数字被选过了
    // 举例：maxChoosableInteger=5，那么状态i=5（二进制为00101）表示数字1（二进制为00001）和数字4（00100）已经被选过了
    // dp[i]=-1表示状态i还未被搜索过
    // dp[i]=0表示当前状态为i时下一个做决策的player必败
    // dp[i]=1表示当前状态为i时下个一做决策的player能够获胜

    vector<int> dp;

    // maxChoosableInteger和desiredTotal的全局变量
    int choose, total;

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // 1 + ... + maxChoosableInteger < desiredTotal，无论如何都不可能赢，直接返回false
        if ((1 + maxChoosableInteger) * maxChoosableInteger < desiredTotal) {
            return false;
        }
        // maxChoosableInteger > desiredTotal，第一轮就能赢，直接返回true
        if (maxChoosableInteger > desiredTotal) {
            return true;
        }

        choose = maxChoosableInteger;
        total = desiredTotal;
        // dp数组初始化
        dp.resize(1 << (maxChoosableInteger + 1), -1);

        return calc_dp(0, 0);
    }

    // cur记录当前选过的数的总和为cur，状态used记录当前选过的数字状态为二进制表示的used
    // 举例：当前已经选择了数字1、3、4，那么cur=1+3+4=8
    // used = 01101 = 00001 | 00100 | 01000 = (1<<0) | (1<<2) | (1<<3) = 1 + 4 + 8 = 13 （十进制）
    bool calc_dp(int cur, int used) {

        if (dp[used] != -1) return dp[used];

        for (int i = 0; i < choose; i++) {
            // 选择一个数字i+1，i是指二进制的第i位，所以对应的数字为i+1
            // 比如要选择数字2，它的二进制表示为1<<1（即1左移1位），得到00010
            // used跟(1<<i)做&(与操作)等于0时当前仅当used中第i位也为0
            // 比如：00101 & 00100 = 00100不等于0，说明第2位（即数字3）已经被选过
            // 比如：01001 & 00100 = 00000等于0，说明第2位（即数字3）没有被选过
            if ((used & (1 << i)) == 0) {
                // 第一种情况：如果当前总和cur加上选择的数字i+1≥total，那么dp[used]为true
                // 说明在used状态时，当前做决策的player选择i+1这个数字就能获胜
                if (cur + i + 1 >= total) {
                    dp[used] = true;
                    return true;
                }

                // 第二种情况：如果当前总和cur加上选择的数字i+1可以到达一个必败状态dp[used | (1<<i)]，
                // 那么选择数字i+1就可以使得下一个做决策的player必败，则dp[used]状态也为true，即当前做决策的player就能获胜
                // 解释used | (1 << i)，举例：当前状态used为01001（已经选择了数字1和数字4），选择的数字为3（二进制为00100），
                // 那么01001 | 00100 = 01101，就是在当前used状态下再加入选择的数字3得到一个新的状态
                if (!calc_dp(cur + i + 1, used | (1 << i))) {
                    dp[used] = true;
                    return true;
                }
            }
        }
        // 任意选择一个数字i+1都不能使得dp[used]=true，那么dp[used]就等于false
        dp[used] = false;
        return false;
    }
};

int main() {


    Solution s;
    // 1 2 3 4   6 优先拿小于一半的数 6 - 1 = 5  - 4
    cout << s.canIWin(16, 226) << endl;

    return 0;
}