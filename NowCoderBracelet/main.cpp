#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int unmatchedColors(vector<unordered_set<int>> &bracelet, int n, int m, int c) {
    if (n <= 1)
        return 0;
    int res = 0;

    for (int i = 1; i <= c; ++i) {

        int left = 0;
        int right = 0;

        while (left < n) {
            right = left + m - 1;
            int count = 0;
            for (int j = left; j <= right; ++j) {
                if (bracelet[j % n].find(i) != bracelet[j % n].end())
                    count++;

                if (count >= 2) {
                    res++;
                    break;
                }
            }

            left += 1;
        }
    }

    return res;
}


int main() {

    int n, m, c;

    cin >> n >> m >> c;

    int num;
    int color;

    vector<unordered_set<int>> bracelet = vector<unordered_set<int>>(n);
    for (int i = 0; i < n; ++i) {
        cin >> num;
        unordered_set<int> bead;
        for (int j = 0; j < num; ++j) {
            cin >> color;
            bead.insert(color);
        }
        bracelet[i] = bead;
    }

    int res = unmatchedColors(bracelet, n, m, c);

    cout << res << endl;

    return 0;
}