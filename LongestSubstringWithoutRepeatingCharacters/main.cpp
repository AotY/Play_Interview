#include <iostream>
#include <string>
using namespace std;

// 1， 用桶方法，思路错误，不是求 字符个数，是求最长不重复子序列长度
class Solution {
private:
    const int MAX_SIZE = 256;

public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;

        int bucket[MAX_SIZE + 1];
        // init
        for (int i = 0; i <= MAX_SIZE; ++i) {
            bucket[i] = 0;
        }

        for (int i = 0; i < s.size(); ++i) {
            int index = s[i];
            bucket[index] += 1;
        }

        for (int i = 0; i <= MAX_SIZE; ++i) {
            if (bucket[i] != 0)
                res ++;
        }

        return res;
    }
};

int main() {
    string str = "pwwkew";
    Solution s;
    cout<<s.lengthOfLongestSubstring(str)<<endl;
    return 0;
}