#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
private:
    vector<vector<string>> results;
    map<string, bool> palindromeMap;

    bool isPalindrome(string &str) {
        int len = str.size();

        if (len == 0 || len == 1)
            return true;

        for (int i = 0; i < len / 2; ++i)
            if (s[i] != s[len - 1 - i])
                return false;

        return true;

    }

    void searchPartition(string &s, int index, vector<string> &res) {

        if (index >= s.size()) {
            results.push_back(res);
            return;
        }

        for (int i = 0; i < s.size() - index; ++i) {
            string subStr = s.substr(index, i + 1);
            bool isP = true;
            if (palindromeMap.find(subStr) != palindromeMap.end()) {
                isP = palindromeMap[subStr];
            } else {
                isP = isPalindrome(subStr);
                palindromeMap[subStr] = isP;
            }

            if (isP) {
                res.push_back(subStr);
                searchPartition(s, index + i + 1, res);
                res.pop_back();
            }

        }

        return;
    }

public:
    vector<vector<string>> partition(string &s) {

        vector<string> res;
        searchPartition(s, 0, res);
        return results;
    }
};


int main() {
    Solution s;
    vector<vector<string>> results = s.partition("aab");

    for (int i = 0; i < results.size(); ++i) {
        cout << "[ ";
        for (int j = 0; j < results[i].size(); ++j) {
            cout << results[i][j] << ", ";
        }
        cout << "], ";
        cout << endl;
    }

    return 0;
}