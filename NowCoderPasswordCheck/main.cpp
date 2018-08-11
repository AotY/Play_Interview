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
            right++;
        } else {
            right++;
            left = right;
            continue;
        }

        if (right - left == 2) {
            int num1 = password[left] - '0';
            int num2 = password[left + 1] - '0';
            int num3 = password[right] - '0';

//            if (num1 == num2 && num1 == num3)
//                return true;

            if ((num2 - num1) == (num3 - num2))
                return true;

            right++;
            left = right;
        }
    }

    // 三个连续大写或者小写字母
    left = 0;
    right = 0;
    while (right < n) {
        if (password[right] >= 'A' && password[right] <= 'Z') {
            right++;
        } else {
            right++;
            left = right;
            continue;
        }

        if (right - left == 2) {
            int num1 = password[left] - 'A';
            int num2 = password[left + 1] - 'A';
            int num3 = password[right] - 'A';

            int sub1 = (num2 - num1);
            int sub2 = (num3 - num2);

            if (sub1 == sub2 && sub1 == 1)
                return true;

            right++;
            left = right;
        }
    }

    left = 0;
    right = 0;
    while (right < n) {
        if (password[right] >= 'a' && password[right] <= 'a') {
            right++;
        } else {
            right++;
            left = right;
            continue;
        }

        if (right - left == 2) {
            int num1 = password[left] - 'a';
            int num2 = password[left + 1] - 'a';
            int num3 = password[right] - 'a';

            int sub1 = (num2 - num1);
            int sub2 = (num3 - num2);

            if (sub1 == sub2 && sub1 == 1)
                return true;

            right++;
            left = right;
        }
    }


    //包含特殊单词
    left = 0;
    right = 0;
    while (right < n) {
        if (password[right] >= 'a' && password[right] <= 'a') {
            right++;
        } else {
            right++;
            left = right;
            continue;
        }

        if (right - left == 4) {
            string subStr = password.substr(left, (right - left) + 1);

            if (subStr == "admin" ||
                subStr == "hello")
                return true;

            right++;
            left = right;
        }

        if (right - left == 5) {
            string subStr = password.substr(left, (right - left) + 1);

            if (subStr == "qwerty")
                return true;

            right++;
            left = right;
        }

        if (right - left == 7) {
            string subStr = password.substr(left, (right - left) + 1);

            if (subStr == "iloveyou" || subStr == "password")
                return true;

            right++;
            left = right;
        }
    }


    left = 0;
    right = 0;
    while (right < n) {
        if (password[right] >= '0' && password[right] <= '9') {
            right++;
        } else {
            right++;
            left = right;
            continue;
        }

        if (right - left == 5) {
            string subStr = password.substr(left, (right - left) + 1);

            if (subStr == "112233")
                return true;

            right++;
            left = right;
        }
    }

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