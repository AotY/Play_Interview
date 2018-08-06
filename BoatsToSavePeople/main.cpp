#include <iostream>
#include <vector>

using namespace std;


// 贪心思想

class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit) {
        int n = people.size();
        if (n == 1)
            return 1;

        sort(people.begin(), people.end(), std::greater<int>());

        vector<bool> mark = vector<bool>(n, false);

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (!mark[i]) {
                if (people[i] == limit) {
                    res++;
                    mark[i] = true;
                } else if (people[i] < limit) {
                    // 寻找最合适的搭档
                    int index = i + 1;
                    int sub = limit - people[i];

                    while (index < n && (mark[index] || people[index] > sub))
                        index++;

                    mark[i] = true;
                    if (index < n)
                        mark[index] = true;
                    res++;
                }
            }
        }


        return res;
    }
};

int main() {
    vector<int> people = {8, 3, 8, 3, 10, 2, 9, 1, 3, 6, 6, 4, 2, 3, 3, 8, 10, 6, 1, 8, 4, 4, 6, 3, 10, 2, 5, 3, 6, 6,
                          7, 6, 5, 7, 5, 8, 8, 3, 4, 7, 2, 7, 4, 6, 2, 7, 4, 5, 5, 5, 7, 4, 7, 1, 4, 8, 1, 7, 1, 5, 9,
                          1, 6, 1, 9, 7, 8, 7, 1, 1, 7, 10, 9, 7, 8, 3, 8, 3, 2, 5, 4, 2, 5, 9, 5, 5, 8, 6, 2, 10, 5, 8,
                          4, 9, 4, 3, 2, 10, 6, 1};
    Solution s;
    cout << s.numRescueBoats(people, 10) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}