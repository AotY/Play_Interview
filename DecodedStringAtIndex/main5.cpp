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

        int n = S.size();

//        long *dp = new long[n+1];
        long dp[10] = {0};

//        for (int j = 0; j < n+1; ++j) {
//            dp[j] = 0;
//        }

        string res;

        for(int i = 0;i < n;i++){
            if(S[i] >= '2' && S[i] <= '9'){
                dp[i+1] = dp[i] * (S[i]- '0' );
            }else{
                dp[i+1] = dp[i] + 1;
            }
        }

        K--;

        for(int i = n-1;i >= 0;i--){
            K %= dp[i+1];
            if(K+1 == dp[i+1] && !(S[i] >= '2' && S[i] <= '9')){
                res.push_back(S[i]);
                return res;
            }
        }
        return NULL;
    }
};

int main() {
    Solution s;

    cout << s.decodeAtIndex("ha22", 5) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}