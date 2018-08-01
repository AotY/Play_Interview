#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string longestPalindrome(string s) {
        //insert "#"
        string temp = "$#";

        for (int i = 0; i < s.size(); ++i) {
            temp += s[i];
            temp += "#";
        }

        //find the longestPalindrome in temp
        vector<int> p(temp.size(), 0);

        int idx = 0, r_max = 0, res_center = 0, res_length = 0;

        for (int i = 0; i < temp.size(); ++i) {
            p[i] = (r_max > i) ? min(p[2 * idx - i], r_max - i) : 1;

            while (temp[i + p[i]] == temp[i - p[i]]) ++p[i];
            if (r_max < i + p[i]) {
                idx = i;
                r_max = i + p[i];
            }
            if (res_length < p[i]) {
                res_length = p[i];
                res_center = i;
            }
        }

        return s.substr((res_center - res_length) / 2, res_length - 1);
    }
};


int main() {
    Solution s;
    cout << s.longestPalindrome("bbd") << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}