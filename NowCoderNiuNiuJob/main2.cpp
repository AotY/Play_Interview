#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int d; // 难度
    int p; // 报酬
};

struct Friend {
    int no; // 序号
    int d; //  能力

    int maxP; //可以得到的最大报酬
};


void searchP(vector<Job> &jobs, vector<Friend> &friends) {
//    int preMaxIndex = 0; // 前一个friend 的最大 P的job的位置
    int preMaxP = 0; // 前一个friend 的最大 P

    int jobIndex = 0;
    int friendIndex = 0;

    int curP = 0; // 当前P
    while (friendIndex < friends.size()) {
        if (friends[friendIndex].d >= jobs[jobIndex].d) {
            // 能力大于 d
            curP = jobs[jobIndex].p;

            if (curP > preMaxP) {
                preMaxP = curP;
            }

            friends[friendIndex].maxP = max(friends[friendIndex].maxP, preMaxP);

            if (jobIndex < jobs.size() - 1)
                jobIndex++;
            else
                friendIndex++;
        } else {
            // 能力小于 d
            friends[friendIndex].maxP = max(friends[friendIndex].maxP, preMaxP);
            friendIndex++;
        }

    }

}


bool jobCompare(const Job &job1, const Job &job2) {
    return job1.d < job2.d;
}

int main() {

    // 分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
    int N, M;
    cin >> N >> M;

    vector<Job> jobs = vector<Job>(N);
    int nextP;
    // 接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
    for (int i = 0; i < N; ++i) {
        Job job;
        cin >> job.d >> job.p;
        jobs[i] = job;
    }


    vector<Friend> friends = vector<Friend>(M);

    // 接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
    for (int j = 0; j < M; ++j) {
        Friend f;
        cin >> f.d;
        f.no = j;
        friends[j] = f;
    }

    // jobs sort
    sort(jobs.begin(), jobs.end(), jobCompare);

    // friends sort
    sort(friends.begin(), friends.end(), [&](const Friend &f1, const Friend &f2) { return f1.d < f2.d; });

    searchP(jobs, friends);

    // 按 no 序号排序
    sort(friends.begin(), friends.end(), [&](const Friend &f1, const Friend &f2) { return f1.no < f2.no; });

    for (int k = 0; k < M; ++k) {
        cout << friends[k].maxP << endl;
    }

    return 0;
}


/*
5 6
10 100
20 200
50 150
100 1000
200 2300
10 12 30 60 100 300
 */