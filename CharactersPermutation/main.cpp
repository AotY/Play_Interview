#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 字母全排列，又是典型的回溯法

void getPermutation(string &str, vector<string> &results, vector<bool> &mark, int curSize, string curStr) {
    if (curSize == str.size())
        results.push_back(curStr);


    for (int i = 0; i < str.size(); ++i) {
        if (!mark[i]) {
            mark[i] = true;
            curStr.push_back(str.at(i));
            getPermutation(str, results, mark, curSize + 1, curStr);
            curStr.pop_back();
            mark[i] = false;
        }
    }
}


int main() {

    string str;
    cin >> str;

    vector<string> results;

    vector<bool> mark = vector<bool>(str.size(), false);

    // 因为给定的字符串已经按小到大进行排序，故可保证得到的全排列顺序也是从小到大的
    getPermutation(str, results, mark, 0, "");

    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }

    return 0;
}