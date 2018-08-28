#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {

        int len1 = word1.size();
        int len2 = word2.size();

        if (len1 == 0 || len2 == 0)
            return max(len1, len2);

        // 尝试使用三类操作 1. 插入; 2. 删除; 3. 替换

        // We define the state memo[i][j] to be the minimum number of operations to
        // convert word1[0..i - 1] to word2[0..j - 1]
        vector<vector<int>> memo = vector<vector<int>>(len1 + 1, vector<int>(len2 + 1));

        for (int i = 1; i <= len1; i++)
            memo[i][0] = i;

        for (int j = 1; j <= len2; j++)
            memo[0][j] = j;

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (word1[i - 1] == word2[j - 1])
                    memo[i][j] = memo[i - 1][j - 1];
                else
                    memo[i][j] = min(memo[i - 1][j - 1] + 1, min(memo[i][j - 1] + 1, memo[i - 1][j] + 1));
            }
        }
        return memo[len1][len2];
    }
};

int main() {
    string word1 = "horse";
    string word2 = "ros";

    Solution s;
    cout << s.minDistance(word1, word2) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}