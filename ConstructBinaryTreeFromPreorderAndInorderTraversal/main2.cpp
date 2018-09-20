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
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size = inorder.size();
        TreeNode *result = buildTree1(inorder, postorder, size - 1, 0, size - 1);
        return result;

    }

    TreeNode *buildTree1(vector<int> &inorder, vector<int> &postorder, int a, int a1, int b1) {

        if (a < 0 || b1 < a1 || a1 >= inorder.size() || b1 < 0)
            return NULL;

        TreeNode *result = new TreeNode(postorder[a]);
        int i = 0;
        for (i = b1; i >= a1; i--) {
            if (inorder[i] == postorder[a])
                break;
        }

        result->right = buildTree1(inorder, postorder, a - 1, i + 1, b1);
        result->left = buildTree1(inorder, postorder, a - b1 + i - 1, a1, i - 1);
        return result;
    }
};

int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution s;
    cout << s.buildTree(preorder, inorder) << endl;
    return 0;
}