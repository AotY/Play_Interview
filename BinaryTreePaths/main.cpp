#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    vector<string> results;


    void searchPath(TreeNode *node, string path) {

        // 叶子节点
        if (node->right == NULL && node->left == NULL) {
           results.push_back(path.substr(0, path.size()-2));
            return;
        } else {

            // 左孩子
            if (node->left != NULL) {
                string appendPath = to_string(node->left->val) + "->";
                path += appendPath;
                searchPath(node->left, path);
                path = path.substr(0, path.size() - appendPath.size());
            }

            // 右孩子

            if (node->right != NULL) {
                string appendPath = to_string(node->right->val) + "->";
                path += appendPath;
                searchPath(node->right, path);
                path = path.substr(0, path.size() - appendPath.size());
            }
        }


    }


public:

    vector<string> binaryTreePaths(TreeNode* root) {

        if (root == NULL)
            return results;

        string path;
        path = to_string(root->val) + "->";
        searchPath(root, path);

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

    s.binaryTreePaths(root);
    return 0;
}