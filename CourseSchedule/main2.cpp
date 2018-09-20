#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


// This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
class Solution {
private:

    vector<bool> visited;
    vector<bool> recursionStack;

    //
    bool searchCycle( unordered_map<int, vector<int>> &edgesMap, int curCourse) {

        if (!visited[curCourse]) {

            // set mark
            visited[curCourse] = true;
            recursionStack[curCourse] = true;


            // 尝试访问其连接（先修）的节点（课程）
            for (int i = 0; i < edgesMap[curCourse].size(); ++i) {
                if (!visited[edgesMap[curCourse][i]]) {
                    if (searchCycle(edgesMap, edgesMap[curCourse][i]))
                        return true;
                } else {
                    //
                    if (recursionStack[edgesMap[curCourse][i]])
                        return true;
                }
            }

        }

        // remove mark
        visited[curCourse] = false;
        recursionStack[curCourse] = false;

        return false;

    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        int n = prerequisites.size();
        if (n == 0)
            return true;



        visited = vector<bool>(numCourses, false);
        recursionStack = vector<bool>(numCourses, false);


        unordered_map<int, vector<int>> edgesMap;

        // 只要存在相互依赖，或者是环，就不可能完成
        for (int i = 0; i < n; ++i) {
            int c1 = prerequisites[i].first; // course
            int c2 = prerequisites[i].second; // pre course

            if (edgesMap.find(c1) == edgesMap.end()) {
                vector<int> preCourses;
                preCourses.push_back(c2);
                edgesMap.insert(make_pair(c1, preCourses));
            } else {
                edgesMap[c1].push_back(c2);
            }

        }

        // 搜索从每一个节点（课程）从发，是否有cycle

        for (int i = 0; i < numCourses; ++i) {
            if (edgesMap[i].size() > 0 )
                if (searchCycle(edgesMap, i) ) { // 如果有环
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