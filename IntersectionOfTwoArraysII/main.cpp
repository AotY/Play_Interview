#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;

        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 == 0 || n2 == 0)
            return res;


        unordered_map<int, int> countMap;
        for (int i = 0; i < n1; ++i) {
            countMap[nums1[i]]++;
        }

        for (int j = 0; j < n2; ++j) {
            if (countMap[nums2[j]] > 0) {
                res.push_back(nums2[j]);

                countMap[nums2[j]]--;

            }
        }


        return res;

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}