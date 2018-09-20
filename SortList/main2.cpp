#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


// 归并排序思路

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;

        ListNode *slow = head, *fast = head, *pre = head;

        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return mergeTwoLists(sortList(head), sortList(slow));
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *mergedList = new ListNode(-1), *cur = mergedList;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return mergedList->next;
    }
};

int main() {


    return 0;
}