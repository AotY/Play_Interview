#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
private:
    map<int, RandomListNode *> valNodeMap;

public:
    RandomListNode *copyRandomList(RandomListNode *node) {

        if (node == NULL) {
            return node;
        }
        
        RandomListNode *newNode;
        if (valNodeMap.find(node->val) != valNodeMap.end()) {
            // has a node, which contains val same to node 
            newNode = valNodeMap[node->val];
        } else {
            newNode = new RandomListNode(node->val);
        }
        
        // next node
        if (node->next != NULL)) {
            if (valNodeMap.find(node->next->val) != valNodeMap.end()) {
                newNode->next = valNodeMap[node->next->val];
            } else {
                newNode->next = copyRandomList(node);    
            }
        }


        // random node
        if (node->random != NULL) {
            if (valNodeMap.find(node->random->val) != valNodeMap.end()) {
                newNode->random = valNodeMap[node->random->val];
            } else {
                RandomListNode *randomNode = new RandomListNode(node->random->val);
                randomNode->next = node->random->next;
                randomNode->random = node->random->random;
                newNode->random = randomNode;

                valNodeMap.insert(make_pair(node->random->val, randomNode));
            }
        }

        return newNode;

    }
};

