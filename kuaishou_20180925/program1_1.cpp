#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> getNums(string &str) {
    int len = str.size();
    vector<int> nums;
    for (int i = 0; i < 6; ++i) {
        int num = str[len - 1 - i] - '0';
        nums.push_back(num);
    }
    return nums;

}
int main() {
    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {
       string str;
       cin >> str;

       vector<int> nums = getNums(str);

       for (int i = nums.size() - 1; i >= 0 ; i--){
            cout << nums[i];
       }
       cout << endl;
    }
}
