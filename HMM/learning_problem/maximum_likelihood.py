'''
已给训练数据包含S个长度相同的观测序列和对应的状态序列，
{ (O1, I1), ,,, (Os, Is) }，那么可以利用极大似然估计方法
来估计隐马尔科夫模型的参数。

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
'''

import numpy as np

T = 3
A_len = 3
O_len = 2

# (Oi, Ii)
datas = [
    (0, 0),
    (0, 1),
    (1, 1),
    (1, 0),
    (1, 2),
    (0, 2),
    (0, 1),
    (0, 1),
    (0, 2),
    (1, 1),
    (0, 2),
    (1, 1),
    (0, 1),
    (0, 0),
    (1, 1),
    (0, 1),
    (1, 1),
    (1, 0),
    (1, 2),
    (0, 2),
    (0, 1),
    (0, 1),
    (0, 0),
    (1, 1),
    (0, 2),
    (0, 1),
    (0, 1),
    (0, 0),
    (1, 1),
    (1, 2),
    (0, 2)
]

A = np.zeros(shape=(A_len, A_len))

B = np.zeros(shape=(A_len, O_len))

pi = np.zeros(shape=A_len)

# aij t时刻为i转移到t+1时刻为j的频数，bj(k) 状态为j 并观测为k的频数
for t, data in enumerate(datas):
    Oi = data[0]
    Ii = data[1]
    pi[Ii] += 1  # 统计初始概率
    if (t + 1) < len(datas):
        Ij = datas[t + 1][1]  # t+1
        A[Ii][Ij] += 1
    B[Ii][Oi] += 1

# 归一化，需要涉及到平滑问题 （拉普拉斯平滑）
A = np.apply_along_axis(lambda a: (a + 1) / np.sum((a + 1)), axis=1, arr=A)
B = np.apply_along_axis(lambda b: (b + 1) / np.sum((b + 1)), axis=1, arr=B)
pi = pi / np.sum(pi)

print('A: ', A)
print('B: ', B)
print('pi: ', pi)
