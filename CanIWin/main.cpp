#include <iostream>
#include <vector>

using namespace std;

enum Who {
    FIRST, SECOND
};

class Solution {

private:

    vector<bool> book;

    Who searchForWin(int maxChoosableInteger, int desiredTotal, int remindTotal, Who who) {

        // 优先拿 小于 （desiredTotal - remindTotal）- maxChoosableInteger 最小值的，没有的话就是输家

        // 游戏结束，这轮玩家已经没有选择了，肯定会输
        if (remindTotal <= 0) { // 1: min value
            return who == SECOND ? FIRST : SECOND;
        }

        // 如果此时  remindTotal 小于等于maxInteger则说明这次选择的玩家就是赢家
        int minInteger = 1;
        if (remindTotal >= minInteger && remindTotal <= maxChoosableInteger) {
            return who;
        }

        // 1 2 3 4 5    10 - 5 = 5
        int canChooseInteger = remindTotal - maxChoosableInteger - 1;
        if (canChooseInteger <= 0)
            return who == SECOND ? FIRST : SECOND;

        canChooseInteger = canChooseInteger > maxChoosableInteger ? maxChoosableInteger : canChooseInteger;
        while (book[canChooseInteger] && canChooseInteger >= 1) {
            canChooseInteger--;
        }

        if (canChooseInteger == 0)
            return who == SECOND ? FIRST : SECOND;

        book[canChooseInteger] = true;

        Who nextWho = who == FIRST ? SECOND : FIRST;

        Who winWho = searchForWin(
                canChooseInteger == maxChoosableInteger ? maxChoosableInteger - 1 : maxChoosableInteger,
                desiredTotal, remindTotal - canChooseInteger, nextWho);
        book[canChooseInteger] = false;

        return winWho;

    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        if (desiredTotal == 0)
            return true;

        book = vector<bool>(maxChoosableInteger + 1, false);

        Who who = searchForWin(maxChoosableInteger, desiredTotal, desiredTotal, FIRST);

        return who == FIRST;

    }
};

int main() {


    Solution s;
    // 1 2 3 4   6 优先拿小于一半的数 6 - 1 = 5  - 4
    cout << s.canIWin(18, 79) << endl;

    return 0;
}