#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    int likesQuery(vector<int> &nums, int l, int r, int k) {
        int res = 0;

        for (int i = l; i <= r; ++i) {
            if (nums[i] == k)
                res ++ ;
        }

        return res;
    }

};

int main() {

    int n;

    int m;

    // 用户个数
    cin >> n;

    vector<int> nums = vector<int>(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &nums[i]);
    }

    Solution s;

    // 查询个数
    cin >> m ;
    int l, r, k;
    for (int j = 0; j < m; ++j) {
        scanf("%d %d %d", &l, &r, &k);
        cout << s.likesQuery(nums, l, r, k) << endl;
    }


//    std::cout << "Hello, World!" << std::endl;
    return 0;
}