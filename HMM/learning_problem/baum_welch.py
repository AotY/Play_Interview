'''
由于监督学习（如直接使用极大似然估计）需要使用训练数据，而人工标注训练数据往往代价很高，有时就会利用非监督学习方法（如果 Baum-welch算法）

将观测序列数据看着观测数据O，状态序列数据看做不可观测的隐数据I，那么马尔科夫模型事实上是一个含有隐变量的概率模型。

1. 确定完全数据的 对数似然函数 ；
2. EM算法的E步：求Q函数；
3. EM算法的M步：极大化Q函数，求模型参数
'''
from __future__ import division
import numpy as np

# (Oi)
Os = np.array([
    1,
    0,
    0,
    1,
    1,
    1,
    0,
    0,
    0,
    0,
    1,
    0,
    1,
    0,
    0,
    1,
    0,
    1,
    1,
    1,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    1,
    1,
    0
])

T = len(Os)
A_len = 3
O_len = 2

eps = 1e-6

# 初始化
A = np.random.uniform(size=(A_len, A_len))
A = np.apply_along_axis(lambda a: (a + 1) / np.sum((a + 1)), 1, A)

B = np.random.uniform(size=(A_len, O_len))
B = np.apply_along_axis(lambda b: (b + 1) / np.sum(b), 1, B)

pi = np.random.uniform(size=A_len)
pi = (pi + 1) / np.sum((pi + 1))


# 递推

def baum_welcn(A, B, pi):
    while True:

        last_A = A.copy()
        last_B = B.copy()

        alpha, beta, gamma = forward_backward(Os)

        # update pi
        pi = gamma[0]

        txi = np.zeros(shape=(len(Os), A_len, A_len))

        for t in range(len(Os) - 1):
            for i in range(A_len):
                for j in range(A_len):
                    txi[t, i, j] = alpha[t, i] * A[i, j] * B[j, Os[t + 1]] * beta[t + 1, j]

            txi[t] = txi[t] / np.sum(txi[t])

        # update A
        for i in range(A_len):
            denominator = np.sum(gamma[:-1, i])
            for j in range(A_len):
                A[i, j] = np.sum(txi[:-1, i, j]) / denominator

        # update B
        for j in range(A_len):
            denominator = np.sum(gamma[:, j])
            for k in range(O_len):
                B[j, k] = np.sum(gamma[Os == k, j]) / denominator

        diff_A = np.max(A - last_A)
        diff_B = np.max(B - last_B)

        if diff_A < eps and diff_B < eps:
            break

        print('A: ', A)
        print('B: ', B)
        print('pi: ', pi)

    return A, B, pi


def forward_backward(Os):
    alpha = forward(Os)
    beta = backward(Os)

    gamma = np.zeros(shape=(len(Os), A_len))

    for t in range(len(Os)):
        for i in range(A_len):
            gamma[t, i] = alpha[t, i] * beta[t, i]
        gamma[t, :] = gamma[t, :] / np.sum(gamma[t, :])

    return alpha, beta, gamma


def forward(Os):
    alpha = np.zeros((len(Os), A_len))

    alpha[0, :] = pi.dot(np.diag(B[:, Os[0]]))

    for t in range(1, len(Os)):
        alpha[t, :] = alpha[t - 1, :].dot(A).dot(np.diag(B[:, Os[t]]))

    return alpha


def backward(Os):
    beta = np.zeros((len(Os), A_len))

    beta[-1] = np.ones(A_len)

    for t in range((len(Os) - 2), -1, -1):
        beta[t, :] = A.dot(np.diag(B[:, Os[t + 1]])).dot(beta[t + 1, :])

    return beta


if __name__ == '__main__':
    A, B, pi = baum_welcn(A, B, pi)

    # 终止，得到模型参数
    print('------------------------------------')
    print('A: ', A)
    print('B: ', B)
    print('pi: ', pi)
