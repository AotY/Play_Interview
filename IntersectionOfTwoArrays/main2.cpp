#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> ve;
        set<int> numset;

        for (int i = 0; i < nums1.size(); i++)
            numset.insert(nums1[i]);

        for (int i = 0; i < nums2.size(); i++) {
            if (numset.find(nums2[i]) != numset.end()) {
                ve.push_back(nums2[i]);
                numset.erase(nums2[i]);
            }
        }

        return ve;
    }
};

int main() {


    return 0;
}