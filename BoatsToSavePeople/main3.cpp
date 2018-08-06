#include <iostream>
#include <vector>

using namespace std;


// 贪心思想 , 时间超时

static const auto _____ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {

private:
    int binarySearch(vector<int> &people, int target, int left, int right) {
//        int left = 0;
//        int right = people.size() - 1;

        while (left <= right) {
            int mid = (left + right) >> 1;

            if (people[mid] == target)
                return mid;
            else if (people[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return right;
    }

public:
    int numRescueBoats(vector<int> &people, int limit) {
        int n = people.size();
        if (n == 1)
            return 1;

        sort(people.begin(), people.end()); // , std::greater<int>()

        int res = 0;

        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int cur = people[right];

            if (cur == limit) {
                res++;
                right--;
            } else {
                // 寻找最合适的搭档
                int sub = limit - cur;

                int pos = binarySearch(people, sub, left, right);

                if (pos >= left && sub >= people[pos]) {
                    for (int i = pos; i > left; i--) {
                        people[i] = people[i - 1];
                    }

                    people[left++] = -1;
                }
                right--;
                res++;
            }
        }

        return res;
    }
};

int main() {
    vector<int> people = {1, 5, 3, 5};
    Solution s;
    cout << s.numRescueBoats(people, 7) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}