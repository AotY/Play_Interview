#include <iostream>

/**
 * 1. build a trie
 * 2. insert a sentence (uppercase -> lowercase)
   Every node of Trie consists of multiple branches. Each branch represents a possible character of keys. We need to mark the last node of every key as end of word node. A Trie node field isEndOfWord is used to distinguish the node as end of word node.
   3. search a word
   4. print result
 *
 * @return
 */


#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
#include "trie.h"

//using namespace std;

int main() {

    // sentence
    std::string sentence = "e Every eve node of Trie consists of multiple branches Each branch represents a possible character of keys We need to mark the last node of every key as end of word node A Trie node field isEndOfWord is used to distinguish the node as end of word node";
//    std::string sentence = "branches";

    // uppercase -> lowercase
    for (int i = 0; i < sentence.size(); ++i) {
        int alphabetIndex = sentence[i];
        if (alphabetIndex >= 65 && alphabetIndex <= 90)
            alphabetIndex = alphabetIndex + 32;
        sentence[i] = char(alphabetIndex);
    }

    // split to words
    std::string words[100];
    int wordCount = 0;
    std::istringstream iss(sentence);
    while (iss.good()) {
        iss >> words[wordCount++];
    }

    // insert to trie
    Trie* trie = new Trie();
    for (int j = 0; j < wordCount; ++j) {
        trie->insertWord(words[j]);
    }

    // find word
    std::string searchWords[4] = {"e", "eve", "multiple", "field"};
    for (int k = 0; k < sizeof(searchWords)/sizeof(searchWords[0]); ++k) {
        bool result = trie->searchWord(searchWords[k]);
        std::cout<<result<<std::endl;
    }

    delete trie;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}