#include <iostream>
#include <vector>

using namespace std;


// 删除数组，返回最后一个被删除的元素
int main() {

    int N;
    cin >> N;

    vector<bool> nums = vector<bool>(N, true);

    int index = -1;
    int delIndex = -1;
    int curSize = N;
    while (curSize > 1) {
        index = ++index % N; // 循环
        while (!nums[index])
            index = ++index % N;
        if (nums[index]) {
            delIndex++;
            if (delIndex == 2) {
                nums[index] = false;
                delIndex = -1;
                curSize--;
            }
        }
    }

    //
    for (int i = 0; i < N; ++i) {
        if (nums[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
