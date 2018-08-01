#include <iostream>
#include <string>
#include <set>
using namespace std;

// 速度太慢
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;

        int res = 1;
        set<char> charSet;
        charSet.insert(s[0]);

        int left = 0;
        int right = 1;
        int curCount = 1;
        while(true) {
            if (right >= s.size())
                break;

//            set<char>::iterator it = charSet.find(s[right]);
//            auto it = charSet.find(s[right]);
            const bool is_in = charSet.find(s[right]) != charSet.end();
            if (is_in) { // is_init != charSet.end()
                // 已包含当前元素
                res = max(res, curCount);
                charSet.clear();
                curCount = 0;
                left ++;
                right = left;
            } else {
                charSet.insert(s[right]);
                curCount ++ ;
                right ++;
            }
        }

        res = max(res, curCount);
        return res;

    }
};

int main() {
    string str = "dvdf";
    Solution s;
    cout<<s.lengthOfLongestSubstring(str)<<endl;
    return 0;
}