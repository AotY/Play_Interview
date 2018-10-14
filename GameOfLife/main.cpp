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



// save a copy of board, then update simultaneously.
class Solution {
    private:
        int m; // rows
        int n; // columns

        int moveArr[8][2] = {
            {-1, 0}, //
            {-1, 1}, //
            {0, 1},
            {1, 1},
            {1, 0},
            {1, -1},
            {0, -1},
            {-1, -1}
        };

        bool isInArea(int curI, int curJ) {
            return (curI >= 0 && curI < m) && (curJ >= 0 && curJ < n);
        }

        int getNeighborLives(vector<vector<int>> &copyOfBoard, int curI, int curJ) {
            int count = 0;
            for (int k = 0; k < 8; k++) {
                int newI = moveArr[k][0] + curI;
                int newJ = moveArr[k][1] + curJ;

                if (isInArea(newI, newJ) && copyOfBoard[newI][newJ] == 1)
                    count ++;

            }

            return count;

        }
    public:
        void gameOfLife(vector<vector<int>>& board) {
            m = board.size();
            if (m == 0)
                return ;

            n = board[0].size();

            vector<vector<int>> copyOfBoard = board;
            // update board
            for (int i = 0; i < m; i ++ ) {
                for (int j = 0; j < n; j++) {
                    int neighborCount = getNeighborLives(copyOfBoard, i, j );

                    if (board[i][j]) {
                        // alive
                        if (neighborCount < 2)
                            board[i][j] = 0;
                        else if (neighborCount == 2 || neighborCount == 3)
                            board[i][j] = 1;
                        else if (neighborCount > 3)
                            board[i][j] = 0;
                    }
                    else {
                        //died
                        if (neighborCount == 3)
                            board[i][j] = 1;
                    }

                }
            }
            return;
        }
};



int main() {


    vector<vector<int>> board = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };

    Solution s;

    s.gameOfLife(board);

    for (int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}
