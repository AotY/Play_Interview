#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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

        queue<stack<Command>> commandQueue;
        stack<Command> layerStack;

        layerStack.push(Command(GO, 0, root));
        commandQueue.push(layerStack);

        queue<Command> printQueue;
        printQueue.push(Command(PRINT, 0, root));

        int order = 0;
        while (!commandQueue.empty()) {

            stack<Command> curLayerStack = commandQueue.front();
            commandQueue.pop();

            while (!curLayerStack.empty()) {
                Command command = curLayerStack.top();
                curLayerStack.pop();

                int curLayer = command.layer;
                TreeNode *curNode = command.node;

                if (curNode == NULL)
                    continue;

                if (command.op == GO) {

                    if ((curLayer + 1) % 2 == 1) { // right -> left
                        printQueue.push(Command(PRINT, curLayer + 1, curNode->right));
                        printQueue.push(Command(PRINT, curLayer + 1, curNode->left));

                        if (commandQueue.size() < 1) {
                            stack<Command> tmpLayerStack;
                            tmpLayerStack.push(Command(GO, curLayer + 1, curNode->right));
                            tmpLayerStack.push(Command(GO, curLayer + 1, curNode->left));
                            commandQueue.push(tmpLayerStack);
                        } else {
                            commandQueue.front().push(Command(GO, curLayer + 1, curNode->right));
                            commandQueue.front().push(Command(GO, curLayer + 1, curNode->left));
                        }

                    } else { // left -> right

                        printQueue.push(Command(PRINT, curLayer + 1, curNode->left));
                        printQueue.push(Command(PRINT, curLayer + 1, curNode->right));

                        if (commandQueue.size() < 1) {
                            stack<Command> tmpLayerStack;
                            tmpLayerStack.push(Command(GO, curLayer + 1, curNode->left));
                            tmpLayerStack.push(Command(GO, curLayer + 1, curNode->right));
                            commandQueue.push(tmpLayerStack);
                        } else {
                            commandQueue.front().push(Command(GO, curLayer + 1, curNode->left));
                            commandQueue.front().push(Command(GO, curLayer + 1, curNode->right));

                        }
                    }
                }
            }
        }

        while (!printQueue.empty()) {
            Command command = printQueue.front();
            printQueue.pop();

            int curLayer = command.layer;
            TreeNode *curNode = command.node;

            if (curNode == NULL)
                continue;

            // print
            if (results.size() > curLayer) {
                results[curLayer].push_back(curNode->val);
            } else {
                vector<int> layerVector;
                layerVector.push_back(curNode->val);
                results.push_back(layerVector);
            }
        }

        return results;
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}