#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


// 归并排序思路 2

class Solution {
private:
    ListNode *mergeList(ListNode *node1, ListNode *node2) {
        ListNode *newHead = new ListNode(-1);
        ListNode *tmpHead = newHead;

        while (node1 != NULL && node2 != NULL) {
            if (node1->val < node2->val) {
                newHead->next = node1;
                node1 = node1->next;
            } else {
                newHead->next = node2;
                node2 = node2->next;
            }
            newHead = newHead->next;
        }

        if (node1 != NULL)
            newHead->next = node1;

        if (node2 != NULL)
            newHead->next = node2;

        return tmpHead->next;
    }

public:
    ListNode *sortList(ListNode *head) {

        if (head == NULL || head->next == NULL)
            return head;


        //  split list
        ListNode *pre = head, *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre->next = NULL;
        // head --> pre;   pre --> fast

        return mergeList(sortList(head), sortList(slow));

    }

};

int main() {
    ListNode *head = new ListNode(4);
    ListNode *node1 = new ListNode(2);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    Solution s;
    cout << s.sortList(head) << endl;

    return 0;
}