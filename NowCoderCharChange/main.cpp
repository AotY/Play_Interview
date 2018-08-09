#include <iostream>
#include <string>

using namespace std;

//int maxCharCount()

int main() {

    string str;
    int m;

    int countArr[26] = {0};

    cin >> str >> m;

    int len = str.size();

    // init
    int left = 0;
    int right = left + m + 1;
    if (right >= len)
        right = len - 1;

    int maxCount = 0;
    for (int i = left; i <= right; ++i) {
        int index = str.at(i) - 'a';
        countArr[index]++;
        maxCount = max(maxCount, countArr[index]);
    }


    while (true) {
        left++;
        right = left + m + 1;
        if (right >= len) {
            break;
        }

        int index1 = str.at(left - 1) - 'a';
        int index2 = str.at(right) - 'a';
        countArr[index1]--;
        countArr[index2]++;

//        maxCount = max(maxCount, countArr[index1]);
        maxCount = max(maxCount, countArr[index2]);

    }

    cout << maxCount << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}