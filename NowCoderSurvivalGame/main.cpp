#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <map>
#include <stdio.h>

using namespace std;

// 排名得分标准
struct RankScore {
    int l;
    int r;
    int score;
};

// 击杀信息
struct KillInfo {
    int timeK;
    string killerK;
    string victimK;
};

// 排名 + 击杀 + 生存 ，按字母排序
struct UserInfo {
    string name;
    int killCount;
    int survivalTime;
    int rank;
    int score;

    UserInfo() : killCount(0), survivalTime(0), rank(0), score(0) {};
};


// 获取排名分数
int getRankScore(int rank, const vector<RankScore> &rankScores) {
    for (int i = 0; i < rankScores.size(); ++i) {
        if (rank >= rankScores[i].l && rank <= rankScores[i].r)
            return rankScores[i].score;
    }
    return 0;
}


// 字母排序
bool nameCompare(const UserInfo &user1, const UserInfo &user2) {
    return user1.name < user2.name;
}

// 生存时间排序
bool userCompare(const UserInfo &user1, const UserInfo &user2) {
    if (user1.survivalTime == user2.survivalTime)
        return user1.killCount > user2.killCount;
    else
        return user1.survivalTime > user2.survivalTime;
}

vector<UserInfo> computeScore(const vector<RankScore> &rankScores,
                              const vector<int> &killScore,
                              const vector<KillInfo> &killinfos, int Q, int A, int B) {


    // 得出死亡顺序，并且记录时间
    // 击杀得分
    vector<UserInfo> userinfosVector = vector<UserInfo>(Q);
    unordered_set<string> nameSet;
    map<string, int> nameIndexMap;
    int userIndex = 0;
    for (int i = 0; i < killinfos.size(); ++i) {
        int timeK = killinfos[i].timeK;
        string killerName = killinfos[i].killerK;
        string victimName = killinfos[i].victimK;

        if (nameSet.find(killerName) != nameSet.end()) {
            UserInfo killUser = userinfosVector[nameIndexMap[killerName]];
            killUser.survivalTime = max(killUser.survivalTime, timeK);
            int ks = 0; //击杀得分
            if (killerName != victimName) {
                killUser.killCount += 1;
                ks = killScore[0];
                if (nameSet.find(victimName) != nameSet.end()) {
                    UserInfo victimUser = userinfosVector[nameIndexMap[victimName]];

                    if (victimUser.killCount >= killScore.size())
                        ks = killScore[killScore.size() - 1];
                    else
                        ks = killScore[victimUser.killCount];
                }
            }
            killUser.score += ks;
            userinfosVector[nameIndexMap[killerName]] = killUser;
        } else {
            UserInfo killUser;
            killUser.name = killerName;
            killUser.killCount += 1;
            killUser.score += killScore[0];

            nameIndexMap[killerName] = userIndex;
            nameSet.insert(killerName);
            userinfosVector[userIndex] = killUser;
            userIndex++;
        }

        if (nameSet.find(victimName) != nameSet.end()) {
            UserInfo victimUser = userinfosVector[nameIndexMap[victimName]];
            victimUser.survivalTime = timeK;
            userinfosVector[nameIndexMap[victimName]] = victimUser;
        } else {
            UserInfo victimUser;
            victimUser.name = victimName;
            victimUser.survivalTime = timeK;

            nameSet.insert(victimName);
            nameIndexMap[victimName] = userIndex;
            userinfosVector[userIndex] = victimUser;
            userIndex++;
        }
    }


    // 计算排名得分,按死亡顺序排序
    sort(userinfosVector.begin(), userinfosVector.end(), userCompare);
    for (int j = 1; j <= userIndex; ++j) {
        userinfosVector[j - 1].score += getRankScore(j, rankScores);
    }


    // 计算生存得分
    for (int k = 0; k < userIndex; ++k) {
        userinfosVector[k].score += userinfosVector[k].survivalTime * A + B;
    }


    // 按字母排序
    sort(userinfosVector.begin(), userinfosVector.end(), nameCompare);

    return userinfosVector;

}


int main() {

    int T; // T组数据

    cin >> T;

    for (int i = 0; i < T; ++i) {

        string line;
        getline(cin, line); //

        int Q, N, M; //Q个玩家，N记录排名积分规则，M记录击杀积分规则

        cin >> Q >> N >> M;

        //
        vector<RankScore> rankScores = vector<RankScore>(N);
        for (int j = 0; j < N; ++j) {
            RankScore rs;
            cin >> rs.l >> rs.r >> rs.score;
            rankScores[j] = rs;
        }

        //
        vector<int> killScores = vector<int>(M + 1);
        for (int k = 0; k < M + 1; ++k) {
            cin >> killScores[k];
        }

        int A, B;
        cin >> A >> B;
        vector<KillInfo> killinfos = vector<KillInfo>(Q - 1);
        for (int l = 0; l < Q - 1; ++l) {
            KillInfo kl;

            cin >> kl.timeK;
            cin >> kl.killerK;
            cin >> kl.victimK;
            killinfos[l] = kl;
        }

        // 计算积分  排名 + 击杀 + 生存 ，按字母排序
        vector<UserInfo> res = computeScore(rankScores, killScores, killinfos, Q, A, B);
        for (int m = 0; m < res.size(); ++m) {
            cout << res[m].name << " " << res[m].score << endl;
        }

    }


    return 0;
}

/*

1

10 6 3
1 1 300
2 2 250
3 3 200
4 5 100
6 8 50
9 10 10
10 50 100 150
5 1
0 Apple Ball
1 Cat Dog
2 Elephane Fish
5 Gorilla Hat
8 Igloo Juice
10 Cat Cat
10 Elephane Igloo
15 Gorilla Elephane
20 Apple Gorilla


 */