#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 需要先对查找的位置进行排序，然后进行比较，这样才不会超时
vector<int> queryQ(vector<int> &apples, vector<pair<int, int>> &querys) {

    vector<int> res = vector<int>(querys.size(), 0);

    int queryIndex = 0;
    int appleIndex = 0;

    int sum = 0;
    sum += apples[0];

    while (queryIndex < querys.size())

        if (sum >= querys[queryIndex].first) {
            res[querys[queryIndex].second] = appleIndex;
            queryIndex ++;
        } else {
            appleIndex += 1;
            sum += apples[appleIndex];
        }

    return res;
}



bool queryCompare(pair<int, int> &p1, pair<int, int> &p2) {
    return p1.first < p2.first;
}

// 第二题
int main() {


    int n;

    cin >> n;

    vector<int> apples = vector<int>(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> apples[i];
    }

    int m;

    cin >> m;


    vector<pair<int, int>> querys = vector<pair<int, int>>(m);
    for (int i = 0; i < m; ++i) {
        int q;
        cin >> q;
        querys[i] = make_pair(q, i);
    }

    sort(querys.begin(), querys.end(), queryCompare);

    vector<int> res = queryQ(apples, querys);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] + 1 << endl;
    }

    return 0;
}

/*
5
2 7 3 4 9
3
1 25 11

 */