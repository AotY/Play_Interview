#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {

        // 最长公共前缀
        int n = strs.size();

        if (n == 0)
            return "";

        vector<set<string>> filterSets = vector<set<string>>(n, set<string>());
        for (int i = 0; i < n; ++i) {
            for (int count = 1; count <= strs[i].size(); ++count) {
                // substr [pos, pos+count)
                string prefix = strs[i].substr(0, count);
                filterSets[i].insert(prefix);
            }
        }

        string res = "";
        for (set<string>::iterator it = filterSets[0].begin(); it != filterSets[0].end(); it++) {
            string curPrefix = *it;

            bool isCommon = true;
            for (int j = 1; j < n; ++j) {
                if (filterSets[j].find(curPrefix) == filterSets[j].end()) {
                    isCommon = false;
                    break;
                }

            }

            if (isCommon)
                res = curPrefix;
        }

        return res;
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