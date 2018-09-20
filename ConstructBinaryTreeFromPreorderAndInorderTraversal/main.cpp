#include <iostream>
#include <vector>

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int curRootPreIndex,
                        int left, int right) {

        if (left > right)
            return NULL;

        int curRootInIndex = left;

        while (curRootInIndex < right && inorder[curRootInIndex] != preorder[curRootPreIndex])
            curRootInIndex++;

        // create node
        TreeNode *node = new TreeNode(inorder[curRootInIndex]);

        node->left = buildTree(preorder, inorder,
                               curRootPreIndex + 1, left, curRootInIndex - 1);

        node->right = buildTree(preorder, inorder, curRootPreIndex + curRootInIndex +
                                                   1 - left, curRootInIndex + 1, right);


        return node;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        if (n == 0)
            return NULL;

        TreeNode *root = buildTree(preorder, inorder, 0, 0, n - 1);

        return root;
    }
};

int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution s;
    cout << s.buildTree(preorder, inorder) << endl;
    return 0;
}