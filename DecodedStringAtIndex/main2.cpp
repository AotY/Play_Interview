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
        string decodeS = "";
        for (int i = 0; i < len; ++i) {
            if ('a' <= S[i] && S[i] <= 'z') {
                // 字母
                decodeS += S[i];
            } else {
                // 数字，不用扩展，每次只读一个字符
                int n = S[i] - '0';
                int curLen = decodeS.size();
                for (int j = 0; j < (n - 1); ++j) {
                    decodeS += decodeS.substr(0, curLen);
                }
            }

            if (decodeS.size() == K)
                break;
        }

        return decodeS.substr(K-1, 1);
    }
};

int main() {
    Solution s;
    cout << s.decodeAtIndex("leet2code3", 10) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}