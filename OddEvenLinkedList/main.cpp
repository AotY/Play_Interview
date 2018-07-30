#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.

 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//  思路不对
class Solution {
private:
    void moveList(ListNode *head) {
        ListNode *odd = new ListNode(0);
        odd->next = NULL;

        ListNode *even = new ListNode(0);
        even->next = NULL;

        ListNode *tmp = head;

        int index = 0;
        while (tmp != NULL) {
            index ++;
            if (index % 2 == 1) {
                // odd
                if(odd->next != NULL) {
                    int tmpVal = odd->val;
                    odd->val = tmp->val;
                    tmp->val = tmpVal;

                    odd->next = tmp;
                    odd->val =
                } else {
                    odd->next = tmp;
                    odd->val = tmp->val;
                }

            } else{
                // even
                if(even->next != NULL) {
                    int tmpVal = even->val;
                    even->val = tmp->val;
                    tmp->val = tmpVal;

                    even->next = tmp;
                } else {
                    even->next = tmp;
                    even->val = tmp->val;
                }
            }
            tmp = tmp->next;
        }
    }
public:
    ListNode* oddEvenList(ListNode* head) {

        moveList(head);
        return head;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}