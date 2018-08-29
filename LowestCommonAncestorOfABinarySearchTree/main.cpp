#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 左小， 右大
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

        if (root == NULL)
            return NULL;

        // 当前节点就为最近公共祖先
        if (root == p || root == q)
            return root;

        // 如果在两边，则，当前节点就为最近公共祖先
        if ( (p->val < root->val && q->val > root->val) ||  (q->val < root->val && p->val > root->val))
            return root;

        TreeNode *res;
        // 左边
        if (p->val < root->val && q->val < root->val)
            res = lowestCommonAncestor(root->left, p, q);

        else
            // 右边
            res = lowestCommonAncestor(root->right, p, q);

        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}