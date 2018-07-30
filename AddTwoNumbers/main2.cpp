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

// long long int 范围超出，还是不能用int, 考虑用char，或者 vector
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
private:
    vector<int> list2Integer(ListNode *node) {
        ListNode *tmp = node;
        vector<int> resList;
        while (tmp != NULL) {
            resList.push_back(tmp->val);
            tmp = tmp->next;
        }
        return resList;
    }

    vector<int> vectorSum(vector<int> &list1, vector<int> &list2) {
        int n1 = list1.size();
        int n2 = list2.size();

        int maxN = n1 > n2 ? n1 : n2;

        int minN = n1 <= n2 ? n1 : n2;

        vector<int> sumList;
        bool isCarryOver = false;

        for (int i = 0; i < maxN; ++i) {
            int sum = 0;
            if (i < minN)
                sum = list1[i] + list2[i];
            else
                sum = n1 > n2 ? list1[i] : list2[i];

            if (isCarryOver) {
                sum += 1;
                isCarryOver = false;
            }

            if (sum >= 10) {
                isCarryOver = true;
                sum = sum - 10;
                if (i == (maxN - 1)) {
                    sumList.push_back(sum);
                    sum = 1;
                }
            }
            sumList.push_back(sum);
        }

        return sumList;

    }

    ListNode *vector2List(vector<int> &sumList) {

        ListNode *head = new ListNode(-1);
        head->next = NULL;
        for (int i = sumList.size() - 1; i >= 0; i--) {
            ListNode *node = new ListNode(sumList[i]);
            node->next = head->next;
            head->next = node;
        }
        // 创建节点
        return head->next;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        vector<int> list1 = list2Integer(l1);
        vector<int> list2 = list2Integer(l2);

        vector<int> sumList = vectorSum(list1, list2);

        return vector2List(sumList);
    }
};


int main() {

//    int res = 9999999991 + 9;
//    cout<<res<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}