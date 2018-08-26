#include <iostream>
#include <vector>

using namespace std;


/**
    Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


// 每次需要找到k个链表中的最小值
class Solution {
private:
    ListNode *tryMergeList(vector<ListNode *> &newLists) {

        int k = newLists.size();

        if (k == 0)
            return NULL;

        int minVal = INT_MAX;
        int minListIndex = 0;
        ListNode *minNode;
        for (int i = 0; i < k; ++i) {
            if (newLists[i] != NULL) {
                if (newLists[i]->val < minVal) {
                    minListIndex = i;
                    minVal = newLists[i]->val;
                }
            }
        }

        minNode = newLists[minListIndex];
        newLists[minListIndex] = newLists[minListIndex]->next;

        if (newLists[minListIndex] == NULL)
            newLists.erase(newLists.begin() + minListIndex);

        minNode->next = tryMergeList(newLists);

        return minNode;

    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {

        vector<ListNode *> newLists;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL)
                newLists.push_back(lists[i]);
        }


        return tryMergeList(newLists);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}