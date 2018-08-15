#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    string word;
    TreeNode *child[26];

    TreeNode() {
        for (int i = 0; i < 26; ++i) {
            child[i] = NULL;
        }
    }
};

class Trie {
private:
    TreeNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TreeNode();
    }

    /** Inserts a word into the cout<<trie. */
    void insert(string word) {
        TreeNode *tmpRoot = root;
        for (int i = 0; i < word.size(); ++i) {
            int charIndex = word[i] - 'a';
            if (tmpRoot->child[charIndex] == NULL)
                tmpRoot->child[charIndex] = new TreeNode();

            tmpRoot = tmpRoot->child[charIndex];
        }
        tmpRoot->word = word;
    }

    /** Returns if the word is in the cout<<trie. */
    bool search(string word) {
        TreeNode *tmpRoot = root;
        for (int i = 0; i < word.size(); ++i) {
            int charIndex = word[i] - 'a';
            if (tmpRoot->child[charIndex] == NULL)
                return false;

            tmpRoot = tmpRoot->child[charIndex];
        }
        if (tmpRoot->word == word)
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode *tmpRoot = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int charIndex = prefix[i] - 'a';
            if (tmpRoot->child[charIndex] == NULL)
                return false;

            tmpRoot = tmpRoot->child[charIndex];
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() {

    Trie trie;

    trie.insert("apple");
    cout << trie.search("apple") << endl;   // returns true
    cout << trie.search("app") << endl;     // returns false
    cout << trie.startsWith("app") << endl; // returns true
    trie.insert("app");
    cout << trie.search("app") << endl;     // returns true


    return 0;
}