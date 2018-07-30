## 474. Ones and Zeroes

https://leetcode.com/problems/ones-and-zeroes/description/

```
Input: Array = { "10", "0001", "111001", "1", "0" }, m = 5, n = 3
Output: 4

Input: Array = {"10", "0", "1"}, m = 1, n = 1
Output: 2
```

Explanation: 
This are totally 4 strings can be formed by the using of 5 0s and 3 1s, 
which are “10,”0001”,”1”,”0”


> 这个题目用贪心的策略不能保证结果正确
> 用搜索树的方法就是在求一个递归树的最大深度
