#include <iostream>
#include <vector>

using namespace std;


int main() {

    int n;

    int m;

    // 用户个数
    cin >> n;

    vector<int> nums = vector<int>(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &nums[i]);
    }

    // 查询个数
    cin >> m;
    int l, r, k;
    for (int j = 0; j < m; ++j) {
        scanf("%d %d %d", &l, &r, &k);

        int res = 0;

        for (int i = l; i <= r; ++i) {
            if (nums[i] == k)
                res++;
        }
        cout << res << endl;
    }


//    std::cout << "Hello, World!" << std::endl;
    return 0;
}