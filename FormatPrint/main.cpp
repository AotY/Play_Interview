/*
 * main.cpp
 * Copyright (C) 2018 LeonTao 
 *
 * Distributed under terms of the MIT license.
 */

/* #include "main.h" */
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>


using namespace std;


string formatPrint(string &str, int index, string cur, int lastCount) {
    if (str[index] == ']'  || index > str.size()) {
        
        return cur;

    } else if (str[index] == '[') {
        string tmp_res = "";
        int tmpCount = lastCount;
        string tmp_cur = formatPrint(str, index + 1, cur, 1);
        for (int i = 0; i < tmpCount; i++)
            tmp_res += tmp_cur;
        return tmp_res;

    } else if (str[index] >= '0' && str[index] <= '9') {
        int tmpIndex = index;
        while (str[tmpIndex] >= '0' && str[tmpIndex] <= '9') {
            tmpIndex ++;
        }
        int count = stoi(str.substr(index, tmpIndex-index));

        return formatPrint(str, tmpIndex, cur, count);
            
    } else {
        // letter
        int tmpIndex = index;
        while (str[tmpIndex] >= 'A' && str[tmpIndex] <= 'Z') {
            tmpIndex ++;
        }

        string tmpCur = str.substr(index, tmpIndex - index) + formatPrint(str, tmpIndex, "", lastCount);
        return tmpCur;
    }

}




int main() {

    string str = "3[K2[AB]]";
    // cin >> str;
    int index = 0;
    string cur = "";

    string res = formatPrint(str, 0, cur, 1);

    cout << res << endl;
    return 0;
}
