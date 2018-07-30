#include <iostream>
#include <vector>

using namespace std;


// 贪心不能解决这个问题，要搜索
class Solution {
public:
    bool stoneGame(vector<int> &piles) {
        bool result = true;

        int alex = 0;
        int lee = 0;
        int curStart = 0;
        int curLen = piles.size() - 1;
        while (curStart <= curLen) {
            if (piles[curStart] > piles[curLen]) {
                alex += piles[curStart];
                curStart += 1;
            } else {
                alex += piles[curLen];
                curLen -= 1;
            }

            if (piles[curStart] >= piles[curLen]) {
                lee += piles[curStart];
                curStart += 1;
            } else {
                lee += piles[curLen];
                curLen -= 1;
            }

        }

        result = alex > lee;
        return result;
    }
};

int main() {
    Solution s;
    vector<int> piles = {3, 7, 2, 3};
    cout << s.stoneGame(piles) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}