#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    vector<vector<int>> results;


    void searchSum(TreeNode *node, int curSum, vector<int> &paths) {

        // 叶子节点
        if (node->right == NULL && node->left == NULL) {
            if (curSum == 0)
                results.push_back(paths);
            return;
        } else {

            // 左孩子
            if (node->left != NULL) {
                paths.push_back(node->left->val);
                searchSum(node->left, curSum - node->left->val, paths);
                paths.pop_back();
            }

            // 右孩子

            if (node->right != NULL) {
                paths.push_back(node->right->val);
                searchSum(node->right, curSum - node->right->val, paths);
                paths.pop_back();
            }
        }


    }


public:

    vector<vector<int>> pathSum(TreeNode *root, int sum) {

        // 如果没有找到

        if (root == NULL)
            return results;


        vector<int> paths;
        paths.push_back(root->val);
        searchSum(root, sum - root->val, paths);

        return results;
    }

};


int main() {

    TreeNode *root = new TreeNode(3);

    TreeNode *node1 = new TreeNode(1);

    TreeNode *node2 = new TreeNode(1);
    root->left = node1;
    root->right = node2;

    node1->left = NULL;
    node1->right = NULL;

    node2->left = NULL;
    node2->right = NULL;


    Solution s;

    s.pathSum(root, 4);
    return 0;
}