import pickle

from math import log

from frequency import NormalProb


class CharacterBasedGenerativeModel:
    def __init__(self):
        self.l1 = 0.0
        self.l2 = 0.0
        self.l3 = 0.0

        self.status = ('b', 'm', 'e', 's')
        self.uni = NormalProb()
        self.bi = NormalProb()
        self.tri = NormalProb()

    def save(self, fname):
        pickle.dump(self, open(fname, 'wb'))

    def load(self, fname):
        return pickle.load(open(fname, 'rb'))

    def train(self, datas):
        for sentence in datas:
            now = [('', 'bos'), ('', 'bos')]
            self.bi.add(tuple(now), 1)
            self.uni.add(now[-1], 2)
            for character, tag in sentence:
                now.append((character, tag))
                self.uni.add((character, tag), 1)
                self.bi.add(tuple(now[1:]), 1)
                self.tri.add(tuple(now), 1)
                now.pop(0)

        tl1 = 0.0
        tl2 = 0.0
        tl3 = 0.0
        # 按照次数排序
        samples = sorted(self.tri.samples(), key=lambda x: self.tri.get(x)[1])

        for now in samples:
            c3 = self.div(self.tri.get(now)[1] - 1, self.bi.get(now[:2])[1] - 1)
            c2 = self.div(self.bi.get(now[1:])[1] - 1, self.uni.get(now[1])[1] - 1)
            c1 = self.div(self.uni.get(now[2])[1] - 1, self.bi.get_sum() - 1)

            if c3 >= c2 and c3 >= c1:
                tl3 += self.tri.get(now)[1]
            elif c2 >= c1 and c2 >= c3:
                tl2 += self.tri.get(now)[1]
            elif c1 >= c2 and c1 >= c3:
                tl1 += self.tri.get(now)[1]

        total_tl = tl1 + tl2 + tl3
        self.l1 = self.div(tl1, total_tl)
        self.l2 = self.div(tl2, total_tl)
        self.l3 = self.div(tl3, total_tl)

    def div(self, v1, v2):
        if v2 == 0:
            return 0
        else:
            return float(v1) / v2

    def tag(self, sentence):
        now = [((('', 'bos'), ('', 'bos')), 0.0, [])]

        for character in sentence:
            stage = {}
            not_found = True

            for s in self.status:
                if self.uni.freq((character, s)) != 0:
                    not_found = False
                    break

            if not_found:
                for s in self.status:
                    for pre in now:
                        stage[(pre[0][1], (character, s))] = (pre[1], pre[2] + [s])

                now = list(map(lambda x: (x[0], x[1][0], x[1][1]), stage.items()))
                continue

            for s in self.status:
                for pre in now:
                    p = pre[1] + self.log_prob(pre[0][0], pre[0][1], (character, s))

                    if (not (pre[0][1], (character, s)) in stage) or (p > stage[(pre[0][1], (character, s))][0]):
                        stage[(pre[0][1], (character, s))] = (p, pre[2] + [s])

            now = list(map(lambda x: (x[0], x[1][0], x[1][1]), stage.items()))

        return zip(sentence, max(now, key=lambda x: x[1])[2])

    def log_prob(self, character1, character2, character3):
        uni = self.l1 * self.uni.freq(character3)
        bi = self.div(self.l2 * self.bi.get((character2, character3))[1], self.uni.get(character2)[1])
        tri = self.div(self.l3 * self.tri.get((character1, character2, character3))[1],
                       self.bi.get((character1, character2))[1])

        total_prob = uni + bi + tri
        if total_prob == 0:
            return float('-inf')

        return log(total_prob)
