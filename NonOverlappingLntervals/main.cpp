#include <iostream>
#include <vector>
using namespace std;



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
    if (interval1.end == interval2.end)
        return interval1.start < interval2.start;
    else
        return interval1.end < interval2.end;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        // 按 end 排序，使用贪心思想
        int n = intervals.size();
        if (n == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), intervalCompare);

        int res = 1;
        int preIndex = 0;

        for (int i = 1; i < n; ++i) {
            if (intervals[i].start >= intervals[preIndex].end) {
                res ++ ;
                preIndex = i;
            }
        }

        return n - res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}