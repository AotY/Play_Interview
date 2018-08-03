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


static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


bool intervalCompare(const Interval &interval1, const Interval &interval2) {
    if (interval1.start == interval2.start)
        return interval1.end < interval2.end;
    else
        return interval1.start < interval2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        int n = intervals.size();
        if (n == 0)
            return res;

        sort(intervals.begin(), intervals.end(), intervalCompare);

        Interval mergeInterval = intervals[0];
        for (int i = 1; i < n; i++) {
            Interval curInterval = intervals[i];

            if (mergeInterval.start == curInterval.end) {
                mergeInterval.end = curInterval.end;
            } else if (mergeInterval.end >= curInterval.start) {
                if (mergeInterval.end < curInterval.end)
                    mergeInterval.end = curInterval.end;
            } else if (mergeInterval.end <= curInterval.start) {
                res.push_back(mergeInterval);
                mergeInterval = intervals[i];
            } else if (mergeInterval.end >= curInterval.end) {
                continue;
            }
        }
        res.push_back(mergeInterval);
        return res;
    }
};


int main() {
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 4));
    intervals.push_back(Interval(4, 5));
//    intervals.push_back(Interval(8, 10));
//    intervals.push_back(Interval(15, 18));

    Solution s;
    vector<Interval> res = s.merge(intervals);
    for (int i = 0; i < res.size(); ++i) {
        cout << "[ " << res[i].start << ", " << res[i].end << " ]" << endl;
    }
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}