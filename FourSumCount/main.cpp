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


using namespace std;

// memory search
class Solution {
    private:
        map<pair<int, int>, int> memo;

        int searchSum(vector<vector<int>> &matrix, int index, int curSum, int m, int n) {
            if (index >= m) {
                return (int) curSum == 0;
            }

            // search in memory 
            pair<int, int> key = make_pair(index, curSum);
            if (memo.find(key) != memo.end()){
                return memo[key]; 
            }
            
            int res = 0;
            for (int i = 0; i < n; i++) {
               res += searchSum(matrix, index + 1, curSum + matrix[index][i], m, n); 
            
            }

            // keep in memory
            memo.insert(make_pair(key, res));

            return res;

        }
    public:
        int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
            int n = A.size();

            if (n == 0)
                return 0;

            // n^4  ? timeout
            vector<vector<int>> matrix;
            matrix.push_back(A);
            matrix.push_back(B);
            matrix.push_back(C);
            matrix.push_back(D);

            int m = 4;

            int curSum = 0;
            int index = 0;

            int res = searchSum(matrix, index, curSum, m, n);
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
