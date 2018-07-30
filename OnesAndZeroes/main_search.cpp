#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <unordered_map>

using namespace std;

static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
private:
    vector<bool> isMark;
    vector<bool> banMark;

    unordered_map<string, vector<int>> countMap;

    int max3(int a, int b, int c) {
        int result = max(a, b);
        result = max(result, c);
        return result;
    }

    vector<int> getZeroOneCount(string s) {
        if (countMap.count(s)) {
            return countMap[s];
        }

        int oneCount = 0, zeroCount = 0;
        for (int j = 0; j < s.size(); ++j) {
            int num = s[j] - '0';
            if (num == 1)
                oneCount++;
            else
                zeroCount++;
        }
        vector<int> result;
        result.push_back(zeroCount);
        result.push_back(oneCount);
        countMap[s] = result;

        return countMap[s];
    }

    int searchMaxDepth(vector<string> &strs, int depth, int m, int n) {


        if (m == 0 && n == 0)
            return depth;

        int cur_depth = depth;

        for (int i = 0; i < strs.size(); ++i) {
            if (!isMark[i] && !banMark[i]) { // 没有被访问过，可以访问

                isMark[i] = true;

                vector<int> counts = getZeroOneCount(strs[i]);
                int zeroCount = counts[0];
                int oneCount = counts[1];

                if ((m - zeroCount) >= 0 && (n - oneCount) >= 0)
                    depth = max3(depth,
                                 searchMaxDepth(strs, cur_depth + 1, m - zeroCount, n - oneCount),
                                 searchMaxDepth(strs, cur_depth, m, n));
                else {
                    banMark[i] = true;
                    depth = max(depth, searchMaxDepth(strs, cur_depth, m, n));
                }

                isMark[i] = false;
            }
        }
        return depth;
    }


public:
    int findMaxForm(vector<string> &strs, int m, int n) {

        // m - zero count
        // n - one count
        if (m == 0 && n == 0)
            return 0;

        int depth = 0;

        isMark = vector<bool>(strs.size(), false);

        for (int i = 0; i < strs.size(); ++i) {
            banMark = vector<bool>(strs.size(), false);
            vector<int> counts = getZeroOneCount(strs[i]);
            int zeroCount = counts[0];
            int oneCount = counts[1];
            // 对于每一个str, 可以选择或者不选择，但是要保证 oneCount与zeroCount足够
            isMark[i] = true;
            if ((m - zeroCount) >= 0 && (n - oneCount) >= 0)
                depth = max3(depth, searchMaxDepth(strs, 1, m - zeroCount, n - oneCount),
                             searchMaxDepth(strs, 0, m, n));
            else {
                banMark[i] = true;
                depth = max(depth, searchMaxDepth(strs, 0, m, n));
            }

            // 回溯
            isMark[i] = false;
        }
        return depth;
    }
};


int main() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};

    Solution s;
    cout << s.findMaxForm(strs, 5, 3) << endl;
    return 0;
}

//        banMark = vector<bool>(strs.size(), false);

//        vector<int> counts = getZeroOneCount(strs[0]);
//        int zeroCount = counts[0];
//        int oneCount = counts[1];
//        // 对于每一个str, 可以选择或者不选择，但是要保证 oneCount与zeroCount足够
//        isMark[0] = true;
//        if ((m - zeroCount) >= 0 && (n - oneCount) >= 0)
//            depth = max3(depth,
//                         searchMaxDepth(strs, 0, strs.size(), 1, m - zeroCount, n - oneCount),
//                         searchMaxDepth(strs, 0, strs.size(), 0, m, n));
//        else {
//            depth = max(depth, searchMaxDepth(strs, 1, strs.size(), 0, m, n));
//            banMark[0] = true;
//        }
//
//        // 回溯
//        isMark[0] = false;