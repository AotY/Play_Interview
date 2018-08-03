#include <iostream>
#include <vector>
#include <cassert>
#include <stack>


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

static int xx = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {

public:
    int find_k(TreeNode *root, int &k) {
        if (!root)
            return -1;

        int val = find_k(root->left, k);

        if (k == 0)
            return val;

        if (--k == 0)
            return root->val;

        return find_k(root->right, k);
    }

    int kthSmallest(TreeNode *root, int k) {
        return find_k(root, k);
    }
};

int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}