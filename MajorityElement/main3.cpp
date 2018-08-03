#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


// 著名的主元素问题
// 3. 概率尝试，不可行
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        srand(time(NULL));

        int n = nums.size();
        bool *mark = new bool[n];
        int res;
        for (int i = 0; i < n / 2 + 1; ++i) {

            int index = (rand() % n);
            while (mark[index]) {
                index = (rand() % n);
            }

            mark[index] = true;
            res = nums[index];
        }

        delete[] mark;

        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 3, 4, 1, 1, 1, 4, 3, 1};
    cout << s.majorityElement(nums) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}