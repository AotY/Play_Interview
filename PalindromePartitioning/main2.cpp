#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
private:
    vector<vector<string>> results;
    map<string, bool> palindromeMap;

    void searchPartition(string s, int index, vector<string> &res) {

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
                int mid = ( subStr.size() - 1) / 2;
                for (int j = 0; j <= mid; ++j) {
                    if (subStr[j] != subStr[subStr.size() - 1 - j]) {
                        isP = false;
                        break;
                    }
                }

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
    vector<vector<string>> partition(string s) {

//        for (int i = 0; i < s.size(); ++i) {
//            vector<string> res;
//            res.clear();
//            res.push_back(s.substr(0, i + 1));
//            searchPartition(s, i + 1, res);
//
//        }
        vector<string> res;
        res.clear();
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