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

// A, B, C, D -> AB, CD, then bianry search
class Solution {
    private:

        unordered_map<int, int> getSumsMap(vector<int> &v1, vector<int> &v2) {
            unordered_map<int, int> sums;

            for (int i = 0; i < v1.size(); i++ ){
                for (int j = 0; j < v2.size(); j ++) {
                    int sum = v1[i] + v2[j];
                    sums[sum] += 1;
                }
            }
            return sums;
        }
        
        vector<int> getSumsVector(vector<int> &v1, vector<int> &v2) {
            vector<int> sums;

            for (int i = 0; i < v1.size(); i++ ){
                for (int j = 0; j < v2.size(); j ++) {
                    sums.push_back(v1[i] + v2[j]);
                }
            }
            return sums;
        }

    public:
        int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
            int n = A.size();

            if (n == 0)
                return 0;

            // sort

            vector<int> sumAB = getSumsVector(A, B);
            unordered_map<int, int> sumCD = getSumsMap(C, D);


            int res = 0;
            for (int i = 0; i < sumAB.size(); i++) {
                int curNum = sumAB[i];

                if (sumCD.find(0 - curNum) != sumCD.end()) {
                    res += sumCD[0 - curNum];
                }
            }

            return res;
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
