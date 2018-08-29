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


// 求次数
class Solution {
private:

    int searchSum(TreeNode *node, int curSum) {

        if (node == NULL)
            return 0;

        int res = 0;

        // 可能后面会出现一负一整的情况，所以不能返回
        if (node->val == curSum) {
            res += 1;
        }

        res += searchSum(node->left, curSum - node->val);

        res += searchSum(node->right, curSum - node->val);


        return res;

    }


public:

    int pathSum(TreeNode *root, int sum) {

        if (root == NULL)
            return 0;

        // 路径和为 sum的所有可能路径
        int res = 0;

        // root
        res += searchSum(root, sum);

        // left，是递归调用 pathSum()
        res += pathSum(root->left, sum);

        // right，是递归调用 pathSum()
        res += pathSum(root->right, sum);

        return res;
    }

};


int main() {

    TreeNode *root = new TreeNode(1);

    TreeNode *node2 = new TreeNode(2);

    root->left = NULL;
    root->right = node2;

    TreeNode *node3 = new TreeNode(3);

    node2->left = NULL;
    node2->right = node3;

    TreeNode *node4 = new TreeNode(4);
    node3->left = NULL;
    node3->right = node4;


    TreeNode *node5 = new TreeNode(5);

    node4->left = NULL;
    node4->right = node5;


    node5->left = NULL;
    node5->right = NULL;


    Solution s;

    cout << s.pathSum(root, 3) << endl;
    return 0;
}