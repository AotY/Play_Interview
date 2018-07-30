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
public:
    int kthSmallest(TreeNode *root, int k) {
        if (root == NULL)
            return 0;
        //
        stack<Command> traversalStack;
        traversalStack.push(Command(GO, root));

        // 二分查找法来确定位置
        vector<int> valArr;

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
                    valArr.push_back(val);

                }
            }

        }

        sort(valArr.begin(), valArr.end(), std::less<int>());
        return binaryArr[k-1];
    }
};

int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}