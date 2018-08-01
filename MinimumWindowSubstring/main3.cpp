#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    string minWindow(string S, string T) {
        if (T.size() > S.size())
            return "";

        string res = "";
        int left = 0;
        int count = 0;
        int minLen = S.size() + 1;

        int tm[256] = {0};
        int sm[256] = {0};

        for (int i = 0; i < T.size(); ++i)
            ++tm[T[i]];

        for (int right = 0; right < S.size(); ++right) {
            if (tm[S[right]] != 0) {

                ++sm[S[right]];

                if (sm[S[right]] <= tm[S[right]])
                    ++count;

                while (count == T.size()) {
                    // 更新最小子串
                    int curLen = right - left + 1;
                    if (curLen < minLen) {
                        minLen = curLen;
                        res = S.substr(left, minLen);
                    }

                    if (tm[S[left]] != 0) {
                        --sm[S[left]];

                        if (sm[S[left]] < tm[S[left]])
                            --count;
                    }

                    ++left;
                }
            }
        }
        return res;
    }
};


int main() {
    string s = "ABDAEC";
    string t = "ABC";
    Solution S;
    cout << S.minWindow(s, t) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}