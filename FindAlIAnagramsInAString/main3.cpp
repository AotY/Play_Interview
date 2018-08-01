#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ret;
        int j;
        if (s.empty() || p.empty() || p.length() > s.length())
            return ret;

        int tbl[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int pt[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        int l = p.length();
        for (int i = 0; i < l; i++) {
            pt[p[i] - 'a']++;
            tbl[s[i] - 'a']++;
        }

        for (int i = 0; i <= s.length() - l; i++) {
            for (j = 0; j < 26; j++) {
                if (tbl[j] != pt[j])
                    break;
            }
            if (j == 26)
                ret.push_back(i);
            tbl[s[i] - 'a']--;
            if (i + l < s.length())
                tbl[s[i + l] - 'a']++;
        }

        return ret;
    }
};

int main() {
    Solution s;
    string s1 = "abacbabc";
    string s2 = "abc";
    // [1,2,3,5]
    vector<int> results = s.findAnagrams(s1, s2);
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << ", ";
    }
    cout << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}