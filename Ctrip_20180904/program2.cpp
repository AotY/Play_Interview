#include <iostream>

using namespace std;

int main() {

    long long int num;
    cin >> num;

    int result = 0;
    for (int i = 0; i < 64; ++i) {
        int numI = ( num >> i ) & 1;
        if (numI == 1)
            result ++;

    }

    cout << result << endl;

    return 0;
}