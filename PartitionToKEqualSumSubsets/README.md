## 698. Partition to K Equal Sum Subsets

> Given an array of integers nums and a positive integer k, 
> find whether it's possible to divide this array into k non-empty subsets 
> whose sums are all equal.


```html

Example 1:
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) 
with equal sums.

Note:

1 <= k <= len(nums) <= 16.
0 < nums[i] < 10000.

```

Tips
> We can figure out what target each subset must sum to. Then, 
> let's recursively search, where at each call to our function, 
> we choose which of k subsets the next value will join.








