#include<iostream>

using namespace std;

int add_real(int *a, int *b) {
    return a[0] * b[0] - a[1] * b[1];
}

int add_complex(int *a, int *b) {
    return a[0] * b[1] + a[1] * b[0];
}

int main() {
    int arr_a[10][2] = {0};
    int arr_b[10][2] = {0};

    for (int i = 0; i < 5; i++) {
        cin >> arr_a[i][0];
        cin >> arr_a[i][1];
    }

    for (int i = 0; i < 5; i++) {
        cin >> arr_b[i][0];
        cin >> arr_b[i][1];
    }

    for (int i = 0; i <= 8; i++) {
        int real = 0;
        int imag = 0;
        for (int j = 0; j <= i; j++) {
            real += add_real(arr_a[j], arr_b[i - j]);
            imag += add_complex(arr_a[j], arr_b[i - j]);
        }

        cout << real << endl;
        cout << imag << endl;

    }

    return 0;
}