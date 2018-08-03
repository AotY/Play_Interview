#include <iostream>

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
    int searchSecondMinValue(TreeNode *node) {
        if (node == NULL)
            return -1;

        int res = -1;
        int curVal = node->val;

        if (node->left != NULL) { // ensure 0 or 2 sub nodes
            int leftVal = node->left->val;
            int rightVal = node->right->val;
            if (curVal == leftVal && curVal == rightVal) {

                int tmpRes1 = searchSecondMinValue(node->left);

                int tmpRes2 = searchSecondMinValue(node->right);

                if (tmpRes1 != -1 && tmpRes2 != -1)
                    return min(tmpRes1, tmpRes2);

                if (tmpRes1 == -1)
                    return tmpRes2;

                if (tmpRes2 == -1)
                    return tmpRes1;


            } else {
                if (leftVal == curVal) {
                    int tmpRes = searchSecondMinValue(node->left);
                    if (tmpRes != -1)
                        return min(rightVal, tmpRes);
                    else
                        return rightVal;
                } else if (rightVal == curVal) {
                    int tmpRes = searchSecondMinValue(node->right);
                    if (tmpRes != -1)
                        return min(leftVal, tmpRes);
                    else
                        return leftVal;
                } else
                    return min(leftVal, rightVal);
            }
        }

        return res;

    }

public:
    int findSecondMinimumValue(TreeNode *root) {
        if (!root)
            return -1;

        return searchSecondMinValue(root);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}