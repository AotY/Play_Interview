#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;


// 输入一个字符串，求出该字符串包含的字符集合
int main() {

    string str;
    cin >> str ;

    unordered_set<char> charSet;
    for (int i = 0; i < str.size(); ++i) {
        if (charSet.find(str[i]) == charSet.end()) {
            cout << str[i];
            charSet.insert(str[i]);
        }
    }

    cout << endl;
    return 0;
}

// SoriEYVzZDtnWCFAKUONgPaplIybQHmM
// SoriEYVzZDtnWCFAKUONgPaplIybQHmM