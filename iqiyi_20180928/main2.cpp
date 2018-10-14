#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
#define maxn 1000005


// 散散掌控着一片森林，这片森林有N棵树，高度分别为ai，
// 现在散散想要长度为m的木头，散散的锯子有一个缺陷，必须同时切割所有的树木，
// 即如果有高度为10，15，12的树木，散散只能确定锯子的高度，如果锯子的高度为13，
// 那么只能将高度为15的树木切下长度为2的木头，锯子高度为8，则分别切下2，7，4的木头，共13长度。
// 请问锯子的高度最高可以多高呢？
//n <= 10^5
//m<= 10^9
//ai <= 10^9

ll n, m, maxHeight = 0, res;
ll h[maxn];

ll isSolution(int mid) {
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        sum += max((ll)0, h[i] - mid);
    }
    return sum >= m;
}

int main() {
    ll l = 1, r;
    //    第一行n和m
    //    第二行n个整数ai
    //    输出： 一个高度

    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        cin >> h[i];
        maxHeight = max(maxHeight, h[i]);
    }
    r = maxHeight;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (isSolution(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res  << endl;
}

/*
5 20
4 42 40 26 46


36
 */