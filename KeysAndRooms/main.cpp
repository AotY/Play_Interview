#include <iostream>
#include <vector>

using namespace std;

static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int roomNum = rooms.size();
        if (roomNum == 0) {
            return false;
        }
        bool res = true;

        bool *mark = new bool[roomNum];
        mark[0] = true;
        for (int i = 1; i < roomNum; ++i) {
            mark[i] = false;
        }

        for (int i = 0; i < roomNum; ++i) {
            if (mark[i]) {
                for (int j = 0; j < rooms[i].size(); ++j) {
                    mark[rooms[i][j]] = true;
                }
            }
        }

        for (int i = 0; i < roomNum; ++i) {
            if (!mark[i]) {
                res = false;
                break;
            }
        }

        delete[] mark;
        return res;
    }
};

int main() {

    vector<vector<int>> rooms = {
            {1, 3},
            {3, 0, 1},
            {2},
            {0}
    };
    Solution s;
    cout << s.canVisitAllRooms(rooms) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}