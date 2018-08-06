#include <iostream>
#include <vector>

using namespace std;

static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

//  忘记条件，可能向前或者向后开门

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        int roomNum = rooms.size();
        if (roomNum == 0) {
            return false;
        }
        bool res = true;

        bool mark[20001] = {false};
        mark[0] = true;

        // 向前
        for (int i = 0; i < roomNum; ++i) {
            if (mark[i]) {
                for (int j = 0; j < rooms[i].size(); ++j) {
                    mark[rooms[i][j]] = true;
                }
            }
        }

        // 不论顺序
        for (int i = roomNum - 1; i >= 0; i--) {
            if (mark[i]) {
                for (int j = 0; j < rooms[i].size(); ++j) {
                    if (!mark[rooms[i][j]])
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