#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0;
        int right = 0;
        int charArr[256] = {0};

        for (int i = 0; i < s.size();) {

            if (charArr[s[i]] == 1) {
                // 此时有重复元素
                charArr[s[left]]--;
                left++;
            } else {
                // 没有重复元素
                charArr[s[i]] += 1;
                i++;
                right++;
            }

            res = max(res, right - left);
        }

        return res;

    }
};

int main() {
    string str = "pwwkew";
    Solution s;
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}