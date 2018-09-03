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

class Solution {

private:

    // [left, right] 中构建maximumBinaryTree
    TreeNode *tryConstructing(vector<int> &nums, int left, int right) {


        if (left < 0 || right >= nums.size() || left > right)
            return NULL;

        int maxNum = nums[left];
        int maxIndex = left;
        for (int i = left + 1; i <= right; ++i) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                maxIndex = i;
            }
        }

        // 找到当前[left, right]区间中的最大值，然后划分
        TreeNode *node = new TreeNode(maxNum);

        // 左孩子
        node->left = tryConstructing(nums, left, maxIndex - 1);

        // 右孩子
        node->right = tryConstructing(nums, maxIndex + 1, right);

        return node;

    }


public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {


        TreeNode *root = tryConstructing(nums, 0, nums.size() - 1);

        return root;
    }
};


int main() {

    Solution s;

    vector<int> nums = {3, 2, 1, 6, 0, 5};
    cout << s.constructMaximumBinaryTree(nums) << endl;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}