/*
 * main.cpp
 * Copyright (C) 2018 LeonTao <LeonTao@Leons-MacBook-Pro.local>
 *
 * Distributed under terms of the MIT license.
 */

/* #include "main.h" */
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>


using namespace std;


/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    private:
        int res = INT_MIN;

        int searchMaxSum(TreeNode *node) {
            if (node == NULL)
                return 0;

            int leftMax = max(0, searchMaxSum(node->left));
            int rightMax = max(0, searchMaxSum(node->right));

            int sum = leftMax + rightMax + node->val;

            res = max(sum, res);

            return max(leftMax, rightMax) + node->val;

        }

    public:
        int maxPathSum(TreeNode* root) {
            if (root == NULL)
                return 0;

            searchMaxSum(root);

            return res;
        }
};



int main() {
    Solution s;

    TreeNode *root = new TreeNode(1);
    TreeNode *left = new TreeNode(-2);
    TreeNode *right = new TreeNode(-3);

    root->left = left;
    root->right = right;


    TreeNode *left2 = new TreeNode(1);
    TreeNode *right2 = new TreeNode(3);

    left->left = left2;
    left->right = right2;

    right2->left = NULL;
    right2->right = NULL;

    TreeNode *left3 = new TreeNode(-1);
    left2->left = left3;
    left2->right = NULL;

    TreeNode *left4 = new TreeNode(-2);
    left4->left = NULL;
    left4->right = NULL;

    right->left = left4;
    right->right = NULL;


    int res = s.maxPathSum(root);
    cout << res << endl;

    return 0;
}
