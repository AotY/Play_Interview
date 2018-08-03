#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

enum OP {
    GO, PRINT
};

struct Command {

    OP op;
    int layer; // which layer
    TreeNode *node;

    Command(OP op, int layer, TreeNode *node) : op(op), layer(layer), node(node) {}
};


class Solution {
private:
    vector<vector<int>> results;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == NULL)
            return results;

        stack<Command> commandStack;
        commandStack.push(Command(GO, 0, root));
        commandStack.push(Command(PRINT, 0, root));

        int order = 0;
        while (!commandStack.empty()) {

            Command command = commandStack.top();
            commandStack.pop();

            int curLayer = command.layer;
            TreeNode *curNode = command.node;

            if (curNode == NULL)
                continue;

            if (command.op == GO) {

                if ((curLayer + 1) % 2 == 1) { // right -> left
                    commandStack.push(Command(GO, curLayer + 1, curNode->right));
                    commandStack.push(Command(GO, curLayer + 1, curNode->left));

                    commandStack.push(Command(PRINT, curLayer + 1, curNode->left));
                    commandStack.push(Command(PRINT, curLayer + 1, curNode->right));
//                    commandStack.push(Command(PRINT, curLayer, curNode));

                } else { // left -> right

                    commandStack.push(Command(GO, curLayer + 1, curNode->left));
                    commandStack.push(Command(GO, curLayer + 1, curNode->right));

                    commandStack.push(Command(PRINT, curLayer + 1, curNode->right));
                    commandStack.push(Command(PRINT, curLayer + 1, curNode->left));
//                    commandStack.push(Command(PRINT, curLayer, curNode));

                }
            } else {
                // print
                if (results.size() > curLayer) {
                    results[curLayer].push_back(curNode->val);
                } else {
                    vector<int> layerVector;
                    layerVector.push_back(curNode->val);
                    results.push_back(layerVector);
                }
            }
        }

        return results;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}