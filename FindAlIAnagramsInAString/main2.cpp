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

private:
    bool isEqual(int *searchArr, int *pArr) {
        for (int i = 0; i < 26; ++i) {
            if (searchArr[i] != pArr[i])
                return false;
        }
        return true;
    }

    void clear2Zero(string &s, int *arr, int left, int right) {
        for (int i = left; i < right; ++i) {
            int index = s[i] - 'a';
            if (arr[index] > 0)
                arr[index] -= 1;
        }
    }

public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> results;
        int pLen = p.length();
        int sLen = s.length();

        if (pLen == 0 || sLen == 0)
            return results;

        int pArr[26] = {0};
        for (int i = 0; i < pLen; ++i) {
            pArr[p[i] - 'a'] += 1;
        }

        int left = 0;
        int right = 0;
        int count = 0;
        int searchArr[26] = {0};


        while (right < sLen) {
            int index = s[right] - 'a';

            if (pArr[index] != 0) {
                // 存在
                count++;
                searchArr[index] += 1;

                if (count == pLen) {
                    //
                    if (isEqual(searchArr, pArr)) {
                        results.push_back(left);
                    }
                    clear2Zero(s, searchArr, left, left + 1);
                    left++;
                    count -= 1;
                }
                right++;
            } else {
                // 不存在
                count = 0;
                right++;
                clear2Zero(s, searchArr, left, right);
                left = right;
            }
        }
        return results;
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