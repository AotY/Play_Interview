## 230. Kth Smallest Element in a BST
> Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
  
> Note: 
> You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

```html

binary search trees (BST), sometimes called ordered or sorted binary trees, 
are a particular type of container: data structures that store "items" 
(such as numbers, names etc.) in memory. They allow fast lookup, 
addition and removal of items, and can be used to implement either dynamic sets of 
items, or lookup tables that allow finding an item by its key 
(e.g., finding the phone number of a person by name).
```


```html
Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
```

```html
Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
```