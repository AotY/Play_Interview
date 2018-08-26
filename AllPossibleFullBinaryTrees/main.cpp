#include <iostream>
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

// 递归思想
class Solution {
public:
    vector<TreeNode *> allPossibleFBT(int N) {

        vector<TreeNode *> results;

        if (N % 2 == 0)
            return results;

        if (N == 1) {
            TreeNode *root = new TreeNode(0);
            results.push_back(root);
            return results;
        }


        // 尝试让每一个点都当root节点
        for (int i = 1; i <= N - 1; ++i) {

            int leftEnd = i;
            int rightEnd = N - i - 1;

            vector<TreeNode *> leftChildren = allPossibleFBT(i);
            vector<TreeNode *> rightChildren = allPossibleFBT(rightEnd);

            for (auto lc: leftChildren) {
                for (auto rc: rightChildren) {
                    TreeNode *root = new TreeNode(0);
                    root->left = lc;
                    root->right = rc;

                    results.push_back(root);
                }
            }
        }
        return results;
    }
};

int main() {
    Solution s;
    s.allPossibleFBT(7);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}