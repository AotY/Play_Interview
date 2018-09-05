#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;


// 添加size 和 path compression  优化
class Solution {
private:


    vector<int> sizes;

    vector<int> nums;

    //
    int findFriend(int f) {

        if (nums[f] != f) {
            nums[f] = findFriend(nums[f]);
        }
        return nums[f];
    }


    void unionFriends(int f1, int f2) {

        int parent1 = findFriend(f1);

        int parent2 = findFriend(f2);

        if (parent1 != parent2) {

            if (sizes[parent1] < sizes[parent2]) {
                nums[parent1] = parent2;
                sizes[parent2] += sizes[parent1];
            } else {
                // sizes[parent1] >= sizes[parent2]

                nums[parent2] = parent1;
                sizes[parent1] += sizes[parent2];
            }
        }
    }


public:
    int findCircleNum(vector<vector<int>> &M) {

        int n = M.size();

        if (n == 1)
            return 1;


        sizes = vector<int>(n, 1);

        // init uion find
        nums = vector<int>(n);

        for (int i = 0; i < n; ++i) {
            nums[i] = i;
        }

        // M[i][j]
        // 1. i == j
        // 2. i != j -> j belongs to i
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && M[i][j] == 1) {
                    unionFriends(i, j);
                }
            }
        }


        unordered_set<int> resSet;
        for (int i = 0; i < n; ++i) {
            resSet.insert(findFriend(nums[i]));
        }

        return (int) resSet.size();
    }
};

int main() {

    Solution s;

//    vector<vector<int>> M = {
//            {1, 0, 0, 1},
//            {0, 1, 1, 0},
//            {0, 1, 1, 1},
//            {1, 0, 1, 1}
//    };

    vector<vector<int>> M = {{1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                             {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
                             {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                             {0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
                             {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
                             {0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1},
                             {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                             {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}
    };

    cout << s.findCircleNum(M) << endl;

    return 0;
}
