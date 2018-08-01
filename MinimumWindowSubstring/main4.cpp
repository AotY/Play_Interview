#include <iostream>
#include <string>

using namespace std;


static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// 改进 第一种方法
class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();

        if (sLen == 0 || tLen == 0)
            return "";

        // t[i] - 'A' 耗时多
        int tArr[128] = {0};
        for (int i = 0; i < tLen; ++i)
            tArr[t[i]] += 1;

        int left = 0;
        int right = 0;

        //
        string res = "";
        int minLen = sLen + 1;

        int searchArr[128] = {0};
        int count = 0;

        while (right < sLen) {
            int index = s[right] ;
            //  如果是在 t 中的字符
            if (tArr[index] != 0) {

                searchArr[index] += 1;

                // 这里也很重要，只有当字符出现次数小于等于在t中的次数时，才进行count++;
                if (searchArr[index] <= tArr[index])
                    count ++;

                while (count == tLen) {
                    // 更新最小包含t中所有字符的子串
                    int curLen = right - left + 1;
                    if (curLen < minLen) {
                        res = s.substr(left, curLen);
                        minLen = curLen;
                    }

                    // 更新 searchArr[tmpIndex]，如果tArr[tmpIndex]包含，则 --
                    int tmpIndex = s[left];
                    if (tArr[tmpIndex])
                        searchArr[tmpIndex]--;

                    // 更新count
                    if (searchArr[tmpIndex] < tArr[tmpIndex])
                        count --;

                    // 移动left指针
                    left++;
                }
            }
            right++;
        }

        return res;
    }
};

int main() {
    string s = "AAFBEDCABEC";
    string t = "ABC";
    Solution S;
    cout << S.minWindow(s, t) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}