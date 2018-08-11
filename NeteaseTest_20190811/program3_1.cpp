#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 2 2 6
// zzaa

void searchAWords(string &a, string &b, string &curWord, int index, int n, int m, int ln, int lm);

void searchBWords(string &a, string &b, string &curWord, int index, int n, int m, int ln, int lm);


vector<string> results;
vector<bool> aMark;
vector<bool> bMark;


void searchBWords(string &a, string &b, string &curWord, int index, int n, int m, int ln, int lm) {
    if (curWord.size() >= (n + m)) {
        results.push_back(curWord);
        return;
    }

    for (int i = index; i < m; ++i) {
        if (!bMark[i] && index < (n + m)) {
            bMark[i] = true;
            curWord.push_back(b[i]);
            lm--;
            searchBWords(a, b, curWord, i + 1, n, m, ln, lm);
            bMark[i] = false;
            curWord.pop_back();
        }
    }

    if (ln > 0)
        searchAWords(a, b, curWord, 0, n, m, ln, lm);

}

void searchAWords(string &a, string &b, string &curWord, int index, int n, int m, int ln, int lm) {
    if (curWord.size() >= (n + m)) {
        results.push_back(curWord);
        return;
    }

    for (int i = index; i < n; ++i) {
        if (!aMark[i] && index < (n + m)) {
            aMark[i] = true;
            curWord.push_back(a[i]);
            ln--;
            searchAWords(a, b, curWord, i + 1, n, m, ln, lm);
            aMark[i] = false;
            curWord.pop_back();
        }
    }


    if (lm > 0)
        searchBWords(a, b, curWord, 0, n, m, ln, lm);

}

void searchWords(string &a, string &b, int n, int m) {


    // a 在前面的组合
    for (int i = 0; i < n; ++i) {
        string curWord = "";
        curWord.push_back(a[i]);
        aMark[i] = true;
        searchAWords(a, b, curWord, i + 1, n, m, n - 1, m);
        aMark[i] = false;
    }

    // z在前面的组合
    for (int i = 0; i < m; ++i) {
        string curWord = "";
        curWord.push_back(b[i]);
        bMark[i] = true;
        searchBWords(a, b, curWord, i + 1, n, m, n, m - 1);
        bMark[i] = false;
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


    string b;
    for (int i = 0; i < m; ++i) {
        b.push_back('z');
    }


    aMark = vector<bool>(n, false);

    bMark = vector<bool>(m, false);
    searchWords(a, b, n, m);

    // 排序
    sort(results.begin(), results.end(), [&](string &s1, string &s2) { return s1 < s2; });

    cout << results.size() << endl;
    cout << results[k - 1] << endl;

    return 0;
}