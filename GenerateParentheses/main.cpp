#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

class Solution {
private:
    vector<string> results;

    void searchParenthesis(int n, vector<char> openParenthesis, vector<char> closeParenthesis,
                           int index, vector<char> curParentheses, stack<char> legalStack) {
        int curSize = curParentheses.size();
        if (curSize == 2 * n) {
            // 这里的判断标准还是应该使用栈来判断
            if (legalStack.size() == 0) {
                string result(curParentheses.begin(), curParentheses.end());
                results.push_back(result);
            }
            return;
        }

        if (closeParenthesis.size() <= 0 && openParenthesis.size() >= 1)
            return;

        for (int i = 0; i < 2; ++i) {
            // 0 -- (   1 -- )
            if (i == 0) {
                if (openParenthesis.size() > 0) {
                    curParentheses.push_back('(');
                    openParenthesis.pop_back();
                    legalStack.push('(');
                    searchParenthesis(n, openParenthesis, closeParenthesis, index + 1, curParentheses, legalStack);
                    legalStack.pop();
                    openParenthesis.push_back('(');
                    curParentheses.pop_back();
                }
            } else {
                if (closeParenthesis.size() > 0) {
                    curParentheses.push_back(')');
                    closeParenthesis.pop_back();
                    bool isPop = false;
                    if ((legalStack.size() > 0) && (legalStack.top() == '('))
                        legalStack.pop();
                    else {
                        legalStack.push(')');
                        isPop = true;
                    }
                    searchParenthesis(n, openParenthesis, closeParenthesis, index + 1, curParentheses, legalStack);
                    if (isPop)
                        legalStack.pop();
                    closeParenthesis.push_back(')');
                    curParentheses.pop_back();
                }
            }

        }

    }

public:
    vector<string> generateParenthesis(int n) {

        vector<char> openParenthesis(n, '(');
        vector<char> closeParenthesis(n, ')');


        vector<char> curParentheses;
        curParentheses.push_back('(');
        openParenthesis.pop_back();

        stack<char> legalStack;
        legalStack.push('(');
        searchParenthesis(n, openParenthesis, closeParenthesis, 1, curParentheses, legalStack);


        return results;
    }
};


int main() {

    Solution s;
    vector<string> results = s.generateParenthesis(3);

    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}