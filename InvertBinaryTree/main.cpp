#include <iostream>


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


class Solution {
private:
    void tryInveretTree(TreeNode* node) {
        if (node == NULL)
            return;

        tryInveretTree(node->left);
        tryInveretTree(node->right);
        swap(node->left, node->right);
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        tryInveretTree(root);
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}