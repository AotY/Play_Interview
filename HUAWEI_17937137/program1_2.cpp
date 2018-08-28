#include <iostream>
#include <vector>

using namespace std;


// 删除数组，返回最后一个被删除的元素
int main() {

    int N;
    cin >> N;

    vector<int> nums = vector<int>(N);

    for (int i = 0; i < N; ++i) {
        nums[i] = i;
    }

    int delIndex = 0;
    while (nums.size() > 1) {

        delIndex = (delIndex + 2) % nums.size();

        nums.erase(nums.begin() + delIndex);
    }

    cout << nums[0] << endl;
    return 0;
}
