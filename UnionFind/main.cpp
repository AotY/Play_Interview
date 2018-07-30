#include <iostream>
#include <vector>
#include "union_find.h"


void initDatas(std::vector<std::vector<int>> &datas);

/**
 * Union Find
 *
 */



int main() {

    int individual = 10;
    UnionFind unionFind(individual);

    std::vector<std::vector<int>> datas(10, std::vector<int>());

    initDatas(datas);

    for (int i = 1; i < datas.size(); ++i) {
        unionFind.merge(datas[i][0], datas[i][1]);
    }

    int unionCount = unionFind.getUnionCount();

    std::cout << "unionCount: " << unionCount << std::endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void initDatas(std::vector<std::vector<int>> &datas) {
    datas[1].push_back(1);
    datas[1].push_back(2);

    datas[2].push_back(3);
    datas[2].push_back(4);

    datas[3].push_back(5);
    datas[3].push_back(2);

    datas[4].push_back(4);
    datas[4].push_back(6);

    datas[5].push_back(2);
    datas[5].push_back(6);

    datas[6].push_back(8);
    datas[6].push_back(7);

    datas[7].push_back(9);
    datas[7].push_back(7);

    datas[8].push_back(1);
    datas[8].push_back(6);

    datas[9].push_back(2);
    datas[9].push_back(4);

}