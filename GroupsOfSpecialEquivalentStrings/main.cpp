#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string> &A) {
        int res = 0;
        int n = A.size();
        if (n == 1)
            return 1;

        set<string> filterSet;

        for (int i = 0; i < n; ++i) {
            // 没有存在
            string tmpStr = A[i];
            bool isExists = false;
            if (filterSet.find(tmpStr) == filterSet.end()) {
                // 尝试交换是否存在
                for (int j = 0; j < tmpStr.size(); ++j) {
                    string swapStr = tmpStr;
                    for (int k = 0; k < tmpStr.size(); ++k) {
                        if (j != k && j % 2 == k % 2) {
                            swap(swapStr[j], swapStr[k]);
                            if (filterSet.find(tmpStr) != filterSet.end()) {
                                isExists = true;
//                                break;
                            } else {
                                // 加入filterSet，因为这个可以同个 A[i]变化得到
                                filterSet.insert(swapStr);
                            }

                        }
                    }
                }

                if (!isExists) {
                    filterSet.insert(tmpStr);
                    res++;
                }

            }
        }
        return res;

    }
};

int main() {
    Solution s;

//    vector<string> A = {"couxuxaubw", "zsptcwcghr", "kkntvvhbcc", "nkhtcvvckb", "crcwhspgzt"};
    vector<string> A = {"kkntvvhbcc", "nkhtcvvckb"};
    cout << s.numSpecialEquivGroups(A) << endl;
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}