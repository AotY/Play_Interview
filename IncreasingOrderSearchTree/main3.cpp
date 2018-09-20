#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i, s, t) for(int i=(s); i<(t); i++)
#define FILL(x, v) memset(x,v,sizeof(x))

const int INF = (int) 1E9;
#define MAXN 100005

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
public:
    vector<int> v;

    void dfs(TreeNode *root) {
        if (!root)
            return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }

    void build(TreeNode *root) {
        if (v.empty())
            return;
        root->right = new TreeNode(v.back());
        v.pop_back();
        build(root->right);
    }

    TreeNode *increasingBST(TreeNode *root) {
        dfs(root);
        reverse(v.begin(), v.end());
        TreeNode *ret = new TreeNode(v.back());
        v.pop_back();
        build(ret);
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}