#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string> &A) {

        unordered_map<string, int> mp;

        // 这个可以的
        for (auto &str : A) {
            string evenStr;
            string oddStr;

            for (int i = 0; i < str.size(); i += 2)
                evenStr.push_back(str[i]);

            for (int i = 1; i < str.size(); i += 2)
                oddStr.push_back(str[i]);

            sort(evenStr.begin(), evenStr.end());

            sort(oddStr.begin(), oddStr.end());

            string newStr = evenStr + oddStr;

            mp[newStr] ++ ;
        }
        return mp.size();
    }
};

int main() {
    Solution s;

//    vector<string> A = {"couxuxaubw", "zsptcwcghr", "kkntvvhbcc", "nkhtcvvckb", "crcwhspgzt"};
    vector<string> A = {"kkntvvhbcc", "nkhtcvvckb"};
//    vector<string> A = {"abcd", "cdab", "adcb", "cbad"};
    cout << s.numSpecialEquivGroups(A) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}