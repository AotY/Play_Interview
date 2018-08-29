#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool hasPathSum(TreeNode *node, int sum) {

        // 如果没有找到

        if (node == NULL)
            return false;


        // 叶子节点
        if (node->right == NULL && node->left == NULL) {
            if (node->val == sum)
                return true;

            return false;
        }


        return
                hasPathSum(node->left, sum - node->val) ||       // 左孩子，减去当前节点值
                hasPathSum(node->right, sum - node->val);         // 右孩子


    }
};


int main() {

    TreeNode *root = new TreeNode(-2);

    TreeNode *node1 = new TreeNode(1);

    TreeNode *node2 = new TreeNode(-3);
    root->left = node1;
    root->right = node2;

    node1->left = NULL;
    node1->right =NULL;

    node2->left = NULL;
    node2->right = NULL;


    Solution s;
    cout << s.hasPathSum(root, -5) << endl;
    return 0;
}