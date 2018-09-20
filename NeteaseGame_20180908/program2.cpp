#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <istream>

using namespace std;


struct Conference {
    int s;
    int f;
    int dur;
};


bool conCompare(Conference &con1, Conference &con2) {
    if (con1.dur != con2.dur)
        return con1.dur > con2.dur;
    else {
        // con1.dur == con2
        return con1.s < con2.s;
    }
}

bool resCompare(Conference &con1, Conference &con2) {
        return con1.f < con2.f;
}


int main() {


    vector<Conference> cons;
    vector<Conference> results;
    while (true) {
        int s;
        int f;
        scanf("%d,%d", &s, &f);

        if (s == 0 && f == 0) {
            break;
        }

        Conference con;
        con.s = s;
        con.f = f;
        con.dur = f - s;

        if (f <= 0)
            continue;

        cons.push_back(con);
    }

    // sort
    sort(cons.begin(), cons.end(), conCompare);
    vector<bool> mark = vector<bool> (24, false);
    // merge
    for (int i = 0; i < cons.size(); i++) {
        bool flag = true;
        for (int j = cons[i].s; j < cons[i].f; ++j) {
            if (mark[j]) {
                flag = false;
                break;
            } else{
                mark[j] = true;
            }
        }
        if (flag)
            results.push_back(cons[i]);
    }

    // sort
    sort(results.begin(), results.end(), resCompare);

    for (int i = 0; i < results.size(); ++i) {
        cout << results[i].s << "," << results[i].f << endl;
    }

    return 0;
}


/**
 *
8,10
9,11
13,15
10,15
8,9
0,0


 *
 */








