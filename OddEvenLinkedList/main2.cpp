#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.

 */
// 改进
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    void moveList(ListNode *head) {
        ListNode *odd = head;
        ListNode *even = NULL; // 第一个 even 位置

        ListNode *tmp = head;
        // 保证 [1, k] 为odd

        int index = 0;
        while (tmp != NULL) {
            index++;
            if (index == 2)
                even = tmp;

            if (index % 2 == 0) {
                // even
                if (tmp->next != NULL) {
                    odd->next = tmp->next;
                    tmp->next = odd->next->next;
                    odd->next->next = even;

                    odd = odd->next;

                    index ++; //  位置变了，注意注意
                }
            }
            tmp = tmp->next;
        }
    }

public:
    ListNode *oddEvenList(ListNode *head) {

        moveList(head);
        return head;
    }
};

int main() {
//    std::cout << "Hello, World!" << std::endl;

    return 0;
}