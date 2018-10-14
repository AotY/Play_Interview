#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {

    public:
        int lengthOfLongestSubstring(string &s) {
            
            int n = s.size();

            int left = 0;
            int right = -1;
            // [left, right]
            int res = 0;

            vector<int> books = vector<int>(256, 0);

            while (left < n) {
                if (right + 1 < n && books[s[right + 1]] == 0) {
                    books[s[++right]] += 1;

                } else {
                    books[s[left++]] -= 1;
                }

                res = max(res, right - left + 1);
            }
            return res;
        }
};

int main() {

    string str("abcdac");
    Solution s;

    int res = s.lengthOfLongestSubstring(str);
    cout << res << endl;


    return 0;
}
