#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>

using namespace std;

// 在无权图中，从n到0的最短路径
// 最短路径问题的变形
class Solution {
public:
    int numSquares(int n) {
        assert(n > 0);

        if (n == 1)
            return 1;

        // num, curStep
        queue<pair<int, int>> searchQueue;
        searchQueue.push(make_pair(n, 0));

        vector<bool> mark = vector<bool>(n + 1, false);

        while (!searchQueue.empty()) {
            // num, step
            pair<int, int> curPair = searchQueue.front();
            searchQueue.pop();

            int i = 1;
            int s = curPair.first - i * i;
            while (s >= 0) {
                if (s == 0)
                    return curPair.second + 1;
                else {
                    if (!mark[s]) {
                        searchQueue.push(make_pair(s, curPair.second + 1));
                        mark[s] = 1;
                    }
                }
                i++;
                s = curPair.first - i * i;
            }

        }
        throw invalid_argument("invalid argument");
    }
};


int main() {

    clock_t t0 = clock();
    Solution s;
    cout << s.numSquares(12) << endl;

    clock_t t1 = clock();
    cout << (t1 - t0) / CLOCKS_PER_SEC << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}