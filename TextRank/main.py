import pickle
import re
import os
from textrank import TextRank, KeywordRank
from tag import Tag
from seg import Seg

stop_path = os.path.join(os.path.dirname(os.path.abspath(__file__)),
                         'stopwords.txt')

stop_words = set()
with open(stop_path, 'r', encoding='utf-8') as fr:
    for line in fr:
        line = line.rstrip()
        stop_words.add(line.strip())


class Order:
    def __init__(self, text, seg=None, tagger=None):
        self.text = text
        self.tagger = tagger if tagger is not None else self.get_tagger()
        self.seg = seg if seg is not None else self.get_seg()
        self.words_merge = None

    def get_keywords(self, limit=5, merge=False):
        doc = []
        sentences = self.get_sentences()
        for sentence in sentences:
            words = list(self.seg.seg(sentence))
            words = self.filter_stop(words)
            doc.append(words)

        self.keywordrank = KeywordRank(doc)
        self.keywordrank.solve()
        result = []
        for w in self.keywordrank.top_index(limit):
            result.append(w)

        if merge:
            wm = self.words_merge.merge(self.text, result)
            return wm.merge()
        return result

    def get_summaries(self, limit=5):
        doc = []
        sentences = self.get_sentences()
        for sentence in sentences:
            words = list(self.seg.seg(sentence))
            words = self.filter_stop(words)
            doc.append(words)

        self.textrank = TextRank(doc)
        self.textrank.solve()
        result = []
        for index in self.textrank.top_index(limit):
            result.append(sentences[index])
        return result

    def get_sentences(self):
        line_break_re = re.compile('[\r\n]')
        delimiter_re = re.compile('[，。？！；]')
        sentences = []
        for line in line_break_re.split(self.text):
            line = line.strip()
            if not line:
                continue

            for sentence in delimiter_re.split(line):
                sentence = sentence.strip()
                if not sentence:
                    continue
                sentences.append(sentence)

        return sentences

    def get_seg(self, fname='seg.pickle'):
        seg = Seg()
        seg.load(fname)
        return seg

    def get_tagger(self, fname='tag.pickle'):
        tagger = Tag()
        tagger.load(fname)
        return tagger

    def filter_stop(self, words):
        return list(filter(lambda x: x not in stop_words, words))


if __name__ == '__main__':
    text = '''
    自然语言处理是计算机科学领域与人工智能领域中的一个重要方向。
    它研究能实现人与计算机之间用自然语言进行有效通信的各种理论和方法。
    自然语言处理是一门融语言学、计算机科学、数学于一体的科学。
    因此，这一领域的研究将涉及自然语言，即人们日常使用的语言，
    所以它与语言学的研究有着密切的联系，但又有重要的区别。
    自然语言处理并不是一般地研究自然语言，
    而在于研制能有效地实现自然语言通信的计算机系统，
    特别是其中的软件系统。因而它是计算机科学的一部分。
    '''
    order = Order(text)
    keywords = order.get_keywords()
    print(' '.join(keywords))

    summaries = order.get_summaries()
    print(' '.join(summaries))
