'''
预测问题 - 近似算法

在每个时刻t选择在该时刻最有可能出现的状态 it*，
从而得到一个状态序列 I* = (i1*, i2*, ,,, it*)，将其作为预测结果
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

# 预测最可能的状态转移序列
I = np.zeros(T, dtype=int)

# 确定起始状态
max_p = 0.0
for i in range(A.shape[0]):
    cur_p = pi[i] * B[i][O[0]]
    if cur_p > max_p:
        max_p = cur_p
        I[0] = i

for i in range(1, T):
    max_p = 0.0
    for j in range(A.shape[0]):
        # last_i = I[i - 1]
        cur_p = A[j][I[i - 1]] * B[j][O[i]]

        if cur_p > max_p:
            max_p = cur_p
            I[i] = i

print(I)
