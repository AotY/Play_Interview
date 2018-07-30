//
// Created by Leon Tao on 09/07/2018.
//

#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H

#endif //TRIE_TRIE_H


#include <iostream>
#include <string>


const int ALPHABET_SIZE = 128;

struct TrieNode {
    struct TrieNode *childrenNodes[ALPHABET_SIZE];
    bool isEndOfWord;

//    TrieNode() : isEndOfWord(false), childrenNodes{NULL} {}
};

class Trie {

private:
    TrieNode *root;


public:

    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    // new
    TrieNode *getNode() {
        TrieNode *node = new TrieNode;
        node->isEndOfWord = false;

        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            node->childrenNodes[i] = NULL;
        }
    }


    void insertWord(std::string word) {
        if (word.size() == 0)
            return;

        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i) {

            int alphabetIndex = word[i];

            if (cur->childrenNodes[alphabetIndex] == NULL) {

                cur->childrenNodes[alphabetIndex] = getNode();
            }

            cur = cur->childrenNodes[alphabetIndex];

            if (i == (word.size() - 1)) {
                cur->isEndOfWord = true;
                break;
            }
        }

    }

    bool searchWord(std::string word) {

        if (word.size() == 0)
            return false;

        TrieNode *cur = root;

        for (int i = 0; i < word.size(); ++i) {

            int alphabetIndex = word[i];

            if (cur->childrenNodes[alphabetIndex] != NULL) {

                cur = cur->childrenNodes[alphabetIndex];
                if (i == (word.size() - 1)) {
                    return cur->isEndOfWord;
                }
            } else {
                return false;
            }
        }

        return cur->isEndOfWord && cur;
    }


};



