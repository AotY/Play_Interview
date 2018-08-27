#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() < 1)
            return 0;
        if (s.size() == 1)
            return 1;

        int num = 1;

        for (int i = 1; i < s.size(); i++) {
            num++;

            for (int j = 0; j < i & i + j < s.size(); j++) {
                if (s[i - 1 - j] == s[i + j]) {
                    num++;
                } else
                    break;
            }

            for (int j = 0; j < i && i + 1 + j < s.size(); j++) {
                if (s[i - 1 - j] == s[i + 1 + j]) {
                    num++;
                } else
                    break;
            }
        }
        return num;
    }

    int main() {
        Solution s;
        cout << s.countSubstrings("aabaa") << endl;
//    std::cout << "Hello, World!" << std::endl;
        return 0;
    }