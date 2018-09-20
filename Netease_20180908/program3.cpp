#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

/**
1 2
8
2 1 9
1 1



8
 */
// 第三题


void tryPour(vector<int> &vs) {

}

int main() {

    // 香槟塔有个很优雅的视觉效果就是如果这一层的香槟满了，就会从边缘处往下一层流去。
    // 指令一是往第x层塔内倒体积为v的香槟
    // 指令二是询问第k层塔香槟的体积为多少 ?
    // 告诉你香槟塔每层香槟塔的初始容量，你能帮牛牛快速回答妞妞的询问吗？

    // 第一行为两个整数n，m。表示香槟塔的总层数和指令条数。
    // 第二行为n个整数a ，表示每层香槟塔的初始容量。

    int n, m;
    cin >> n >> m;

    vector<int> capabilities = vector<int>(n);
    vector<int> leftCap = vector<int>(n);

    for (int i = 0; i < n; ++i) {
        cin >> capabilities[i];
        leftCap[i] = capabilities[i];
    }

    // 第三行到第2+m行有两种输入，一种输入是“2 x v”表示往第x层倒入体积为v的香槟；另一种输入是“1 k”表示询问第k层当前有多少香槟。
    for (int i = 0; i < m; ++i) {
        int type;
        int layer;

        cin >> type;
        cin >> layer;
        layer -= 1;

        if (type == 2) {
            // 倒入香槟
            int v;
            cin >> v;

            for (int j = layer; j < n && v > 0; j++) {
                if (leftCap[j] > 0) {
                    if (v > leftCap[j]) {
                        v -= leftCap[j];
                        leftCap[j] = 0;
                    } else {
                        leftCap[j] -= v;
                        v = 0;
                    }
                }
            }


        } else if (type == 1) {
            // 对于每个询问，输出一个整数，表示第k层香槟的容量。
            cout << capabilities[layer] - leftCap[layer] << endl;

        }

    }
    return 0;
}