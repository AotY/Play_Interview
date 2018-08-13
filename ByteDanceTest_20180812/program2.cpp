#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;


bool intervalCompare(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.first != p2.first)
        return p1.first < p2.first;
    else
        return p1.second < p2.second;
}


int main() {

    int m;

    cin >> m;

//    vector<vector<pair<int, int>>> intervals = vector<vector<pair<int, int>>>(m, vector<pair<int, int>>());
    vector<pair<int, int>> intervals;

    string line;
    getline(cin, line);

    for (int i = 0; i < m; ++i) {
        getline(cin, line);
        // 分隔字符串

        stringstream ssLine(line);

        string segment;
        vector<string> seglist;
        while (getline(ssLine, segment, ';')) {
            seglist.push_back(segment);
        }

        for (int j = 0; j < seglist.size(); ++j) {
            int tmpIndex = 0;
            while (seglist[j][tmpIndex] != ',')
                tmpIndex++;
            intervals.push_back(make_pair(stoi(seglist[j].substr(0, tmpIndex)),
                                          stoi(seglist[j].substr(tmpIndex + 1, seglist[j].size() - tmpIndex))));
        }
    }

    // merge intervals

    // 1. 排序
    sort(intervals.begin(), intervals.end(), intervalCompare);


    //
    vector<pair<int, int>> results;
    results.push_back(intervals[0]);
    int curSepInterIndex = 0;
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first >= results[curSepInterIndex].first && intervals[i].first <= results[curSepInterIndex].second)
            // 区间包含
            results[curSepInterIndex].second = max(results[curSepInterIndex].second, intervals[i].second);
        else {
            // 不包含
            curSepInterIndex++;
            results.push_back(intervals[i]);
        }

    }


    // 输出 1,45;78,100;200,220

    for (int i = 0; i < results.size(); ++i) {
        if (i != results.size() - 1) {
            cout << results[i].first << "," << results[i].second << ";";
        } else {
            cout << results[i].first << "," << results[i].second;
        }
    }


    return 0;
}