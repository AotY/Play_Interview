'''
后向算法

1. 初始化后向概率

2. 后向概率的递推公式

3. 初始概率

'''
import numpy as np

# 状态转移概率矩阵 (集合0， 1， 2）
A = np.array([[0.5, 0.2, 0.3],
              [0.3, 0.5, 0.2],
              [0.2, 0.3, 0.5]])

# 观测概率矩阵 （观测0， 观测1）
B = np.array([[0.5, 0.5],
              [0.4, 0.6],
              [0.7, 0.3]])

# 初始状态概率向量 (集合0， 1， 2）
pi = np.array([0.2, 0.4, 0.4])

# T=3， 得到的观测序列 O = (观测0， 观测1， 观测0）
# 计算 P(O | model)
T = 3

O = np.array([0, 1, 0], dtype=int)


last_bi = np.ones(T)
for i in range((T - 2), -1, -1):

    cur_bi = np.zeros(T)
    for j in range(A.shape[0]):
        cur_bi[j] = np.sum(A[j, :] * B[:, O[i + 1]] * last_bi)
    last_bi = cur_bi.copy()

totalP = np.sum(pi * B[:, O[0]] * last_bi)
print("total probability: ", totalP)
# total probability:  0.130218



















