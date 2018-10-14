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

// 思路错误
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;

        // left, right, 可以不是从根节点出发，就是每个点都可以是一次根节点
        
        int res = INT_MIN;

        // only root node 
        res = max(res, root->val);
        
        // left, right
        res = max(res, root->val + maxPathSum(root->left) + maxPathSum(root->right));
        
        // left
        res = max(res, root->val + maxPathSum(root->left));
        
        // right
        res = max(res, root->val + maxPathSum(root->right));
    
        if (root->left)
            res = max(res, maxPathSum(root->left));
        
        if (root->right)
            res = max(res, maxPathSum(root->right));
            

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
