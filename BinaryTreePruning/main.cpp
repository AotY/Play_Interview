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
    bool isContainingOneNode(TreeNode *node) {

        if (node == NULL)
            return false;

        // cur node
        if (node->val != 0)
            return true;

        // left children
        // right children
        return isContainingOneNode(node->left) || isContainingOneNode(node->right);
    }
public:
    TreeNode *pruneTree(TreeNode *root) {

        if (root == NULL)
            return NULL;

        if (!isContainingOneNode(root)) {
            return NULL;
        }

        if (root->left != NULL)
            root->left = pruneTree(root->left);

        if (root->right != NULL)
            root->right = pruneTree(root->right);

        return root;
    }
};


int main() {

    TreeNode *root = new TreeNode(1);

    TreeNode *node2 = new TreeNode(0);
    root->left = NULL;
    root->right = node2;

    TreeNode *node3 = new TreeNode(0);

    TreeNode *node4 = new TreeNode(1);

    node2->left = node3;
    node2->right = node4;


    node3->left = NULL;
    node3->right = NULL;

    node4->left = NULL;
    node4->right = NULL;


    Solution s;
    cout << s.pruneTree(root) << endl;
    return 0;
}