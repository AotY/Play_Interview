#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 记忆化搜索方式，超时
class Solution {


private:

    map<int, bool> memoMap;


    bool isUglyNumber(int num) {
        if (num == 1)
            return true;

        if (memoMap.find(num) != memoMap.end())
            return memoMap[num];

        bool res = false;

        if (num % 2 == 0)
            res = res || isUglyNumber(num / 2);

        if (num % 3 == 0)
            res = res || isUglyNumber(num / 3);

        if (num % 5 == 0)
            res = res || isUglyNumber(num / 5);

        memoMap.insert(make_pair(num, res));
        return res;
    }
public:
    int nthUglyNumber(int n) {
        if (n == 1)
            return 1;

        // n-th
        int searchNum = 1;

        while (true) {

            if (isUglyNumber(searchNum)) {
                n -- ;
            }

            if (n == 0)
                break;

            searchNum ++;
        }

        return searchNum;
    }
};

int main() {

    Solution s;
    cout << s.nthUglyNumber(293) << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}