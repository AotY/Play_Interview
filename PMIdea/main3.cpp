#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Task {
    int id; // idea 编号
    int pm; // PM 编号
    int time; // 提出时间
    int pri; // 优先级
    int dur; // 所需时间

};


vector<vector<Task>> pmtasks;
map<int, int> result;
int proid = 1;

class Programer {
private:
    int t; // 当前的时间
    int id;

public:
    Programer() {
        this->t = 0;
        this->id = proid++;
    }

    int getT() {
        return this->t;
    }

    int getId() {
        return this->id;
    }

    int doTask() {
        vector<Task>::iterator findT;
        int index = -1;

        // 这里是先挑编号小的PM
        for (size_t i = 0; i < pmtasks.size(); i++) {
            auto &tasks = pmtasks.at(i);

            if (tasks.size() == 0)
                continue;

            auto it = tasks.begin();

            while (it != tasks.end() && it->time > t) // 还没到开始时间
                it++;

            if (it == tasks.end())
                continue;


            if (index == -1) {
                findT = it;
                index = i;
            } else {
                if (it->dur < findT->dur) {
                    findT = it;
                    index = i;
                }
            }
        }

        if (index != -1) {
            t += findT->dur;
            result[findT->id] = t;
            pmtasks.at(index).erase(findT);
            return 1;
        } else
            t++;

        return 0;
    }

};

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    pmtasks.resize(n); // Resizes the container to contain count elements.

    for (size_t i = 0; i < p; i++) {
        Task task;
        cin >> task.pm >> task.time >> task.pri >> task.dur;
        task.id = i;

        // 分别存储pm的task
        pmtasks.at(task.pm - 1).push_back(task);

    }

    for (size_t i = 0; i < pmtasks.size(); i++) {

        auto &tasks = pmtasks.at(i);

        if (tasks.size() == 0)
            continue;

        sort(tasks.begin(), tasks.end(), [](Task &t1, Task &t2) {
            if (t1.pri == t2.pri) {
                if (t1.dur == t2.dur)
                    return t1.time < t2.time;
                else
                    return t1.dur < t2.dur;
            } else
                return t1.pri > t2.pri;
        });
    }

    vector<Programer> pros(m);

    // 时间比较
    while (p > 0) {
        sort(pros.begin(), pros.end(), [&](Programer &t1, Programer &t2) {
            return t1.getT() < t2.getT();
        });

        p -= pros.begin()->doTask();
    }

    for (auto &it : result)
        cout << it.second << endl;

    return 0;
}


/*
 *
 *
 *
输入例子1:
2 2 5
1 1 1 2
1 2 1 1
1 3 2 2
2 1 1 2
2 3 5 5

输出例子1:
3
4
5
3
9


 */