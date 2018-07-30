from bayes import Bayes
from seg import Seg
import os

stop_path = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                         'stopwords.txt')

stop_words = set()
with open(stop_path, 'r', encoding='utf-8') as fr:
    for line in fr:
        line = line.rstrip()
        stop_words.add(line.strip())


class Sentiment:
    def __init__(self):
        self.classifier = Bayes()
        self.seg = Seg()
        self.seg.load('seg.pickle')

    def save(self, fname):
        self.classifier.save(fname)

    def load(self, fname):
        self.classifier = self.classifier.load(fname)

    def handle(self, doc):
        words = self.seg.seg(doc)
        words = self.filter_stop(words)

        return words

    def train(self, neg_docs, pos_docs):
        datas = []
        for doc in neg_docs:
            datas.append([self.handle(doc), 'neg'])
        for doc in pos_docs:
            datas.append([self.handle(doc), 'pos'])

        self.classifier.train(datas)

    def classify(self, doc):
        ret, prob = self.classifier.classify(self.handle(doc))
        if ret == 'pos':
            return prob
        else:
            return 1 - prob

    @staticmethod
    def filter_stop(words):
        return list(filter(lambda x: x not in stop_words, words))
