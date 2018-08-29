#include <iostream>
#include <queue>
#include <stack>
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

//  不是搜索树，怎么判断祖先 ？

class Solution {
private:
    bool searchNode(TreeNode *node, TreeNode *targetNode, vector<TreeNode *> &paths) {

        if (node == targetNode) {
            return true;
        }

        // 左孩子
        if (node->left != NULL) {
            paths.push_back(node->left);
            if (searchNode(node->left, targetNode, paths))
                return true;

            paths.pop_back();
        }

        // 右孩子
        if (node->right != NULL) {
            paths.push_back(node->right);
            if (searchNode(node->right, targetNode, paths))
                return true;

            paths.pop_back();
        }

        return false;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {


        if (root == NULL)
            return NULL;


        //  从根节点出发找到p, q节点，将路径保存在队列中，最后一次公共节点就是最近公共祖先

        vector<TreeNode *> paths1;
        paths1.push_back(root);
        searchNode(root, p, paths1);


        vector<TreeNode *> paths2;
        paths2.push_back(root);
        searchNode(root, q, paths2);


        // 找到最后一个相同的节点
        TreeNode *res = root;
        int index = 0;
        while (index < paths1.size() && index < paths2.size()) {
            if (paths1[index] == paths2[index]) {
                res = paths1[index++];
            } else {
                break;
            }
        }

        return res;
    }
};


// [3,5,1,6,2,0,8,null,null,7,4]
int main() {

    TreeNode *root = new TreeNode(3);

    TreeNode *node1 = new TreeNode(5);

    TreeNode *node2 = new TreeNode(1);
    root->left = node1;
    root->right = node2;

    TreeNode *node3 = new TreeNode(6);
    node3->left = NULL;
    node3->right =NULL;

    TreeNode *node4 = new TreeNode(2);

    node1->left = node3;
    node1->right = node4;


    TreeNode *node5 = new TreeNode(7);
    node5->left = NULL;
    node5->right =NULL;

    TreeNode *node6 = new TreeNode(4);
    node6->left = NULL;
    node6->right =NULL;


    node4->left = node5;
    node4->right = node6;


    TreeNode *node7 = new TreeNode(0);
    node7->left = NULL;
    node7->right =NULL;

    TreeNode *node8 = new TreeNode(8);
    node8->left = NULL;
    node8->right =NULL;

    node2->left = node7;
    node2->right = node8;


    Solution s;

    cout << s.lowestCommonAncestor(root, node4, node6)->val << endl;
    return 0;
}