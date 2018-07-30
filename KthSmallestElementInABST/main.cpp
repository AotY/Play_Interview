#include <iostream>
#include <vector>
#include <cassert>
#include <stack>


using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


enum Operator {
    GO, PRINT
};

struct Command {
    Operator op;
    TreeNode *node;

    Command(Operator o, TreeNode *n) : op(o), node(n) {}
};

class Solution {
private:
    int binarySearchPos(vector<int> &binaryArr, int left, int right, int val) {
        if (right > binaryArr.size())
            return right;

        while (left <= right) {
            int mid = (left + right) >> 1;
            if (binaryArr[mid] == val)
                return mid;
            else if (binaryArr[mid] > val)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

public:
    int kthSmallest(TreeNode *root, int k) {
        if (root == NULL)
            return 0;
        //
        stack<Command> traversalStack;
        traversalStack.push(Command(GO, root));

        // 二分查找法来确定位置
        vector<int> binaryArr(k, 9999);

        int left = 0;
        int right = k;

        while (!traversalStack.empty()) {
            Command command = traversalStack.top();
            traversalStack.pop();

            if (command.node != NULL) {
                if (command.op == GO) {
                    traversalStack.push(Command(GO, command.node->right));
                    traversalStack.push(Command(PRINT, command.node));
                    traversalStack.push(Command(GO, command.node->left));
                } else {
                    int val = command.node->val;

                    int pos = binarySearchPos(binaryArr, left, right, val);
                    // 最多有k个元素
//                    right = max(right, pos);
                    // 调整数组
                    for (int i = right; i < pos; --i) {
                        binaryArr[k] = binaryArr[k - 1];
                    }
                    binaryArr[pos] = val;
                }
            }

        }
        return binaryArr[k-1];
    }
};

int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}