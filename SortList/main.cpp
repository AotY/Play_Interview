#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    vector<int> getNums(ListNode *tmpHead) {
        vector<int> nums;

        while (tmpHead != NULL) {
            nums.push_back(tmpHead->val);
            tmpHead = tmpHead->next;
        }

        return nums;
    }

public:

    ListNode *sortList(ListNode *head) {
        if (head == NULL)
            return head;

        ListNode *tmpHead = head;

        vector<int> nums = getNums(tmpHead);


        sort(nums.begin(), nums.end());
        tmpHead = head;
        for (int i = 0; i < nums.size(); ++i) {
            tmpHead->val = nums[i];
            tmpHead = tmpHead->next;
        }

        return head;
    }
};

int main() {


    return 0;
}