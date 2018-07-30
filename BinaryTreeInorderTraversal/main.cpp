#include <iostream>
#include <vector>
#include <cassert>

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

// 递归版本

class Solution {
private:
    vector<int> results;

    void inorder(TreeNode *root) {

        if (root == NULL)
            return;

        // 访问左孩子
        inorder(root->left);
        // 访问元素
        results.push_back(root->val);

        // 访问右孩子
        inorder(root->right);

    }

public:
    vector<int> inorderTraversal(TreeNode *root) {

        inorder(root);
        return results;
    }
};


int main() {

    Solution s;

    s.inorderTraversal()
    std::cout << "Hello, World!" << std::endl;
    return 0;
}