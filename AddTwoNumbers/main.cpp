#include <iostream>
#include <stack>
#include <vector>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
private:
    long unsigned int list2Integer(ListNode *node) {
        ListNode *tmp = node;
        long unsigned int res = 0;
        long unsigned int l = 1;
        while (tmp != NULL) {
            res += tmp->val * l;
            l *= 10;
            tmp = tmp->next;
        }
        return res;
    }

    ListNode *integer2List(long unsigned int sum) {
        stack<int> listSum;
        int l = 10;
        while (sum != 0) {
            listSum.push(sum % l);
            sum /= l;
        }
        ListNode *head = new ListNode(-1);
        head->next = NULL;
        while (!listSum.empty()) {
            int val = listSum.top();
            listSum.pop();
            ListNode *node = new ListNode(val);
            node->next = head->next;
            head->next = node;
        }

        // 创建节点
        return head->next;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        long unsigned int integer1 = list2Integer(l1);
        long unsigned int integer2 = list2Integer(l2);

        if (integer1 == 0 && integer2 == 0)
            return l1;

        long unsigned int sum = integer1 + integer2;


        return integer2List(sum);
    }
};


int main() {

//    int res = 9999999991 + 9;
//    cout<<res<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}