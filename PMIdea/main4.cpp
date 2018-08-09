#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


struct Idea {
    int no; // idea 编号

    int PMNum; // PM 编号
    int proTime; // 提出时间
    int priority; // 优先级
    int costTime; // 所需时间

};


class Coder {
private:
    int curTime;

public:
    Coder() {
        this->curTime = 0;
    }

    int getCurTime() {
        return curTime;
    }

    int doIdea(vector<vector<Idea>> &PMIdeas, map<int, int> &res) {
        vector<Idea>::iterator foundIdeaIt;
        int foundPMIndex = -1;

        for (int i = 0; i < PMIdeas.size(); ++i) {
            if (PMIdeas[i].size() == 0) {
                continue;
            }

            for (vector<Idea>::iterator it = PMIdeas[i].begin(); it != PMIdeas[i].end(); it++) {
                if (curTime >= it->proTime) {
                    if (foundPMIndex != -1) {
                        if (it->costTime < foundIdeaIt->costTime) {
                            foundIdeaIt = it;
                            foundPMIndex = i;
                        }
                    } else {
                        foundIdeaIt = it;
                        foundPMIndex = i;
                    }
                    // 这里要记得 break ;
                    break;
                }
            }
        }

        if (foundPMIndex != -1) {
            // found an idea
            curTime += foundIdeaIt->costTime;
            res[foundIdeaIt->no] = curTime;
            PMIdeas.at(foundPMIndex).erase(foundIdeaIt);

            return 1; // 完成一个
        } else {
            curTime++;
        }

        return 0;
    }
};


// PM Compare
bool PMCompare(Idea &idea1, Idea &idea2) {
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
}

// coder Compare
bool coderCompare(Coder &c1, Coder &c2) {
    return c1.getCurTime() < c2.getCurTime();
}

class Solution {

public:
    map<int, int> getIdeasTime(vector<vector<Idea>> &PMIdeas, int coderCount, int ideaCount) {
//        vector<int> res = vector<int>(ideaCount);
        map<int, int> res;

        //按PM 排序
        for (int i = 0; i < PMIdeas.size(); ++i) {
            if (PMIdeas[i].size() != 0)
                sort(PMIdeas[i].begin(), PMIdeas[i].end(), PMCompare);
        }

        vector<Coder> coders(coderCount, Coder());

        // coder 排序
        while (ideaCount > 0) { // idea  没有全部完成

            // 选择当前时间点小的程序员
            sort(coders.begin(), coders.end(), coderCompare);

            int finishedCount = coders.begin()->doIdea(PMIdeas, res);
            ideaCount -= finishedCount;
        }

        return res;
    }
};


int main() {

    int PMCount, coderCount, ideaCount;

    cin >> PMCount >> coderCount >> ideaCount;

    // 每一个PM的idea存为一个vector
    vector<vector<Idea>> PMIdeas = vector<vector<Idea>>(PMCount, vector<Idea>());

    for (int i = 0; i < ideaCount; ++i) {
        Idea idea = Idea();
        cin >> idea.PMNum >> idea.proTime >> idea.priority >> idea.costTime;
        idea.no = i;

        PMIdeas.at(idea.PMNum-1).push_back(idea);

    }

    Solution s;
    map<int, int> res = s.getIdeasTime(PMIdeas, coderCount, ideaCount);

    for (auto &item: res) {
        cout << item.second << endl;
    }
//    for (int i = 0; i < res.size(); ++i) {
//        cout << res[i] << endl;
//    }

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