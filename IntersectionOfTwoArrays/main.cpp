#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        set<int> resultsSet;

        if (n1 > n2) {
            set<int> filterSet = set<int>(nums1.begin(), nums1.end());

            for (int i = 0; i < n2; ++i) {
                if (filterSet.find(nums2[i]) != filterSet.end())
                    resultsSet.insert(nums2[i]);
            }
        } else {
            set<int> filterSet = set<int>(nums2.begin(), nums2.end());

            for (int i = 0; i < n1; ++i) {
                if (filterSet.find(nums1[i]) != filterSet.end())
                    resultsSet.insert(nums1[i]);
            }
        }

        vector<int> results(resultsSet.begin(), resultsSet.end());

        return results;
    }
};

int main() {


    return 0;
}