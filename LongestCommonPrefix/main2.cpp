#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

// 这个思路更好一些
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {

        int vec_len = strs.size();

        if (vec_len == 0)
            return "";

        int str_len = strs[0].size();

        // ["flower","flow","flight"]
        for (int i = 0; i < str_len; ++i) {
            for (int j = 1; j < vec_len; ++j) {
                if (strs[j][i] != strs[0][i] || i > strs[j].size())
                    return strs[0].substr(0, i);
            }
        }

        return strs[0];


    }
};

int main() {
    Solution s;
    vector<string> strs = {
            "flower", "flow", "flight"
    };
    cout << s.longestCommonPrefix(strs) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}