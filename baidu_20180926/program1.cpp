#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;


// 第一题
// 宝箱怪是游戏中常见的一种怪物，它们伪装成普通的宝箱，并在被玩家打开时攻击玩家。
// 假设你操控的游戏角色身处一个放着N个宝箱的房间，每个宝箱或者是普通的宝箱，或者是宝箱怪。
// 每个宝箱上都贴着一张字条，字条上写着以下两种信息中的一种：
// ① 第x个宝箱是普通宝箱；
// ② 第x个宝箱是宝箱怪。
// 其中普通宝箱上的信息一定是真的，而宝箱怪上的信息可能是假的，
// 那么根据这些信息，有多少个宝箱一定是普通宝箱，又有多少个宝箱一定是宝箱怪？
int main() {

//    第一行包含一个整数N，1≤N≤105。
//   接下来N行，第i行包含两个整数t和x，1≤t≤2，1≤x≤N。
//   若t=1，则第i个宝箱上的信息为：第x个宝箱是普通宝箱；
//   若t=2，则第i个宝箱上的信息为：第x个宝箱是宝箱怪。

//    输出两个以空格隔开的整数，
//  第一个整数表示可以确定为普通宝箱的宝箱数量，
//  第二个整数表示可以确定为宝箱怪的宝箱数量。
//    每个宝箱都可能是宝箱怪，其中第一个宝箱一定是宝箱怪。

    int N;
    cin >> N;

    vector<int> ts = vector<int>(N);
    vector<int> xs = vector<int>(N);


    set<int> normalSet;
    set<int> monsterSet;
    set<int> uncertainSet;

    map<int, pair<int, bool>> infos;

    for (int i = 1; i <= N; ++i) {
        cin >> ts[i] >> xs[i];

        if (ts[i] == 1) {
            //  则第i个宝箱上的信息为：第x个宝箱是普通宝箱；
            infos.insert(make_pair(i, make_pair(xs[i], true))); // normal
        } else if (ts[i] == 2) {
            infos.insert(make_pair(i, make_pair(xs[i], false))); // monster
        }
    }

    // 第一个
    pair<int, bool> firstB = infos[1];
    infos[1] = make_pair(firstB.first, false);
    monsterSet.insert(1);
    uncertainSet.insert(firstB.first);

    //
    for (int i = 1; i <= N; ++i) {
        pair<int, bool> curB = infos[i];
        if (uncertainSet.find(i) != uncertainSet.end()) {
            uncertainSet.insert(curB.first);

            if (normalSet.find(i) != normalSet.end()) {
                normalSet.erase(i);
            }


        } else if (monsterSet.find(i) != monsterSet.end()) {
            uncertainSet.insert(curB.first);

            if (normalSet.find(i) != normalSet.end()) {
                normalSet.erase(i);
            }

        } else if (normalSet.find(i) != normalSet.end()) {
            if (curB.second)
                normalSet.insert(curB.first);
            else {

                monsterSet.insert(curB.first);
                if (normalSet.find(curB.first) != normalSet.end()) {
                    normalSet.erase(curB.first);
                }
            }
        } else {
            if (i == curB.first) {
                uncertainSet.insert(curB.first);
            } else {
                if (curB.second)
                    normalSet.insert(curB.first);
                else {

                    monsterSet.insert(curB.first);
                    if (normalSet.find(curB.first) != normalSet.end()) {
                        normalSet.erase(curB.first);
                    }
                }
            }

        }
    }


    cout << normalSet.size() << " " << monsterSet.size() << endl;

    return 0;
}

/*
3
1 2
2 1
1 3


0 1
 */