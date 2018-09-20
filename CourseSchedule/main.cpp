#include <iostream>
#include <vector>

using namespace std;


bool prerequisiteCompare(const pair<int, int> &prerequisite1, const pair<int, int> &prerequisite2) {
    if (prerequisite1.first != prerequisite1.first)
        return prerequisite1.first < prerequisite2.first;
    else
        return prerequisite1.second < prerequisite2.second;
}

class Solution {
private:
    int findParent(vector<int> &nums, int c) {
        while (c != nums[c]) {
            c = nums[c];
        }
        return c;
//        return nums[c];
    }

public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        int n = prerequisites.size();
        if (n == 0)
            return true;


        vector<int> nums = vector<int>(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            nums[i] = i;
        }


        sort(prerequisites.begin(), prerequisites.end(), prerequisiteCompare);
        // 只要存在相互依赖，或者是环，就不可能完成
        for (int i = 0; i < n; ++i) {
            int c1 = prerequisites[i].first;
            int c2 = prerequisites[i].second;


            int p1 = findParent(nums, c1);
            int p2 = findParent(nums, c2);


            if (c1 != p2) {
                nums[c1] = c2;
            } else {


                // 有可能相互依赖
                return false;
            }


        }

        return true;
    }
};


int main() {

//    vector<pair<int, int>> prerequisites = {
//            {1, 0},
//            {1, 2},
//            {0, 1}
//    };
//    int numCourses = 3;

    vector<pair<int, int>> prerequisites = {
            {0, 1},
            {0, 2},
            {1, 3},
            {3, 0}
    };
    int numCourses = 4;

    Solution s;
    cout << s.canFinish(numCourses, prerequisites) << endl;
    return 0;
}