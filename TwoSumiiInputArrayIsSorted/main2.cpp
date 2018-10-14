#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int n=numbers.size();
            vector<int> result;
            int i=0; int j=n-1;
            for (int k=0;k<n;k++){
                if(numbers[i]+numbers[j]==target){
                    result.push_back(i+1);
                    result.push_back(j+1);
                    break;
                }
                else if(numbers[i]+numbers[j]>target){
                    j--;
                }
                else
                    i++;
            }

            return result;
        }
};


int main() {
    Solution s;

    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> res = s.twoSum(nums, target);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << ", ";
    }

    cout << endl;

    return 0;
}
