#include <iostream>
#include <vector>
#include <stack>

using namespace std;

static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

//  还是得用搜索 [Facepalm]

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int roomNum = rooms.size();
        if (roomNum == 0) {
            return false;
        }
        bool res = true;

//        bool visited[20001] = {false};
        bool mark[20001] = {false};
        mark[0] = true;

        stack<int> searchStack;
        searchStack.push(0);

        while (!searchStack.empty()) {
            int roomIndex = searchStack.top();
            searchStack.pop();

            for (int j = 0; j < rooms[roomIndex].size(); ++j) {
                if (!mark[rooms[roomIndex][j]]) { // 标记，不然会memory limited
                    searchStack.push(rooms[roomIndex][j]);
                    mark[rooms[roomIndex][j]] = true;
                }
            }

        }

        for (int i = 0; i < roomNum; ++i) {
            if (!mark[i]) {
                res = false;
                break;
            }
        }

        return res;
    }
};

int main() {

    vector<vector<int>> rooms = {
            {6, 7, 8},
            {5, 4, 9},
            {},
            {8},
            {4},
            {},
            {1, 9, 2, 3},
            {7},
            {6, 5},
            {2, 3, 1}
    };
    Solution s;
    cout << s.canVisitAllRooms(rooms) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}