/*
 * main.cpp
 * Copyright (C) 2018 LeonTao <LeonTao@Leons-MacBook-Pro.local>
 *
 * Distributed under terms of the MIT license.
 */

/* #include "main.h" */
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>


using namespace std;


class Solution {
    public:
        int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

            int iCount = 0;
            unordered_map<int, int> sumAB(2 * A.size() * B.size());
            for (int val1 : A)
                for (int val2 : B)
                    sumAB[val1 + val2]++;

            for (int val3 : C)
            {
                for (int val4 : D)
                {
                    unordered_map<int, int>::iterator it;
                    if ( (it = sumAB.find( -val3 - val4)) != sumAB.end() )
                        iCount += sumAB[-val3 - val4];
                }
            }
            return iCount;
        }
};

int main() {



    Solution s;

    vector<int> A =   {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};

    int res = s.fourSumCount(A, B, C, D);

    cout << res << endl;
    return 0;
}
