#include <iostream>
#include <vector>

using namespace std;


// 著名的主元素问题
// 1. 排序
class Solution {
public:
    int majorityElement(vector<int> &nums) {


        sort(nums.begin(), nums.end());


        return nums[(nums.size() - 1) / 2];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}