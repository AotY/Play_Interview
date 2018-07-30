'''
概率计算问题的直接计算方法

1. 列举所有可能长度的状态序列 I = (i_1, ,,, i_t)
2. 求个各个状态序列I 和 观测序列 O 的联合概率 P(O, I | model)
3. 对所有状态序列求和

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


# 遍历所有可能的状态集合
totalP = 0.0
for i in range(T):
    for j in range(T):
        for k in range(T):
            p = pi[i] * B[i][O[0]] * A[i][j] * B[j][O[1]] * A[j][k] * B[k][O[2]]
            totalP += p
print("total probability: ", totalP)
# 0.13021800000000003 ≈ 0.13022
