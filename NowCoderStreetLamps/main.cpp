#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 路灯可以照亮pos - 1, pos, pos + 1这三个位置。
int getLamps(int n, string &road) {

    int res = 0;
    // 窗口移动
    int left = 0;
    int right = left + 2;

    while (right < n) {

        if (road[left] == 'X') {
            left++;
            right++;
            continue;
        } else {
            res++;
            left = right + 1;
            right = left + 2;
            continue;
        }
    }

    // 边界情况，[left, right]长度小于等于2时
    if (right >= n && left < n) {
        for (int i = left; i < n; ++i) {
            if (road[i] == '.') {
                res++;
                break;
            }
        }
    }


    return res;
}

int main() {


//    输入的第一行包含一个正整数t(1 <= t <= 1000), 表示测试用例数
//    接下来每两行一个测试数据, 第一行一个正整数n(1 <= n <= 1000),表示道路的长度。
//    第二行一个字符串s表示道路的构造,只包含'.'和'X'。
    // 对于每个测试用例, 输出一个正整数表示最少需要多少盏路灯。

    int t;
    cin >> t;
    string road;
    int n;
    string line;
    for (int i = 0; i < t; ++i) {
        cin >> n;
//        getline(cin, line);
        cin >> road;
        int res = getLamps(n, road);

        cout << res << endl;
    }

    return 0;
}