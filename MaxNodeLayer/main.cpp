#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Node {
    vector<Node*> sons;
};


void dfsFind(Node *node, int dep, int counter[]) {
    // 递归终止条件
    if (node == NULL)
        return;

    counter[dep]++;

    for(int i = 0; i < node->sons.size(); i++) {
        //  dep + 1，指针访问元素
        dfsFind(node->sons[i], dep + 1, counter);
    }
}



int find(Node *root, int maxDep) {

    int depCounter[100000];

    dfsFind(root, 0, depCounter);

    // 初始化
    int maxNodes = INT_MIN;

    maxDep = INT_MAX;

    for (int i = 1; i <= maxDep; i++) {

        if (depCounter[i] >= maxNodes) {
            maxNodes = depCounter[i];
            // 记录最浅的一层
            if (i < maxDep)
                maxDep = i;
        }

    }
    return maxDep;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}