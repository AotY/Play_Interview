#include <iostream>
#include <string>

using namespace std;


class Solution {

private:
    int searchLcs(string &s1, string &s2, int m, int n) {
        if (m < 0 || n < 0)
            return 0;
        int res = 0;
        if (s1[m] == s2[n])
            res += 1 + searchLcs(s1, s2, m - 1, n - 1);
        else {
            res = max(searchLcs(s1, s2, m, n - 1),
                      searchLcs(s1, s2, m - 1, n));
        }
        return res;
    }

public:
    int lcs(string &s1, string &s2) {
        int m = s1.size();
        int n = s2.size();
        if (m == 0 || n == 0)
            return 0;

        int res = searchLcs(s1, s2, m-1, n-1);


        return res;
    }
};


int main() {
    string s1 = "abacdfgdcaba";
    string s2 = "abacdgfdcaba";

    Solution s;
    cout<<s.lcs(s1, s2)<<endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}