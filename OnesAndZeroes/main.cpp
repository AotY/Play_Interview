#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;


//bool compare(string s1, string s2) {
//    if (s1.size() != s2.size())
//        return s1.size() < s2.size();
//    else {
//        int zeroCount1 = 0, oneCount1 = 0;
//        for (int i = 0; i < s1.size(); ++i) {
//            int num = s1[i] - '0';
//            if (num == 1)
//                oneCount1++;
//            else
//                zeroCount1++;
//        }
//
//        int zeroCount2 = 0, oneCount2 = 0;
//        for (int i = 0; i < s2.size(); ++i) {
//            int num = s2[i] - '0';
//            if (num == 1)
//                oneCount2++;
//            else
//                zeroCount2++;
//        }
//        return max(zeroCount1, oneCount1) < max(zeroCount2, oneCount2);
//    }
//}

bool moreZero;

bool compare(string s1, string s2) {

    int zeroCount1 = 0, oneCount1 = 0;
    for (int i = 0; i < s1.size(); ++i) {
        int num = s1[i] - '0';
        if (num == 1)
            oneCount1++;
        else
            zeroCount1++;
    }
    int sub1;
    if (moreZero)
        sub1 = zeroCount1 - oneCount1;
    else
        sub1 = oneCount1 - zeroCount1;

    int zeroCount2 = 0, oneCount2 = 0;
    for (int i = 0; i < s2.size(); ++i) {
        int num = s2[i] - '0';
        if (num == 1)
            oneCount2++;
        else
            zeroCount2++;
    }

    int sub2;
    if (moreZero)
        sub2 = zeroCount2 - oneCount2;
    else
        sub2 = oneCount2 - zeroCount2;

    // "1100","100000","011111"
    if (moreZero) {
        if (zeroCount1 == 0)
            return false;

        if (zeroCount2 == 0)
            return true;

        if (s1.size() == s2.size()) {
            return zeroCount1 > zeroCount2;
        } else {
            if (zeroCount1 == zeroCount2)
                return oneCount1 < oneCount2;
            else if (oneCount1 == oneCount2)
                return zeroCount1 < zeroCount2;
            else {
                if (sub1 <= 0)
                    return false;

                if (sub2 <= 0)
                    return true;

                return sub1 < sub2;
            }
        }

    } else {
        if (oneCount1 == 0)
            return false;

        if (oneCount2 == 0)
            return true;

        if (s1.size() == s2.size()) {
            return oneCount1 > oneCount2;
        } else {
            if (oneCount1 == oneCount2)
                return zeroCount1 < zeroCount2;
            else if (zeroCount1 == zeroCount2)
                return oneCount1 < oneCount2;
            else {
                if (sub1 <= 0)
                    return false;

                if (sub2 <= 0)
                    return true;

                return sub1 < sub2;
            }
        }
    }
}

class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        // m - zero count
        // n - one count

        int result = 0;

        if (m >= n) {
            // sort by zero
            moreZero = true;
            sort(strs.begin(), strs.end(), compare);
        } else {
            moreZero = false;
            // sort by one
            sort(strs.begin(), strs.end(), compare);
        }

        for (int i = 0; i < strs.size(); ++i) {
            int zeroCount = 0, oneCount = 0;
            for (int j = 0; j < strs[i].size(); ++j) {
                int num = strs[i][j] - '0';
                if (num == 1)
                    oneCount++;
                else
                    zeroCount++;
            }
            if (m >= zeroCount && n >= oneCount) {
                m -= zeroCount;
                n -= oneCount;
                result++;
            }

            if (m == 0 && n == 0)
                break;
        }
        return result;
    }
};


int main() {
    vector<string> strs = {"011111","001","001"}; //
    Solution s;
    cout << s.findMaxForm(strs, 4, 5) << endl;

//    std::cout << "Hello, World!" << std::endl;
    return 0;
}