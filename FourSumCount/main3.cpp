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
// 剪掉搜索下去不可能变为0的分支
class Solution {
    private:
        vector<vector<int>> memo;

        int searchSum(vector<vector<int>> &matrix, vector<int> &maxNums, vector<int> &minNums, int index, int curSum, int m, int n, int minSum) {
            if (index >= m) {
                return (int) curSum == 0;
            }

            // search in memory
            int tmpIndex = curSum - minSum;

            if (memo[index][tmpIndex] != -1){
                return memo[index][tmpIndex];
            }
            
            // check searching is necessary
            int tmpSum1 = curSum + maxNums[index];
            int tmpSum2 = curSum + minNums[index];
            if ((tmpSum1 > 0 && tmpSum2 > 0) || (tmpSum1 < 0 && tmpSum2 < 0)) {
                memo[index][tmpIndex] = 0;
                return 0;
            }

            int res = 0;
            for (int i = 0; i < n; i++) {
                res += searchSum(matrix, maxNums, minNums, index + 1, curSum + matrix[index][i], m, n, minSum);

            }

            // keep in memory
            memo[index][tmpIndex] = res;

            return res;

        }

        int getMaxNum(vector<int> &nums) {
            int maxNum = nums[0];
            for (int i = 1; i < nums.size(); i++)
                maxNum = max(maxNum, nums[i]);
            return maxNum;
        }

        int getMinNum(vector<int> &nums) {
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
            matrix.push_back(A);
            matrix.push_back(B);
            matrix.push_back(C);
            matrix.push_back(D);

            int maxSum = 0;
            int minSum = 0;
            int m = 4;

            vector<int> maxNums = vector<int>(m);
            vector<int> minNums = vector<int>(m);

            for (int i = m - 1; i >= 0; --i) {
                int maxNum = getMaxNum(matrix[i]);
                int minNum = getMinNum(matrix[i]);

                maxSum += maxNum;
                minSum += minNum;

                maxNums[i] = i == (m - 1) ? maxNum : maxNum + maxNums[i + 1];
                minNums[i] = i == (m - 1) ? minNum : minNum + minNums[i + 1];
            }

            if (minSum > 0)
                minSum = 0;

            memo = vector<vector<int>>(m, vector<int>(maxSum - minSum, -1));

            int res = 0;
            for (int i = 0; i < n; i++) {

                res += searchSum(matrix, maxNums, minNums, 1, matrix[0][i], m, n, minSum);
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
