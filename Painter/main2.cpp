#include<stdio.h>
#include<string.h>
#include<limits.h>

int n;
char src[18][18], temp1[18][18];
int dx[4] = {-1, 0, 1, 0};//上右下左
int dy[4] = {0, 1, 0, -1};

int GetBit(int c, int i)//取c的第i位。i从0开始。
{ return (c >> i) & 1; }

void Flip(int i, int j)//将src[i][j]及其周围元素取反
{
    int k, x, y;
    src[i][j] = src[i][j] == 'w' ? 'y' : 'w';
    for (k = 0; k < 4; k++) {
        x = i + dx[k];
        y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < n) {
            src[x][y] = src[x][y] == 'w' ? 'y' : 'w';
        }
    }
}

int main(int argc, char *argv[]) {
    int i, j, k, t;
    char str[20];
    int count, min = INT_MAX;

    min = INT_MAX;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", str);
        for (j = 0; j < n; j++) {
            temp1[i][j] = src[i][j] = str[j];
        }
    }

    t = (1 << n);//第0行总共有2^n种不同的涂法
    for (i = 0; i <= t; i++)//枚举所有涂法，对每一种涂法都统计该方案需要涂的数量并检验该方案能否全变为y。
    {
        memcpy(src, temp1, sizeof(src));

        count = 0;

        for (j = 0; j < n; j++)//根据当前方案i各个比特的值去涂第0行
        {
            if (GetBit(i, j) == 1)//获取i的第j个比特。若为1，则需要涂（0，j）位置
            {
                Flip(0, j);
                count++;
            }
        }
        for (k = 1; k < n; k++)//扫描除了第0行以外的所有行
        {
            for (j = 0; j < n; j++) {
                if (src[k - 1][j] == 'w') {
                    Flip(k, j);
                    count++;
                }
            }
        }
        for (j = 0; j < n; j++)//扫描最后一行检查是否有未变为y的单元
        {
            if (src[n - 1][j] == 'w')
                break;
        }
        if (j == n && count < min)
            min = count;
    }
    if (min == INT_MAX)
        printf("inf\n");
    else printf("%d\n", min);
    return 0;
}