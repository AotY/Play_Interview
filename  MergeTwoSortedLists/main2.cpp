#include <iostream>


/**
   Definition for singly-linked list.

 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// 这个递归思路很棒
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL || l2 == NULL)
            return (l1 == NULL ? l2 : l1);

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }

    }//end function
};//end class

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}