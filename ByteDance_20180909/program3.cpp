#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

// 考察 并查集

int flag = 0;
int findRoot(vector<int> &users, int user) {

    int keepUser = user;
    while (user != users[user]) {
        user = users[user];
        if (user == keepUser) {
            return users[keepUser];
        }

    }

    return user;
}


void mergeUsers(vector<int> &users, int user1, int user2) {
    int root1 = findRoot(users, user1);
    int root2 = findRoot(users, user2);

    if (root1 != root2) {
        users[user1] = user2;
    }
    if  (root1  == root2 || root2 != user2){
        flag = 1;
    }
    users[user1] = user2;
    return;
}

int main() {

    int N; //  用户数
    int M; //  关系对

    cin >> N;
    cin >> M;

    if ( N == 1) {
        cout << 1 << endl;
        exit(0);
    }


    vector<int> users = vector<int>(N + 1);
    for (int i = 1; i <= N; ++i) {
        users[i] = i;
    }

    int user1;
    int user2;
    for (int i = 0; i < M; ++i) {
        cin >> user1;
        cin >> user2;

        // merge
        mergeUsers(users, user1, user2);
    }


    // find hot user

    int res = 0;
    for (int i = 1; i <= N; ++i) {
        if (users[i] == i) {
            // 可能是红人
            bool flag = true;
            for (int j = 1; j <= N; ++j) {
                if (findRoot(users, j) != i) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res ++;
        }
    }

    cout << res << endl;


    return 0;
}

/**

3
3
1 2 2 1 2 3

4
3
2 1 3 1 4 1
 */

