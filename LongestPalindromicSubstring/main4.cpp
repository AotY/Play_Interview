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
        string ss = "";
        int length = s.length();

        int *radius = new int[2 * length + 1];

        for (int i = 0; i<length; i++) {
            ss +='#';
            ss +=s[i];
        }

        ss += '#';

        for (int i = 0; i <= 2 * length; i++)
            radius[i] = 0;

        radius[1] = 1;

        int i = 1;

        while (i < 2 * length) {
            if (radius[i] == 0) {
                i++;
                int j = i;
                while ((2 * i - j >= 0) && ss[j] == ss[2 * i - j])
                    j++;
                radius[i] = (j - 1) - i;
                continue;

            }

            for (int k = 1; k <= radius[i]; k++) {
                if (radius[i] - k>radius[i - k])
                    radius[i + k] = radius[i - k];
                else if (radius[i] - k < radius[i - k]) {
                    radius[i + k] = radius[i] - k;
                    i = i + k;
                }
                else if (radius[i] - k == radius[i - k]) {
                    int j = i + radius[i];
                    i = i + k;
                    while ((2 * i - j >= 0) && ss[j] == ss[2 * i - j])
                        j++;
                    radius[i] = (j-1) - i;
                    break;
                }
            }
        }

        int maxLength = 0, maxIndex = 0;
        for (int i = 0; i<2 * length; i++)
            if (radius[i]>maxLength) {
                maxLength = radius[i];
                maxIndex = i;
            }

        int startPos = maxIndex/2 - maxLength/2 ;
        string maxS(s, startPos, maxLength);
        return maxS;

    }
};


int main() {
    Solution s;
    cout << s.longestPalindrome("bbd") << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}