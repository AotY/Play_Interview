//
// Created by Leon Tao on 10/07/2018.
//

#ifndef UNIONFIND_UNION_FIND_H
#define UNIONFIND_UNION_FIND_H

#endif //UNIONFIND_UNION_FIND_H

#include <cassert>


class UnionFind {

private:
    int *unionTable;
    const int MAX_SIZE = 1000;
    int count = 0;

public:

    UnionFind(int individual) {
        unionTable = (int *) malloc(individual * sizeof(int));

        for (int i = 1; i <= individual; ++i) {
            unionTable[i] = i;
        }
        count = individual;

    }

    void merge(int u1, int u2) {
        int root1 = find(u1);
        int root2 = find(u2);

        //
        if (root1 == root2) {
            return;
        } else {
            // 左 原则
            unionTable[root2] = root1;
        }

    }

    //
    int find(int u) {

        if (unionTable[u] != u) {
            unionTable[u] = find(unionTable[u]); // 路径压缩
            return unionTable[u];
        } else {
            return u;
        }
    }


    int getUnionCount() {
        int unionCount = 0;
        for (int i = 1; i <= count; ++i) {
            if (unionTable[i] == i)
                unionCount++;
        }
        return unionCount;
    }

};