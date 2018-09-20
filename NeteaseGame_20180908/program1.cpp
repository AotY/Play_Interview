#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>


using namespace std;


string tryOpt(string &str) {

    // 最后一位
    str.push_back('#');

    string res="";
    res.clear();

    int index = 1;

    int matchCount = 0;

    int startIndex = 0;

    while (index < str.size()) {

        if (str[index] == str[index - 1] + 1) {
            matchCount ++;
        } else {
            //
            if (matchCount >= 3) {
                res.push_back(str[startIndex]);
                res.push_back('-');
                res.push_back(str[index - 1]);
            } else {

                if (matchCount > 0) {
                    for (int i = startIndex; i < index; ++i) {
                        res.push_back(str[i]);
                    }
                } else {
                    res.push_back(str[index - 1]);
                }
            }
            matchCount = 0;
        }

        if (matchCount == 1)
            startIndex = index - 1;

        index++;
    }
    if (res[res.size() - 1] == '#')
        res.pop_back();

    return res;
}

int main() {

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {

        string str;
        cin >> str;

        string res = tryOpt(str);


        cout << res << endl;


    }


    return 0;
}

/*

1
ZABCEFGHI

1
XYZABCD
 */