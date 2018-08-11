#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

// 2 2 6
// zzaa 还是回溯法，哎，笔试时没弄出来

set<string> results;
vector<bool> mark;

void searchWords(string &str, string &curWord, int index) {

    if (curWord.size() == str.size()) {
        results.insert(curWord);
        return;
    }

    // 后面排序就好了，哎，我的锅
    for (int i = 0; i < str.size(); ++i) {
        if (!mark[i]) {
            curWord.push_back(str[i]);
            mark[i] = true;
            searchWords(str, curWord, i + 1);
            curWord.pop_back();
            mark[i] = false;
        }
    }


}

int main() {

    int n, m, k;

    cin >> n >> m >> k;


    // 单词是按照字典顺序排序的

    string str;
    for (int i = 0; i < n; ++i) {
        str.push_back('a');
    }


    for (int i = 0; i < m; ++i) {
        str.push_back('z');
    }


    mark = vector<bool>(str.size(), false);

    string curWord = "";
    searchWords(str, curWord, 0);

    // 排序
    vector<string> resultsVector(results.begin(), results.end());

    sort(resultsVector.begin(), resultsVector.end(), [&](string &s1, string &s2) { return s1 < s2; });

//    cout << results.size() << endl;
    cout << resultsVector[k-1] << endl;

    return 0;
}