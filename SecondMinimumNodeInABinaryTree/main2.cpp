#include <iostream>

using namespace std;


/**
  Definition for a binary tree node.
*/


static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
private:
    int searchSecondMinValue(TreeNode *node) {
        if (node == NULL)
            return INT_MAX;

        int res = INT_MAX;
        int curVal = node->val;

        if (node->left != NULL) { // ensure 0 or 2 sub nodes
            int leftVal = node->left->val;
            int rightVal = node->right->val;
            if (curVal == leftVal && curVal == rightVal) {

                res = min(searchSecondMinValue(node->left), searchSecondMinValue(node->right));

            } else {
                if (leftVal == curVal) {

                    res = min(searchSecondMinValue(node->left), rightVal);
                } else if (rightVal == curVal) {
                    res = min(searchSecondMinValue(node->right), leftVal);
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
        int res = searchSecondMinValue(root);
        return res == INT_MAX ? -1 : res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}