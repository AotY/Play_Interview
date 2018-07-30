'''
预测问题 - 解码（decoding ）

每一步计算复杂度都和相邻两个状态各自的节点数 的乘积成正比。
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

delta = np.zeros(shape=(T, A.shape[0]))
psi = np.zeros(shape=(T, A.shape[0]), dtype=int)

# 确定起始状态
for i in range(A.shape[0]):
    delta[0][i] = pi[i] * B[i][O[0]]

for i in range(A.shape[0]):
    psi[0][i] = 0

for i in range(1, T):
    for j in range(A.shape[0]):
        max_p = np.max(delta[i-1] * A[:, j])
        max_p = max_p * B[j][O[i]]
        delta[i][j] = max_p
        psi[i][j] = np.argmax(delta[i-1] * A[:, j])

# 回溯
P_end = np.max(delta[-1])
I[-1] = np.argmax(delta[-1])

for i in range((T - 2), -1, -1):
    I[i] = np.argmax(delta[i+1] * A[:, I[i+1]])

print('P_end: ', P_end)
print('I: ', I)
'''
P_end:  0.014699999999999998
I:  [2 2 2]
'''