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

// A, B, C, D -> AB, CD, then bianry search
class Solution {
    private:

        int binarySerach(vector<int> &nums, int left, int right, int target) {

            while (left <= right) {

                int mid = left + (right - 1) / 2;

                if (nums[mid] == target)
                    return mid;
                else if (nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            return -1;
        }

        vector<int> getSums(vector<int> &v1, vector<int> &v2) {
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
            sort(A.begin(), A.end());
            sort(B.begin(), B.end());
            sort(C.begin(), C.end());
            sort(D.begin(), D.end());

            vector<int> sumAB = getSums(A, B);
            vector<int> sumCD = getSums(C, D);


            int res = 0;
            for (int i = 0; i < sumAB.size(); i++) {
                int curNum = sumAB[i];

                int index = binarySerach(sumCD, 0, n-1, 0 - curNum);

                if (index != -1)
                    res += 1;
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
