'''
向前算法

1. 初值

2. 递推

3. 终止

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

# 1. 初值
last_a_list = pi * B[:, O[0]]
# 2. 递推
for i in range(1, T):
    cur_a_list = np.array([0.0, 0.0, 0.0])

    for j in range(A.shape[0]):
        cur_a_list += last_a_list[j] * A[j, :]

    cur_a_list = cur_a_list * B[:, O[i]]

    last_a_list = cur_a_list.copy()

# 3. 终止
totalP = np.sum(last_a_list)
print("total probability: ", totalP)
# 0.130218 ≈ 0.13022
