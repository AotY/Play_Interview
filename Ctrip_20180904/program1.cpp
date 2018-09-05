#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct OrderInfo {
    int no;
    int inDate;
    int outDate;
};

struct TreeNode {
    TreeNode *left;
    TreeNode *right;

    OrderInfo orderInfo;

};

bool orderCompare(const OrderInfo& o1, const OrderInfo &o2) {
    if (o1.inDate != o2.inDate)
        return o1.inDate < o2.inDate;

    if (o1.outDate != o2.outDate)
        return o1.outDate < o2.outDate;

    return o1.no < o2.no;
}

TreeNode * buildTree(vector<OrderInfo> &orders, int left, int right) {
    if (left < 0 || right >= orders.size() || left > right)
        return NULL;

    int mid = (left + right) >> 1;

    TreeNode *node = new TreeNode();
    node->orderInfo = orders[mid];
    node->left = buildTree(orders, left, mid - 1);
    node->right = buildTree(orders, mid + 1, right);

    return node;
}

TreeNode *searchNode(TreeNode *node, int A){
    if (node == NULL)
        return NULL;

    // 当前节点
    if (node->orderInfo.inDate <= A && node->orderInfo.outDate >= A)
        return node;

    // 左孩子
    if (node->orderInfo.inDate > A) {
        return searchNode(node->left, A);
    } else if (node->orderInfo.outDate < A) {
        return searchNode(node->right, A);
    }

    return NULL;
}

void getAllOrders(TreeNode *node, vector<int> &results, bool isRight) {

    if (node == NULL)
        return;

    results.push_back(node->orderInfo.no);

    getAllOrders(node->left, results, true);

//    if (isRight) {
//        getAllOrders(node->right, results, isRight);
//    }
}

// 订单时间查询
int main() {

    int n ;
    cin >> n;

    int A;
    cin >> A;


    vector<OrderInfo> orders = vector<OrderInfo>(n);
    for (int i = 0; i < n; ++i) {
        OrderInfo orderInfo = OrderInfo();
        cin >> orderInfo.no >> orderInfo.inDate >> orderInfo.outDate;

        orders[i] = orderInfo;
    }


    sort(orders.begin(), orders.end(), orderCompare);


    // 建立查找二叉树
    TreeNode *root = buildTree(orders, 0, orders.size() - 1);


    // 检索
    TreeNode *findNode = searchNode(root, A);

    if (findNode == NULL)
        return 0;

    // 获取所有孩子节点中的订单编号
    vector<int> results;

    getAllOrders(findNode, results, false);

    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }

    return 0;
}