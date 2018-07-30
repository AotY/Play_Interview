#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
private:
    vector<string> results;

    const vector<string> numberMap = {
            {},
            {},
            {"abc"},
            {"def"},
            {"ghi"},
            {"jkl"},
            {"mno"},
            {"pqrs"},
            {"tuv"},
            {"wxyz"}
    };


    void searchCombination(string digits, int index, string curCombination) {

        if (index >= digits.size())
            results.push_back(curCombination);


        int mapIndex = digits[index] - '0';
        for (int j = 0; j < numberMap[mapIndex].size(); ++j) {
            curCombination.push_back(numberMap[mapIndex][j]);
            searchCombination(digits, index + 1, curCombination);
            curCombination.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return results;

        int mapStartIndex = digits[0] - '0';
        for (int i = 0; i < numberMap[mapStartIndex].size(); ++i) {
            string curCombination = "";
            curCombination.push_back(numberMap[mapStartIndex][i]);
            searchCombination(digits, 1, curCombination);
        }

        return results;
    }


};


int main() {
    Solution s;
    vector<string> results = s.letterCombinations("23");
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}