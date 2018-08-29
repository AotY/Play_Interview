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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

        if (root == NULL)
            return NULL;

        // 左边
        if (p->val < root->val && q->val < root->val)
            lowestCommonAncestor(root->left, p, q);

        // 右边
        if (p->val > root->val && q->val > root->val)
            lowestCommonAncestor(root->right, p, q);


        //  就是当前节点
        return roo;
    }


};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}