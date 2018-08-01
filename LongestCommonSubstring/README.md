##  Longest common substring problem
https://www.wikiwand.com/en/Longest_common_substring_problem

> In computer science, the longest common substring problem is to find the longest 
> string (or strings) that is a substring (or are substrings) of two or more strings.
  

```html

Given two strings, S of length m and T of length n, 
find the longest strings which are substrings of both S and T.

A generalization is the k-common substring problem. Given the set of 
strings S=\{S_{1},...,S_{K}\}, where |S_{i}|=n_{i} and \Sigma n_{i}=N. 
Find for each 2\leq k\leq K, the longest strings which occur as substrings of at least k strings.


```

### Suffix tree

### Dynamic programming
if s1[m] == s2[m]:
    Lcs(m, n) = 1 + lcs(m-1, n-1)
else:
    Lcs(m, n) = max(lcs(m-1, n), Lcs(m, n-1))