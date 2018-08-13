#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

// 2 2 6
// zzaa 还是回溯法，哎，笔试时没弄出来
// 开存储a和z 这样就好了 (不超时）

vector<string> results;

void searchWords(string &a, string &z, string &curWord, int totalLen) {

    if (curWord.size() == totalLen) {
        results.push_back(curWord);
        return;
    }

    if (a.size() > 0) {
        curWord.push_back(a[0]);
        a.pop_back();
        searchWords(a, z, curWord, totalLen);
        curWord.pop_back();
        a.push_back('a');
    }


    if (z.size() > 0) {
        curWord.push_back(z[0]);
        z.pop_back();
        searchWords(a, z, curWord, totalLen);
        curWord.pop_back();
        z.push_back('z');
    }


}

int main() {

    int n, m, k;

    cin >> n >> m >> k;


    // 单词是按照字典顺序排序的

    string a;
    for (int i = 0; i < n; ++i) {
        a.push_back('a');
    }


    string z;
    for (int i = 0; i < m; ++i) {
        z.push_back('z');
    }


    string curWord = "";
    searchWords(a, z, curWord, m + n);

    // 排序

    sort(results.begin(), results.end(), [&](string &s1, string &s2) { return s1 < s2; });

    cout << results.size() << endl;
    cout << results[k - 1] << endl;

    return 0;
}