#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

// '(', ')', '{', '}', '[' and ']'
class Solution {
public:
    bool isValid(string s) {

        int len = s.size();
        if (len == 0)
            return true;


        stack<char> checkStack;

        for (int i = 0; i < len; ++i) {
            // 如果当前栈为空
            if (checkStack.size() == 0) {
                checkStack.push(s[i]);
            } else {
                // 如果栈中有元素

                // 如果是括号开始
                if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                    checkStack.push(s[i]);
                }


                if (s[i] == ')') {
                    // 如果栈顶为 ( ，则弹出栈
                    if (checkStack.top() == '(')
                        checkStack.pop();
                    else
                        checkStack.push(s[i]);
                }else if (s[i] == ']') {
                    // 如果栈顶为 [ ，则弹出栈
                    if (checkStack.top() == '[')
                        checkStack.pop();
                    else
                        checkStack.push(s[i]);
                } else if (s[i] == '}') {
                    // 如果栈顶为 [ ，则弹出栈
                    if (checkStack.top() == '{')
                        checkStack.pop();
                    else
                        checkStack.push(s[i]);
                }
            }
        }

        return checkStack.empty();
    }
};


int main() {

    Solution s;
    cout << s.isValid("()[]{") << endl;
    return 0;
}