#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:

    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for (auto c: t) map[c]++;
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size()) {
            if (map[s[end++]]-- > 0) counter--; //in t
            while (counter == 0) { //valid
                if (end - begin < d) d = end - (head = begin);
                if (map[s[begin++]]++ == 0) counter++;  //make it invalid
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }

};


int main() {
    string s = "ABC";
    string t = "AB";
    Solution S;
    cout << S.minWindow(s, t) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}