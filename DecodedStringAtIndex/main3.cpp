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

        string decodeS = "";
        int startIndex = 0;
        for (int i = 0; i < len; ++i) {
            if ('a' <= S[i] && S[i] <= 'z') { // 字母
                decodeS += S[i];
                if (decodeS.size() == K)
                    break;
            } else {
                // 数字，不用扩展，每次只读一个字符
                int n = S[i] - '0';
                int curLen = decodeS.size();
                bool isBreak = false;
                //  这里还是超时
                for (int j = 0; j < (n - 1); ++j) {
                    decodeS += decodeS.substr(0, curLen);

                    if (decodeS.size() >= K) {
                        isBreak = true;
                        break;
                    }
                }

                if (isBreak)
                    break;
            }


        }

        return decodeS.substr(K-1, 1);
    }
};

int main() {
    Solution s;

    cout << s.decodeAtIndex("y959q969u3hb22odq595", 222280369) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}