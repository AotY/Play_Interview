## 371. Sum of Two Integers

```
Calculate the sum of two integers a and b, 
but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.

Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.

```

```html
那么加法运算可以这样实现：

1）先不考虑进位，按位计算各位累加（用异或实现），得到值sum；

2）然后在考虑进位，并将进位的值左移，得值b，若b为0，则a就是加法运算的结果，若b不为0，则a+b即得结果（递归调用该函数）。
```

```c
class Solution {
public:
    int getSum(int a, int b) {
                if(b == 0) return a;        // when carry is zero, return
        int sum = a ^ b;        // calculate sum without carry
        int carry = (a & b) << 1;       // calculate carry
        return getSum(sum, carry);
    }
};

```