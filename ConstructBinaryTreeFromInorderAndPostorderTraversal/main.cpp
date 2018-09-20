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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
private:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int curRootPostIndex,
                        int left, int right) {

        if (left > right)
            return NULL;

        int curRootInIndex = left;

        while (curRootInIndex < right && inorder[curRootInIndex] != postorder[curRootPostIndex])
            curRootInIndex++;

        // create node
        TreeNode *node = new TreeNode(inorder[curRootInIndex]);
        // root-1-(end-i)
        node->left = buildTree(inorder, postorder,
                               curRootPostIndex - 1 - right + curRootInIndex, left, curRootInIndex - 1);

        node->right = buildTree(inorder, postorder , curRootPostIndex - 1, curRootInIndex + 1, right);


        return node;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        if (n == 0)
            return NULL;

        TreeNode *root = buildTree(inorder, postorder, n - 1, 0, n - 1);

        return root;
    }
};
int main() {

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    Solution s;
    cout << s.buildTree(inorder, postorder) << endl;
    return 0;
}