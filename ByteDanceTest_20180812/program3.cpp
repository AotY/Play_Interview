#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool equal(int i, int j, vector<vector<int>> vec) {
    bool result = false;
    int sum = 0;
    for (int t = i; t <= j; t++) {
        sum += vec[t][0];
    }
    int sum1 = 0;

    for (int t1 = i; t1 < j; t1++) {
        sum1 = vec[t1][0];
        for (int t2 = t1 + 1; t2 <= j; t2++) {
            sum1 += vec[t2][0];
            int sum2 = sum - sum1;
            if (sum2 == sum1)
                return true;
        }
    }
    return result;
}

void bubble_sort(vector<vector<int>> &arr, int len) {
    int i, j;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j][1] > arr[j + 1][1])
                swap(arr[j], arr[j + 1]);
}

int getResult() {
    int num;
    cin >> num;
    if (num < 1)
        return 0;
    vector<vector<int>> vec;
    for (int i = 0; i < num; i++) {
        int x, y = 0;
        cin >> x;
        cin >> y;
        vector<int> temp(2, 0);
        temp[0] = x;
        temp[1] = y;
        vec.push_back(temp);
    }
    bubble_sort(vec, num);
    int max = 0;
    int tempsum = 0;
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            tempsum = vec[i][1] + vec[j][1];
            if (vec[i][0] == vec[j][0] && tempsum > max)
                max = tempsum;
        }
    }
    for (int i = 0; i < num - 1; i++) {
        tempsum = vec[i][1];
        for (int j = i + 1; j < num; j++) {
            tempsum += vec[j][1];
            if (equal(i, j, vec) && tempsum >= max) {
                max = tempsum;
            }
        }
    }
    return max;

}

int main() {
    int max = getResult();
    cout << max << endl;
    system("pause");
    return 0;
}