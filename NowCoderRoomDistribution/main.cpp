#include <iostream>
#include <vector>


using namespace std;


bool checkRooms(vector<int>tmpNums, vector<int>nums, int totalNum, int i) {
    // 检查和
    int tmpTotal = 0;
    for (int k = 0; k < tmpNums.size(); ++k) {
        tmpTotal += tmpNums[k];
    }
    if (tmpTotal != totalNum)
        return false;

    // 检查移动
    int numX = tmpNums[i];
    tmpNums[i] = 0;

    int nextDisRoom = i;
    while (numX > 0) {
        nextDisRoom = (nextDisRoom + 1) == nums.size() ? 0 : (nextDisRoom + 1);
        tmpNums[nextDisRoom] ++ ;
        numX -- ;
    }

    for (int j = 0; j < nums.size(); ++j) {
        if (tmpNums[j] != nums[j])
            return false;
    }

    return true;

}

vector<int> searchRoom(vector<int> &nums, int totalNum, int n, int x) {


    int left;
    int right;
    for (int i = 0; i < n; ++i) {
        // 找到一个极小值，认为是从该房间（i）开始重新分配的
        left = (i - 1) == -1 ? (n - 1) : (i - 1);
        right = (i + 1) == n ? 0 : (i + 1);
        if (nums[i] <= nums[left] && nums[i] <= nums[right]) {
            vector<int> tmpNums = nums;
            // 从 x 逆推分配过程
            int lastDisRoom = x;
            tmpNums[i] = 0; // 设置为 0
            while (tmpNums[i] <= totalNum) {

                // 如果 i != lastDisRoom,则  x ->  lastDisRoom 可以算一次合法的移动，如果 x == lastDisRoom，n次算一次移动
                if (i != lastDisRoom) {
                    while (lastDisRoom != i) {
                        tmpNums[lastDisRoom] -- ;
                        tmpNums[i] ++ ;
                        lastDisRoom = (lastDisRoom - 1) == -1 ? (n - 1) : (lastDisRoom - 1);

                    }
                } else {
                    tmpNums[i] += n;
                    for (int j = 0; j < n; ++j) {
                        if (j != i && tmpNums[j] > 0)
                            tmpNums[j] --;
                    }
                }

                // 找到一个组合，判断是否满足题意条件
                if (checkRooms(tmpNums, nums, totalNum, i))
                    return tmpNums;
            }

        }
    }

    return nums;
}


int main() {

    int n; // 房间数
    int x; // 最后一个人被分配的房间

    cin >> n >> x;

    x --; // 从0号房间开始

    vector<int> nums = vector<int>(n);
    int totalNum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        totalNum += nums[i];
    }

    vector<int> res = searchRoom(nums, totalNum, n, x);

    for (int i = 0; i < n; ++i) {
        if (i != (n - 1))
            cout << res[i] << " ";
        else
            cout << res[i] << endl;
    }

    return 0;
}

/*

5 4
3 1 3 1 3

3 1
6 5 1

10 5
3 3 3 3 4 3 3 3 3 3


0 0 0 31 0 0 0 0 0 0
 */