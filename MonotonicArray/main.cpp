#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isMonotonic(vector<int> &A) {

        bool mark1 = true;
        bool mark2 = true;
        for (int i = 1; i < A.size(); ++i) {

            // 递增
            if (A[i] < A[i - 1]) {
                mark1 = false;
            }

            // 递减
            if (A[i] > A[i - 1]) {
                mark2 = false;
            }

        }

        return mark1 || mark2;


    }
};

int main() {

    Solution s;
    vector<int> A = {1, 3, 2};
    cout << s.isMonotonic(A) << endl;
    return 0;
}