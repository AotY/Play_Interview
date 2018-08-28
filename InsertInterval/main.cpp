#include <iostream>
#include <vector>

using namespace std;


/**
 Definition for an interval.
 */

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // 找到位置插入区间，检查是否需要合并
        vector<Interval> results;
        int n = intervals.size();
        if (n == 0) {
            results.push_back(newInterval);
            return results;
        }

        // 先插入
        vector<Interval> newIntervals;
        bool isInsert = false;
        for (int i = 0; i < n; ++i) {
            if (!isInsert && intervals[i].start > newInterval.start) {
                newIntervals.push_back(newInterval);
                isInsert = true;
            }
            newIntervals.push_back(intervals[i]);
        }

        // 防止没有被插入
        if (!isInsert)
            newIntervals.push_back(newInterval);


        for (int i = 0; i < newIntervals.size(); ++i) {
            // 如果当前有区间
            int curSize = results.size();
            if (curSize > 0 && results[curSize - 1].end >= newIntervals[i].start) {
                // 更新
                results[curSize - 1].end = max(results[curSize - 1].end, newIntervals[i].end);
            } else {
                results.push_back(newIntervals[i]);
            }
        }

        return results;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}