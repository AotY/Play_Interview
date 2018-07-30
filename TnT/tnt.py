import pickle
from math import log
import heapq
from frequency import NormalProb, AddOneProb


class TnT:
    def __init__(self, THETA=1000):
        self.THETA = THETA  # Θ, each state that receives a δ value smaller that the
        # largest δ divided by some threshold value Θ=1000

        self.l1 = 0.0  # lambda 1
        self.l2 = 0.0  # lambda 2
        self.l3 = 0.0  # lambda 3

        self.status = set()

        self.wd = AddOneProb()
        self.eos = AddOneProb()
        self.eosd = AddOneProb()

        self.uni = NormalProb()
        self.bi = NormalProb()
        self.tri = NormalProb()

        self.word = {}
        self.trans = {}

    def div(self, v1, v2):
        if v2 == 0:
            return 0
        return float(v1) / v2

    def load(self, fname):
        return pickle.load(open(fname, 'rb'))

    def save(self, fname):
        pickle.dump(self, open(fname, 'wb'))

    def train(self, datas):

        for sentence in datas:
            now = ['bos', 'bos']
            self.bi.add(tuple(now), 1)
            self.uni.add(now[-1], 2)

            for word, tag in sentence:
                now.append(tag)
                self.status.add(tag)
                self.wd.add((tag, word), 1)

                self.eos.add(tuple(now[1:]), 1)
                self.eosd.add(tag, 1)

                self.uni.add(tag, 1)
                self.bi.add(tuple(now[1:]), 1)
                self.tri.add(tuple(now), 1)

                if word not in self.word:
                    self.word[word] = set()
                self.word[word].add(tag)

            self.eos.add((now[-1], 'eos'), 1)

        tl1 = 0.0
        tl2 = 0.0
        tl3 = 0.0

        for now in self.tri.samples():
            c3 = self.div(self.tri.get(now)[1] - 1, self.bi.get(now[:2])[1] - 1)
            c2 = self.div(self.bi.get(now[1:])[1] - 1, self.uni.get(now[1])[1] - 1)
            c1 = self.div(self.uni.get(now[-1])[1] - 1, self.uni.get_sum() - 1)

            if c3 >= c2 and c3 >= c1:
                tl3 += self.tri.get(now)[1]
            elif c2 >= c3 and c2 >= c1:
                tl2 += self.tri.get(now)[1]
            elif c1 >= c2 and c1 >= c3:
                tl1 += self.tri.get(now)[1]

        total_l = tl1 + tl2 + tl3
        self.l1 = self.div(tl1, total_l)
        self.l2 = self.div(tl2, total_l)
        self.l3 = self.div(tl3, total_l)

        for s1 in self.status | set(('bos',)):
            for s2 in self.status | set(('bos',)):
                for s3 in self.status:
                    uni = self.l1 * self.uni.freq(s3)
                    bi = self.div(self.l2 * self.bi.get((s2, s3))[1], self.uni.get(s2)[1])
                    tri = self.div(self.l3 * self.tri.get((s1, s2, s3))[1], self.bi.get((s1, s3))[1])

                    self.trans[(s1, s2, s3)] = log(uni + bi + tri)

    def tag(self, words):
        now = [(('bos', 'bos'), 0.0, [])]
        stage = None
        for word in words:
            stage = {}
            word_status = self.status

            if word in self.word:
                word_status = self.word[word]

            for s in word_status:
                wd = log(self.wd.get((s, word))[1]) - log(self.uni.get(s)[1])

                for pre in now:
                    p = pre[1] + wd + self.trans[(pre[0][0], pre[0][1], s)]

                    if ((pre[0][1], s) not in stage) or (p > stage[(pre[0][1], s)][0]):
                        stage[(pre[0][1], s)] = (p, pre[2] + [s])

            stage = list(map(lambda x: (x[0], x[1][0], x[1][1]), stage.items()))
            now = heapq.nlargest(self.THETA, stage, key=lambda x: x[1])
        now = heapq.nlargest(1, stage, key=lambda x: x[1] + self.get_eos(x[0][1]))

        return zip(words, now[0][-1])

    def get_eos(self, tag):
        tmp = self.eosd.get(tag)
        if not tmp[0]:
            return log(1.0 / len(self.status))
        return log(self.eos.get((tag, 'eos'))[1]) - log(self.eosd.get(tag)[1])