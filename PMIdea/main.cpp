#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Idea {
    int no; // idea 编号
    int PMNum; // PM 编号
    int proTime; // 提出时间
    int priority; // 优先级
    int costTime; // 所需时间
    int startTime; // 开始时间

    Idea() {}
};

bool ideaCompare(Idea &idea1, Idea &idea2) {

    // PM排序
    if (idea1.PMNum == idea2.PMNum) {
        if (idea1.priority == idea2.priority) {
            if (idea1.costTime == idea2.costTime) {
                // idea1.costTime == idea2.costTime
                return idea1.proTime < idea2.proTime;
            } else {
                // idea1.costTime != idea2.costTime
                return idea1.costTime < idea2.costTime;
            }
        } else {
            // idea1.priority != idea2.priority
            return idea1.priority > idea2.priority;
        }
    } else {
        //  idea1.PMNum != idea2.PMNum
        // coder 排序
        if (idea1.proTime != idea2.proTime) {
            return idea1.proTime < idea2.proTime;
        } else {
            if (idea1.priority != idea2.priority) {
                return idea1.priority > idea2.priority;
            } else {
                //  idea1.priority == idea2.priority
                if (idea1.costTime != idea2.costTime) {
                    return idea1.costTime < idea2.costTime;
                } else {
                    return idea1.PMNum < idea2.PMNum;
                }
            }
        }
    }
}


class Solution {

public:
    vector<int> getIdeasTime(vector<Idea> &ideas, int PMCount, int coderCount, int ideaCount) {
        vector<int> res = vector<int>(ideaCount, 0);

        // 排序规则，理一理
        // 1. 时间先后
        // 2. 优先级，所需要时间最小，PM编号顺序
        sort(ideas.begin(), ideas.end(), ideaCompare);

        // -1 等待，1 执行中，0 执行完毕
        vector<int> mark = vector<int>(ideaCount, -1);

        int curTime = 1;

        bool isStop;
        bool isBreak;
        while (true) {

            isStop = true;
            isBreak = false;
            for (int i = 0; i < ideaCount; ++i) {
                if (mark[i] == -1 || mark[i] == 1) {
                    isStop = false;

                    if (mark[i] == -1 && coderCount == 0)
                        continue;

                    // 执行中的任务
                    if (mark[i] == 1 && curTime >= (ideas[i].startTime + ideas[i].costTime)) {
                        res[ideas[i].no] = curTime;
                        mark[i] = 0;
                        coderCount += 1;
                        isBreak = true;
                        break;  //  这里不应该直接就选择下一个，还是应该排序顺序来选择。
                    }

                    // 等待中的任务
                    if (mark[i] == -1 && curTime >= ideas[i].proTime) {
                        //  是否能执行
                        if (coderCount > 0) {
                            mark[i] = 1;
                            ideas[i].startTime = curTime;
                            coderCount--;
                            isBreak = true;
                            break;
                        }
                    }
                }
            }

            if (isBreak)
                continue;

            curTime++; //时间流逝

            if (isStop)
                break;
        }

        return res;
    }
};


int main() {

    int PMCount, coderCount, ideaCount;

    cin >> PMCount >> coderCount >> ideaCount;

    vector<Idea> ideas = vector<Idea>(ideaCount, Idea());

    for (int i = 0; i < ideaCount; ++i) {
        cin >> ideas[i].PMNum >> ideas[i].proTime >> ideas[i].priority >> ideas[i].costTime;
        ideas[i].no = i;
        ideas[i].startTime = 0;
    }

    Solution s;
    vector<int> res = s.getIdeasTime(ideas, PMCount, coderCount, ideaCount);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }

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