#include <iostream>
#include <vector>

using namespace std;

int yoMeiDu(vector<int> &nums) {
    int res = 0;
    // 第一面
    res += nums[0] * nums[1] * nums[2] * nums[3];

    // 第二面
    res += nums[4] * nums[5] * nums[10] * nums[11];

    // 第三面
    res += nums[6] * nums[7] * nums[12] * nums[13];

    // 第四面
    res += nums[8] * nums[9] * nums[14] * nums[15];

    // 第五面
    res += nums[16] * nums[17] * nums[18] * nums[19];

    // 第六面
    res += nums[20] * nums[21] * nums[22] * nums[23];

    return res;
}





int main() {

    vector<int> nums = vector<int>(24);
    for (int i = 0; i < 24; ++i) {
        cin >> nums[i];
    }

    int maxYoMeiDu = yoMeiDu(nums);

    // 不超过5次
    for (int i = 0; i < 5; ++i) {
        // 六种操作
        for (int j = 0; j < 6; ++j) {
            // 选择不同的面

            for (int k = 0; k < 4; ++k) {
                // 每次可以顺时针或者 逆时针

                for (int l = 0; l < 2; ++l) {

                }
            }
        }
    }



    cout << maxYoMeiDu << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}