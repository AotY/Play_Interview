#include <iostream>
#include <string>
#include <vector>
#include <set>


using namespace std;

set<char> specialSet = {
        '!',
        '@',
        '#',
        '$',
        '%',
        '^',
        '&',
        '*',
        '(',
        ')',
        '_',
        '-',
        '=',
        '+',
        '[',
        ']',
        '{',
        '}',
        ',',
        '.',
        '<',
        '>',
        '/',
        '?'
};

bool isWeakPassword(string password) {
    int n = password.size();

    // 长度
    if (n < 8)
        return true;

    // 大写，小写，数组，特殊字符
    int lowerCount = 0;
    int upperCount = 0;
    int numberCount = 0;
    int specialCount = 0;

    for (int i = 0; i < n; ++i) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lowerCount++;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            upperCount++;
        } else if (password[i] >= '0' && password[i] <= '9') {
            numberCount++;
        } else if (specialSet.find(password[i]) != specialSet.end()) {
            specialCount++;
        }
    }
    if (lowerCount == 0 || upperCount == 0 || numberCount == 0 || specialCount == 0) {
        return true;
    }


    // 等差数列
    int left = 0;
    int right = 0;
    while (right < n) {
        if (password[right] >= '0' && password[right] <= '9') {

            if (right - left == 2) {
                int num1 = password[left] - '0';
                int num2 = password[left + 1] - '0';
                int num3 = password[right] - '0';

                if ((num2 - num1) == (num3 - num2))
                    return true;
                left = right;
            }
            right ++;
        } else {
            right++;
            left = right;
            continue;
        }
    }

    // 三个连续大写或者小写字母
    left = 0;
    right = 0;

    while (right < n) {
        if (password[right] >= 'A' && password[right] <= 'Z') {

            if (right - left == 2) {
                int num1 = password[left] - 'A';
                int num2 = password[left + 1] - 'A';
                int num3 = password[right] - 'A';

                int sub1 = (num2 - num1);
                int sub2 = (num3 - num2);

                if (sub1 == sub2 && sub1 == 1)
                    return true;

                left = right;
            }
            right ++;
        } else {
            right++;
            left = right;
            continue;
        }
    }

    while (right < n) {
        if (password[right] >= 'a' && password[right] <= 'z') {

            if (right - left == 2) {
                int num1 = password[left] - 'a';
                int num2 = password[left + 1] - 'a';
                int num3 = password[right] - 'a';

                int sub1 = (num2 - num1);
                int sub2 = (num3 - num2);

                if (sub1 == sub2 && sub1 == 1)
                    return true;

                left = right;
            }
            right ++;
        } else {
            right++;
            left = right;
            continue;
        }
    }


    //包含特殊单词
    if (    password.find("admin") != string::npos ||
            password.find("hello") != string::npos ||
            password.find("qwerty") != string::npos ||
            password.find("iloveyou") != string::npos ||
            password.find("password") != string::npos ||
            password.find("112233") != string::npos )
        return true;

    return false;
}


int main() {

    int n;

    cin >> n;
    vector<string> strs = vector<string>(n);
    for (int i = 0; i < n; ++i) {
        string password;
        cin >> password;
//        scanf("%s", password);
        strs[i] = password;
    }

    for (int j = 0; j < n; ++j) {
        bool res = isWeakPassword(strs[j]);
        if (res)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }

    return 0;
}