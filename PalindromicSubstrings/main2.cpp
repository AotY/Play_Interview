#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 递归思路，中心扩展方法

class Solution {
public:
    int countSubstrings(string s) {

        if (s.empty())
            return 0;

        int res = 0;

        for (size_t i = 0; i < s.size(); ++i) {
            countSubstrings(s, i, i, res);

            countSubstrings(s, i, i + 1, res);
        }

        return res;
    }

    void countSubstrings(const string& s, int i, size_t j, int& res) {

        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;

            ++res;
        }
    }
};

int main() {
    Solution s;
    cout << s.countSubstrings("aabaa") << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}