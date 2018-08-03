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

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const Interval &a, const Interval &b) -> bool { return a.start < b.start; }
        );

        vector<Interval> result;
        int i = 0;
        while (i < intervals.size()) {
            int start = intervals[i].start;
            int end = intervals[i].end;
            int n = 1;
            int cnt = 1;
            while (end >= intervals[i + n].start) {
                if (i + n >= intervals.size()) {
                    break;
                }
                end = max(intervals[i + n].end, end);
                ++n;
                ++cnt;
            }
            i += cnt;
            Interval temp(start, end);
            result.push_back(temp);
        }
        return result;
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