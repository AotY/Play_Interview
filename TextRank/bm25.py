from math import log


class BM25:
    def __init__(self, doc):
        self.D = len(doc)
        self.avg_dl = sum([len(sentence) + 0.0 for sentence in doc]) / self.D

        self.doc = doc
        self.f = []

        self.df = {}
        self.idf = {}

        self.k1 = 1.5
        self.b = 0.75
        self.init()

    def init(self):
        for sentence in self.doc:
            tmp = {}
            for word in sentence:
                if word not in tmp:
                    tmp[word] = 0
                tmp[word] += 1

            self.f.append(tmp)

            for k, v in tmp.items():
                if k not in self.df:
                    self.df[k] = 0

                self.df[k] += 1

        for k, v in self.df.items():
            self.idf[k] = log(self.D - v + 0.5) - log(v + 0.5)

    def sim(self, sentence, index):
        score = 0
        for word in sentence:
            if word not in self.f[index]:
                continue

            d = len(self.doc[index])
            score += (self.idf[word] * self.f[index][word] * (self.k1 + 1)
                      / (self.f[index][word] + self.k1 * (1 - self.b + self.b * d / self.avg_dl)))

        return score

    def simall(self, sentence):
        scores = []
        for index in range(self.D):
            score = self.sim(sentence, index)
            scores.append(score)
        return scores
