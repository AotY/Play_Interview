#include <iostream>
#include <vector>

using namespace std;


class Solution {
private:
    vector<vector<string>> results;

    void searchPartition(string s, int index, vector<string> &res) {
        if (index >= s.size()) {
            results.push_back(res);
            return;
        }

        // two situations

        //1.
        res.push_back(s.substr(index, 1));
        searchPartition(s, index + 1, res);
        res.pop_back();


        //2. whether s[index ... s.size()-1] is a palindrome
        int mid = (s.size() - 1 + index) / 2;
        if (mid < s.size() - 1) {
            bool isP = true;
            for (int i = index; i <= mid; ++i) {
                if (s[i] != s[s.size() - i - 1]) {
                    isP = false;
                    break;
                }
            }

            if (isP) {
                res.push_back(s.substr(index, s.size() - index));
                searchPartition(s, s.size(), res);
                res.pop_back();
            }
        }

        // 3. s[0...index]
        mid = (0 + index) / 2;
        bool isP = true;
        for (int i = 0; i <= mid; ++i) {
            if (s[i] != s[index - i]) {
                isP = false;
                break;
            }
        }

        if (isP) {
            res.push_back(s.substr(0, index + 1));
            searchPartition(s, index + 1, res);
            res.pop_back();
        }

        return;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> res;
        res.clear();
        searchPartition(s, 0, res);
        return results;
    }
};


int main() {
    Solution s;
    vector<vector<string>> results = s.partition("aba");

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