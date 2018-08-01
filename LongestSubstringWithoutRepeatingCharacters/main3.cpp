#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> dict(256, -1);
        int start = -1;
        int res = 0;

        for (int i = 0; i < s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];

            dict[s[i]] = i;

            res = max(res, i - start);
        }
        return res;
    }
};

int main() {
    string str = "abc";
    Solution s;
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}