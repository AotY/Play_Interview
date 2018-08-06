#include <iostream>
#include <vector>
#include <string>

using namespace std;


/**
 *
 *  输入：S = "a2345678999999999999999", K = 1
 *
 *  2 <= S.length <= 100
 *  S 只包含小写字母与数字 2 到 9 。
 *  S 以字母开头。
 *  1 <= K <= 10^9
 *  解码后的字符串保证少于 2^63 个字母。
 */

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int len = S.size();
        if (len == 2)
            return S.substr(0, 1);

        int startIndex = 0;
        // INT_MAX 2147483647 1000000000
        char *decodeChar = new char[K + 1];
        string res;
        for (int i = 0; i < len; ++i) {
            if ('a' <= S[i] && S[i] <= 'z') { // 字母
                decodeChar[++startIndex] = S[i];

                if (startIndex == K)
                    return S.substr(i, 1);


            } else {
                int n = S[i] - '0';
                int tmpIndex = startIndex;
                for (int j = 1; j < n; ++j) {
                    for (int m = 1; m <= tmpIndex; ++m) {
                        decodeChar[++startIndex] = decodeChar[m];
                        if (startIndex == K) {
                            res.push_back(decodeChar[K]);
                            return res;
                        }
                    }

                }
            }
        }

        res.push_back(decodeChar[K]);
        delete[] decodeChar;
        return res;
    }
};

int main() {
    Solution s;

    cout << s.decodeAtIndex("y959q969u3hb22odq595", 222280369) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}