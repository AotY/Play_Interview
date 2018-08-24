#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:

    vector<int> memo;

    bool searchForWin(int maxChoosableInteger, int desiredTotal, int state) {
        // 另一个用户已经把数填满
        if (desiredTotal <= 0)
            return false;


        if (memo[state] != -1)
            return memo[state] == 1;

        for (int i = 0; i < maxChoosableInteger; ++i) {

            if (state & (1 << i)) // 是否已经使用过该数
                continue;


            // The next player can not win, current player wins
            bool res = searchForWin(maxChoosableInteger, desiredTotal - (i + 1), state | (1 << i));
            if (!res) { // res == false
                memo[state] = 1;
                return true;
            }


        }

        memo[state] = 0;
        return false;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        const int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) /  2;
        // 如果可以得到的总和小于desiredTotal
        if (sum < desiredTotal)
            return false;

        // 不用选择就可以获得胜利
        if (desiredTotal <= 0)
            return true;

        // memorized search
        memo = vector<int> (1 << maxChoosableInteger, -1);

        return searchForWin(maxChoosableInteger, desiredTotal, 0);
    }
};

int main() {


    Solution s;
    // 1 2 3 4   6 优先拿小于一半的数 6 - 1 = 5  - 4
    cout << s.canIWin(16, 226) << endl;

    return 0;
}