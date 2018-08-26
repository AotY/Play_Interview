#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


bool countMapCompare(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second > p2.second;
}

class FreqStack {
private:
    vector<int> nums;
    int top;
//    // 第一次出现的位置
//    vector<pair<int, int>> countPairs;
    map<int, vector<int>> positionsMap; // 出现的所有位置
public:
    FreqStack() {
        top = 0;
    }

    void push(int x) {
        nums.push_back(x);

        // 位置，之前不存在
        if (positionsMap.find(x) == positionsMap.end()) {
            vector<int> positions;
            positions.push_back(top);
            positionsMap[x] = positions;
        } else {
            // 存在
            positionsMap[x].push_back(top);
        }

        top++;

    }

    int pop() {
        //获取频率最大的元素
        if (top == 0)
            return -1;

        //  获取频率最大元素第一次出现的位置

        int maxFre = 0;
        int firstIndex = top + 1;
        int popKey;
        vector<int> popPositions;
        for (auto pm: positionsMap) {
            if (pm.second.size() >= maxFre && pm.second[0] < firstIndex) {
                maxFre = pm.second.size();
                firstIndex = pm.second[0];

                popKey = pm.first;
                popPositions = pm.second;
            }
        }

        popPositions.erase(popPositions.begin());
        if (popPositions.size() == 0)
            positionsMap.erase(popKey);
        else
            positionsMap[popKey] = popPositions;

        //
        vector<int>::iterator popIt = (nums.begin() + firstIndex);
        int res = *popIt;
        nums.erase(popIt);
        top--;
        return res;
    }

    ~FreqStack() {}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */


int main() {

    FreqStack obj;

    obj.push(5);
    obj.push(3);

    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}