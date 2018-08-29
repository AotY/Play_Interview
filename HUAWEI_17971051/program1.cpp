#include <iostream>
#include <vector>

using namespace std;

// 最高分是多少

/*
 *  输入包括多组测试数据。
    每组输入第一行是两个正整数N和M（0 < N <= 30000,0 < M < 5000）,分别代表学生的数目和操作的数目。
    学生ID编号从1编到N。
    第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩
    接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），和两个正整数A,B。
    当C为'Q'的时候, 表示这是一条询问操作，他询问ID从A到B（包括A, B）的学生当中，成绩最高的是多少
    当C为‘U’的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。

    对于每一次询问操作，在一行里面输出最高成绩.
 */


int main() {

    int N, M;

    cin >> N >> M;

    vector<int> students = vector<int>(N);
    for (int i = 0; i < N; ++i) {
        cin >> students[i];
    }


    char command;
    int A, B;
    for (int j = 0; j < M; ++j) {
        cin >> command;

        cin >> A >> B;

        if (command == 'Q') { // 查询
            int maxScore = students[A - 1];
            for (int i = A; i < B; ++i) {
                maxScore = max(maxScore, students[i]);
            }
            cout << maxScore << endl;
        } else if (command == 'U') { // 修改

            students[A - 1] = B;
        }
    }


    return 0;
}



/*

输入例子1:
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5

输出例子1:
5
6
5
9

 */