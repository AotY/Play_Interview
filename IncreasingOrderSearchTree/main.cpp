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
    void inOrderTra(TreeNode *node, vector<int>& nums) {

        if (node == NULL)
            return;

        inOrderTra(node->left, nums);
        nums.push_back(node->val);
        inOrderTra(node->right, nums);
    }

    TreeNode *buildTree(vector<int>&nums){
        TreeNode *resRoot = new TreeNode(nums[0]);
        TreeNode *tmpRoot = resRoot;
        for (int i = 1; i < nums.size(); ++i) {
            TreeNode *node = new TreeNode(nums[i]);
            tmpRoot->right = node;
            tmpRoot = tmpRoot->right; // update tmpRoot
        }

        return resRoot;
    }
public:
    TreeNode *increasingBST(TreeNode *root) {

        if (root == NULL)
            return NULL;

        // 获取所有节点元素

        vector<int> nums;
        inOrderTra(root, nums);

        // 建立新树

        TreeNode *resRoot = buildTree(nums);


        return resRoot;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}