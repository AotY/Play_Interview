#include <iostream>


/**
   Definition for singly-linked list.

 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL || l2 == NULL)
            return l1 == NULL ? l2 : l1;


        // base on l1
        ListNode *head = new ListNode(0);
        head->next = NULL;

        ListNode *tmpHead = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                // 添加l1节点
                tmpHead->next = l1;
                l1 = l1->next;

                tmpHead = tmpHead->next;
                tmpHead->next = NULL;


            } else {
                // 添加l2节点

                tmpHead->next = l2;
                l2 = l2->next;

                tmpHead = tmpHead->next;
                tmpHead->next = NULL;

            }

        }

        if (l1 != NULL)
            tmpHead->next = l1;

        if (l2 != NULL)
            tmpHead->next = l2;

        return head->next;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}