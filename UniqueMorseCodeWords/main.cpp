#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;


static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
private:
    const  string MORSECODES[26] = {
            {".-"},
            {"-..."},
            {"-.-."},
            {"-.."},
            {"."},
            {"..-."},
            {"--."},
            {"...."},
            {".."},
            {".---"},
            {"-.-"},
            {".-.."},
            {"--"},
            {"-."},
            {"---"},
            {".--."},
            {"--.-"},
            {".-."},
            {"..."},
            {"-"},
            {"..-"},
            {"...-"},
            {".--"},
            {"-..-"},
            {"-.--"},
            {"--.."},
    };

public:
    int uniqueMorseRepresentations(vector<string> &words) {
        int res = 0;
        int len = words.size();
        if (len == 0)
            return res;

        set<string> codes;
        for (int i = 0; i < len; ++i) {
            string code = "";
            for (int j = 0; j < words[i].size(); ++j) {
                code += MORSECODES[(words[i][j] - 'a')];
            }
            codes.insert(code);
        }

        res = codes.size();

        return res;
    }
};


int main() {
    vector<string> words = {
            {"gin"},
            {"zen"},
            {"gig"},
            {"msg"}
    };
    Solution s;
    cout<<s.uniqueMorseRepresentations(words)<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}