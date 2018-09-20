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
    vector<TreeNode *> order;

    void dfs(TreeNode *x) {
        if (x == NULL) return;
        dfs(x->left);
        order.push_back(x);
        dfs(x->right);
    }

    TreeNode *increasingBST(TreeNode *root) {
        if (root == NULL) return NULL;
        order.clear();
        dfs(root);
        int n = order.size();
        REP(i, 1, n) {
            order[i - 1]->left = NULL;
            order[i - 1]->right = order[i];
        }
        order[n - 1]->left = order[n - 1]->right = NULL;
        return order[0];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}