#include <iostream>
#include <vector>

using namespace std;


const int CHAR_SIZE = 26;


int getCharIndex(char c) {
    return c - 'a';
}

struct TreeNode {
    string word;

    TreeNode *child[CHAR_SIZE]; //  只有26个字母

    TreeNode() {
        for (int i = 0; i < CHAR_SIZE; ++i) {
            child[i] = NULL;
        }
    }

};

bool insert(TreeNode *root, string word) {
    TreeNode *tmpRoot = root;
    int missingCount = 0;
    TreeNode *lastRoot = root;
    int lastCharIndex;
    for (int i = 0; i < word.size(); ++i) {
        int charIndex = getCharIndex(word[i]);
        if (tmpRoot->child[charIndex] == NULL) {
            missingCount++;
            if (missingCount >= 2) {
                lastRoot->child[lastCharIndex] = NULL;
                return false;
            }

            tmpRoot->child[charIndex] = new TreeNode();
        }
        lastRoot = tmpRoot;
        lastCharIndex = charIndex;
        tmpRoot = tmpRoot->child[charIndex];

    }
    tmpRoot->word = word;

    return true;
}

class Solution {
public:
    string longestWord(vector<string> &words) {
        string res;
        int n = words.size();
        if (n == 0)
            return res;

        sort(words.begin(), words.end(), [&](string &s1, string &s2) {
            if (s1.size() != s2.size())
                return s1.size() < s2.size();
            else
                return s1 < s2;

        });

        // 创建前缀树
        TreeNode *root = new TreeNode();

        vector<string> results;

        for (int i = 0; i < n; ++i) {
            bool flag = insert(root, words[i]);

            if (flag) {
                results.push_back(words[i]);
            }
        }


        sort(results.begin(), results.end(), [&](string &s1, string &s2) {
            if (s1.size() != s2.size())
                return s1.size() < s2.size();
            else
                return s1 > s2;

        });

        res = results[results.size() - 1];
        return res;
    }
};


int main() {

    Solution s;
    vector<string> words = {
            "sg", "qgca", "s", "qzu", "qzub", "qzubvs", "hlyc", "hl", "qg", "qzubv", "qgc", "qgcab", "qz", "sgs",
            "sgsnyn", "hly", "hlycf", "sgsn"
    };
    cout << s.longestWord(words) << endl;
    return 0;
}
