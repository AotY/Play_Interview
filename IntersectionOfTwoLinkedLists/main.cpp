#include <iostream>

using namespace std;

/**
 *Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

//  要找到相交的前一个元素
// 下一个元素是否相等 ？
class Solution {
private:
    int getLen(ListNode *head) {
        int len = 0;
        ListNode *tmp = head;
        while (tmp != NULL) {
            len ++;
            tmp = tmp->next;
        }
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL)
            return NULL;

        int lenA = getLen(headA);
        int lenB = getLen(headB);

//        int maxLen = lenA >= lenB ? lenA : lenB;
//        int minLen = lenA < lenB ? lenA : lenB;

        int sub = abs(lenA - lenB);
        ListNode *maxTmp;
        ListNode *minTmp;
        if (lenA >= lenB) {
            maxTmp = headA;
            minTmp = headB;
        } else{
            maxTmp = headB;
            minTmp = headA;
        }

//        ListNode *maxTmp = lenA >= lenB ? headA : headB;
//        ListNode *minTmp = lenA < lenB ? headA : headB;

        int index = 0;
        while (maxTmp != NULL) {
            index ++;
            if (index <= sub) {
                maxTmp = maxTmp->next;
                continue;
            }

            // 相同长度开始比较
            if (maxTmp->val == minTmp->val){
                return maxTmp;
            } else {
                minTmp = minTmp->next;
                maxTmp = maxTmp->next;
            }
        }

        return NULL;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}