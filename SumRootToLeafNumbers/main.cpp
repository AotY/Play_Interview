#include <iostream>


class Solution {

private:
    vector<vector<int>> nums;

    void search2Leaf(TreeNode *node, vector<int> &curNums) {
        if (node == NULL) {
            return;
        }

        curNums.push_back(node->val);

        if (node->left == NULL && node->right == NULL) {
            nums.push_back(curNums);
            curNums.pop_back();
            return;
        }

        // 搜索左孩子

        search2Leaf(node->left, curNums);

        // 搜索右孩子
        search2Leaf(node->right, curNums);


        curNums.pop_back();

        return;

    }

public:
    int sumNumbers(TreeNode *root) {

        int res = 0;

        vector<int> curNums;
        search2Leaf(root, curNums);


        for (int i = 0; i < nums.size(); ++i) {
            int powNum = 0;
            int curNum = 0;
            for (int j = nums[i].size() - 1; j >= 0; --j) {
                curNum += (int) nums[i][j] * pow(10, powNum);
                powNum++;
            }

            res += curNum;
        }


        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}