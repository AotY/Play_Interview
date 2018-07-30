import sys

if sys.version_info[0] == 3:
    import pickle as pkl
else:
    import cPickle as pkl

from math import log
from math import exp
from frequency import AddOneProb

class Bayes:
    def __init__(self):
        self.d = {}
        self.total = 0

    def save(self, fname):
        pkl.dump(self, open(fname, 'wb'))

    def load(self, fname):
        return pkl.load(open(fname, 'rb'))

    def train(self, datas):
        for data in datas:
            c = data[1]

            if c not in self.d:
                self.d[c] = AddOneProb() # 加一， 拉普拉斯平滑

            for word in data[0]:
                self.d[c].add(word, 1)

        self.total = sum(map(lambda x: self.d[x].get_sum(), self.d.keys()))


    def classify(self, doc):
        # 朴素贝叶斯将样本分到后验概率最大的类别中。 等价于期望风险最小化。
        tmp = {}

        for c in self.d:
            tmp[c] = log(self.d[c].get_sum()) - log(self.total)

            for word in doc:
                tmp[c] += log(self.d[c].freq(word))

        ret, prob = 0, 0

        for c1 in self.d:
            now = 0
            try:
                for c2 in self.d:
                    now += exp(tmp[c2] - tmp[c1])
                now = 1 / now
            except OverflowError:
                now = 0

            if now > prob:
                ret, prob = c1, now

        return ret, prob
