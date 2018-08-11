#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_D = 1000000001;
struct Job {
    int dl; // 难度下限
    int dr; // 难度上限 [dl, dr)
    int p; // 报酬
};

int searchP(const vector<Job> &jobs, int ai) {
    int maxP = -1;
    for (int i = 0; i < jobs.size(); ++i) {
        if (ai >= jobs[i].dl && ai < jobs[i].dr)
            maxP = max(maxP, jobs[i].p);
    }
    return maxP;
}


bool jobCompare(const Job &job1, const Job &job2) {
    if (job1.dl != job2.dl)
        return job1.dl < job2.dl;
    else
        return job1.p > job2.p;
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

        cin >> job.dl >> job.p;

        jobs[i] = job;
    }

    // 是否要排序 ？
    sort(jobs.begin(), jobs.end(), jobCompare);

    for (int i = 0; i < N; ++i) {
        if (i != 0)
            jobs[i - 1].dr = jobs[i].dl;

        if (i == (N - 1))
            jobs[i].dr = 1000000001;
    }


//    vector<int> niuFriend = vector<int>(M);
    // 接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
    for (int j = 0; j < M; ++j) {
        int ai;
//        cin >> niuFriend[j];
        cin >> ai;
        int p = searchP(jobs, ai);

        cout << p << endl;
    }



//    std::cout << "Hello, World!" << std::endl;
    return 0;
}