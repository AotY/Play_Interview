#include <iostream>
#include <vector>
#include <cassert>
#include <stack>

using namespace std;


/**
 * Definition for a binary tree node.
 *
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive solution is trivial, could you do it iteratively?


enum Operator {GO, PRINT};

struct Command {
    Operator op;
    TreeNode *node;
    Command(Operator o, TreeNode *n) : op(o), node(n) {}
};

class Solution {
public:

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> results;

        if (root == NULL)
            return results;

        // 初始化栈
        stack<Command> traversalStack;
        traversalStack.push(Command(GO, root));

        while (!traversalStack.empty()) {
            //  取出第一个元素
            Command command = traversalStack.top();
            traversalStack.pop();

            if (command.node == NULL)
                continue;

            if (command.op == GO) {
                // 中序编译，加入栈中顺序：右 中 左，访问顺序：左，中，右
                traversalStack.push(Command(GO, command.node->right));
                traversalStack.push(Command(PRINT, command.node));
                traversalStack.push(Command(GO, command.node->left));
            } else {
                results.push_back(command.node->val);
            }
        }

        return results;
    }
};


int main() {

    Solution s;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}