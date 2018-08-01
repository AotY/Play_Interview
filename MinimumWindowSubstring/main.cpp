#include <iostream>
#include <vector>
#include <string>

using namespace std;


static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


class Solution {
private:


    bool isEqual(int *searchArr, int *tArr) {
        for (int i = 0; i < 60; ++i) {
            if (searchArr[i] < tArr[i])
                return false;
        }
        return true;
    }

    void clear2Zero(string &s, int *searchArr, int left, int right) {
        for (int i = left; i < right; ++i) {
            int index = s[i] - 'A';
            if (searchArr[index] > 0)
                searchArr[index] -= 1;
        }
    }

public:
    string minWindow(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        if (sLen == 0 || tLen == 0)
            return "";


        int tArr[60] = {0};

        for (int i = 0; i < tLen; ++i) {
            tArr[t[i] - 'A'] += 1;
        }

        int left = 0;
        int right = 0;

        //
        string res = "";
        int minLen = sLen + 1;

        int searchArr[60] = {0};

        vector<int> memo;
        int lastMatchIndex = 0;

        while (right < sLen) {
            //
            int index = s[right] - 'A';
            if (tArr[index] != 0) {
                memo.push_back(right);

                searchArr[index] += 1;
                if (isEqual(searchArr, tArr)) {
                    int curLen = right - left + 1;
                    if (curLen < minLen) {
                        res = s.substr(left, curLen);
                        minLen = curLen;
                    }
                    // remove some count
                    if (right != (sLen - 1)) {
                        lastMatchIndex++;
                        clear2Zero(s, searchArr, left, memo[lastMatchIndex]);
                        left = memo[lastMatchIndex];
                    }
                }
                right++;
            } else {
                if (left == right) {
                    left++;
                    right++;
                } else {
                    right++;
                }
            }

        }

        // 当 memo中还有元素没有访问过时，判断是否满足题意条件
        int mSize = memo.size();
        while (mSize > 0 && lastMatchIndex < (mSize - 1)) {
            clear2Zero(s, searchArr, memo[lastMatchIndex++], memo[lastMatchIndex]);
            left = memo[lastMatchIndex];
            if (isEqual(searchArr, tArr)) {
                int curLen = memo[memo.size() - 1] - left + 1;
                if (curLen < minLen) {
                    res = s.substr(left, curLen);
                    minLen = curLen;
                }
            } else
                break;
        }

        return res;
    }
};

int main() {
    string s = "ADOBECODEBANCADOBEADOBECODEBANCADOBABCECODEBANCCODEBANCADOBECODEBANCADOBECODEBANCADOBECODEBANCADOBECODEBANCADOBECODEBANCADOBECODEBANCADOBEADOBECODEBANCADOBECODEBANCCODEBANCADOBECODEBANCADOBECODEBANCADOBECODEBANCADOBECODEBANCADOBECODEBANC";
    string t = "ABC";
    Solution S;
    cout << S.minWindow(s, t) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}