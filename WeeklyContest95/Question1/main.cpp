#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 *
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};



// 找到中间节点元素返回

class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        if (head == NULL)
            return NULL;

        ListNode *result;

//        ListNode *pointArr[100 + 1];
        ListNode **pointArr = new ListNode *[101];


        // 尼玛，没有头结点😕。。。
        ListNode *tmpNode = head->next;
        int len = 0;
        while (tmpNode != NULL) {
            ListNode *n = new ListNode(tmpNode->val);
            n->next = tmpNode->next;
            pointArr[len] = n;
            len++;
            tmpNode = tmpNode->next;
        }
        if (len == 1)
            return pointArr[1];
        else
            return pointArr[(len / 2)];

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}