#include <iostream>
#include <vector>
#include <string>

using namespace std;


int N, P, H, W;

bool isValide(vector<int> &paragraphs, int sum, int mid) {
    // row
    int rowSize = H / mid;

    // column
    int columnSize = W / mid;

    int totalRows = rowSize * P;

    int requireRows = 0;

    for (int i = 0; i < paragraphs.size(); i++) {
        if (paragraphs[i] % columnSize == 0)
            requireRows += paragraphs[i] / columnSize;
        else
            requireRows += paragraphs[i] / columnSize + 1;

    }

    if (totalRows >= requireRows)
        return true;

    return false;

}

int searchSolution(vector<int> &paragraphs, int sum, int left, int right) {
    int res = 1;
    while (left < right) {

        int mid = left + (right - left) / 2;

        if (isValide(paragraphs, sum, mid)) {
            res = max(res, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return res;
}

int main() {
    cin >> N >> P >> H >> W;

    vector<int> paragraphs = vector<int>(N);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> paragraphs[i];
        sum += paragraphs[i];
    }
    // binary search
    int left = 1;
    int right = min(H, W);
    // int right = max(H, W);

    int res = searchSolution(paragraphs, sum, left, right);
    cout << res << endl;

}
