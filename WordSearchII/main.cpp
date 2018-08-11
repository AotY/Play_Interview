#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
private:
    vector<string> res;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        if (n == 0)
            return res;
        int m = board[0].size();

        for (int i = 0; i < words.size(); ++i) {
            
        }


        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}