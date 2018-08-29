## 求排列的逆序数(总时间限制:1000ms、内存限制:65536kB)

【问题描述】：在Internet上的搜索引擎经常需要对信息进行比较，比如可以通过某个人对一些事物的排

名来估计他（或她）对各种不同信息的兴趣，从而实现个性化的服务。 
对于不同的排名结果可以用逆序来评价它们之间的差异。考虑1,2,…,n的排列i_1，i_2，…，i_n，
如果其中 存在j,k，满足 j < k 且 i_j > i_k， 那么就称(i_j,i_k)是这个排列的一个逆序。

一个排列含有逆序的个数称为这个排列的逆序数。
例如排列 263451 含有8个逆序(2,1),(6,3),(6,4),(6,5), (6,1),(3,1),(4,1),(5,1)，
因此该排列的逆序数就是8。
显然，由1,2,…,n 构成的所有 n! 个排列中，最小的逆序数是 0，
对应的排列就是1,2,…,n；
最大的逆序数是n(n‑1)/2，对应的排列就是n, (n‑1),…,2,1。
逆序数越大的排列与原始排列的差异度就越大。 

现给定1,2,…,n的一个排列，求它的逆序数。

【输入说明】： 第一行是一个整数n，表示该排列有n个数（n <= 100000)。 
第二行是n个不同的正整数，之间以空格隔开，表示该排列。

【输出说明】：输出该排列的逆序数。 【样例输入】：

6
2 6 3 4 5 1

【样例输出】：
8