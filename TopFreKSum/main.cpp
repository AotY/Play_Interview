#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct NumFre{
    int index;
    int num;
    int fre;

};

bool numFreCompare(const NumFre &numFre1, const NumFre &numFre2) {
    if (numFre1.fre != numFre2.fre)
        return numFre1.fre > numFre2.fre;
    else
        return numFre1.index < numFre2.index;
}

int main() {

    int n;
    cin >> n;

    int num;
    vector<NumFre> numFres;
    map<int, int> indexMap;

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (indexMap.find(num) != indexMap.end()) {
            int vIndex = indexMap[num];
            NumFre numFre = numFres[vIndex];
            numFre.fre += 1;
            numFres[vIndex] = numFre;

        } else {
            NumFre numFre = NumFre();
            numFre.index = i;
            numFre.num = num;
            numFre.fre = 1;
            indexMap.insert(make_pair(num, numFres.size()));
            numFres.push_back(numFre);
        }
    }

    sort(numFres.begin(), numFres.end(), numFreCompare);

    int res = numFres[0].num + numFres[1].num;

    cout << res << endl;
    return 0;
}


/*
6
1
1
1
2
2
3

5
1
2
1
3
5
 */