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

//  获取左右孩子的最大深度
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if (root == NULL)
            return 0;

        int leftDepth = 1 + maxDepth(root->left);


        int rightDepth = 1 + maxDepth(root->right);


        return max(leftDepth, rightDepth);

    }
};

int main() {

    TreeNode *root = new TreeNode(3);

    TreeNode *node1 = new TreeNode(5);

    TreeNode *node2 = new TreeNode(1);
    root->left = node1;
    root->right = node2;

    TreeNode *node3 = new TreeNode(6);

    TreeNode *node4 = new TreeNode(2);

    node1->left = node3;
    node1->right = node4;


    node2->left = NULL;
    node2->right = NULL;

    TreeNode *node5 = new TreeNode(0);
    TreeNode *node6 = new TreeNode(0);
    node3->left = node5;
    node3->right = node6;

    node5->left = NULL;
    node5->right = NULL;

    node6->left = NULL;
    node6->right = NULL;

    Solution s;

    cout << s.maxDepth(root) << endl;

    return 0;
}