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

//小于时返回true
static bool compare(Interval &lhs, Interval &rhs) {
    return (lhs.start == rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
}


class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;

        if (intervals.size() == 0) {
            return res;
        }

        sort(intervals.begin(), intervals.end(), compare);

        for (int i = 0; i < intervals.size(); i++) {
            int size = res.size();

            if (size > 0 && res[size - 1].end >= intervals[i].start) {
                res[size - 1].end = max(res[size - 1].end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);

            }
        }
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