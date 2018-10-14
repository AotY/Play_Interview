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
        vector<vector<int>> memo;

        int searchSum(vector<vector<int>> &matrix, int index, int curSum, int m, int n, int minSum) {
            if (index >= m) {
                return (int) curSum == 0;
            }

            // search in memory
            int tmp = curSum - minSum;
            if (memo[index][tmp] != -1){
                return memo[index][tmp];
            }

            int res = 0;
            for (int i = 0; i < n; i++) {
                res += searchSum(matrix, index + 1, curSum + matrix[index][i], m, n, minSum);

            }

            // keep in memory
            memo[index][tmp] = res;

            return res;

        }

        int maxNum(vector<int> &nums) {
            int maxNum = nums[0];
            for (int i = 1; i < nums.size(); i++)
                maxNum = max(maxNum, nums[i]);
            return maxNum;
        }
        
        int minNum(vector<int> &nums) {
            int minNum = nums[0];
            for (int i = 1; i < nums.size(); i++)
                minNum = min(minNum, nums[i]);

            return minNum;
        }


    public:
        int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
            int n = A.size();

            if (n == 0)
                return 0;

            // n^4  ? timeout
            vector<vector<int>> matrix;
            matrix.push_back(B);
            matrix.push_back(C);
            matrix.push_back(D);
            
            int maxSum = 0;
            int minSum = 0;

            maxSum = maxNum(A) + maxNum(B) + maxNum(C) + maxNum(D);

            minSum = minNum(A) + minNum(B) + minNum(C) + minNum(D);

            if (minSum > 0)
                minSum = 0;

            int m = 3;

            memo = vector<vector<int>>(m, vector<int>(maxSum - minSum, -1));

            int res = 0;
            for (int i = 0; i < n; i++) {

                res += searchSum(matrix, 0, A[i], m, n, minSum);
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
