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

// 递归
class Solution {
    private:
        void traverseMatrix(vector<vector<int>> &matrix, int left, int right, int low, int high, vector<int> &res){
            if (left > right || low > high)
                return;
            
            if (left == right) {
                for (int i = low; i <= high; i++)
                    res.push_back(matrix[i][left]);
                return ;
            }

            if (low == high) {
                for (int j = left; j <= right; j++)
                    res.push_back(matrix[low][j]);

                return;
            }

            // left -> right
            for (int j = left; j < right; j++)
                res.push_back(matrix[low][j]);

            // low -> high
            for (int i = low; i < high; i++)
                res.push_back(matrix[i][right]);

            // high, right -> high, left
            for (int j = right; j > left; j--)
                res.push_back(matrix[high][j]);

            // left, high -> left, low
            for (int i = high; i >= low + 1; i--)
                res.push_back(matrix[i][left]);

            traverseMatrix(matrix, left + 1, right - 1, low + 1, high - 1, res);

            return;
        }
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {

            vector<int> res;
            res.clear();

            int m = matrix.size();
            if (m == 0)
                return res;

            if (m == 1)
                return matrix[0];

            int n = matrix[0].size();

            // 递归遍历Matrix, left, right, low, high
            int left = 0;
            int right = n - 1;
            int low = 0;
            int high = m - 1;
            traverseMatrix(matrix, left, right, low, high, res);

            return res;

        }
};




int main() {

    Solution s;
    vector<vector<int>> matrix = {
        {1, 2},
        {3, 4},
    };
    vector<int> res = s.spiralOrder(matrix);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << ", ";

    }

    cout << endl;


    return 0;
}
