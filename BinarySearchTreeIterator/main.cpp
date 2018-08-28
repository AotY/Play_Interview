#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/**
  Definition for binary tree
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 二分搜索树的迭代器

enum NodeOperation {
    GO, PRINT
};

struct Command {
    TreeNode *node;
    NodeOperation opera;

    Command(TreeNode *_node, NodeOperation _opera) : node(_node), opera(_opera) {};
};

class BSTIterator {
private:
    TreeNode *keepRoot;
    vector<int> nums;
    int index = 0;
    int size = 0;
public:
    BSTIterator(TreeNode *root) {

        this->keepRoot = root;

        stack<Command> traStack;

        traStack.push(Command(root, GO));

        while (!traStack.empty()) {
            Command curCommand = traStack.top();
            traStack.pop();

            if (curCommand.node != NULL) {
                if (curCommand.opera == GO) {
                    traStack.push(Command(curCommand.node->right, GO));

                    traStack.push(Command(curCommand.node, PRINT));

                    traStack.push(Command(curCommand.node->left, GO));
                } else {
                    // print
                    nums.push_back(curCommand.node->val);
                }
            }
        }

        size = (int) nums.size();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index < size;
    }

    /** @return the next smallest number */
    int next() {
        return nums[index++];
    }
};

/**
  Your BSTIterator will be called like this:
  BSTIterator i = BSTIterator(root);
    while (i.hasNext())
        cout << i.next();
 */


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}