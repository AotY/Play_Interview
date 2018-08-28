#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/**
  Definition for binary tree
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 二分搜索树的迭代器


class BSTIterator {
private:
    stack<TreeNode *> nodes;

public:
    BSTIterator(TreeNode *root) {

        // 遍历到最后一个左孩子，加入栈中
        if (root) {
            nodes.push(root);
            while (root->left) {
                nodes.push(root->left);
                root = root->left;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {

        return !nodes.empty();
    }

    /** @return the next smallest number */
    int next() {

        int res;

        //  将栈顶元素移动到一下需要访问的位置
        TreeNode *curTop = nodes.top();
        res = curTop->val;
        nodes.pop();

        if (curTop->right) {

            curTop = curTop->right;
            nodes.push(curTop); // 第一个右节点

            while (curTop->left) {
                nodes.push(curTop->left);
                curTop = curTop->left;
            }
        }
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}