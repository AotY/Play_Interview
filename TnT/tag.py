from tnt import TnT


class Tag:
    def __init__(self):
        self.tagger = TnT()

    def load(self, fname):
        self.tagger = self.tagger.load(fname)

    def save(self, fname):
        self.tagger.save(fname)

    def train(self, fname):
        datas = []
        with open(fname, 'r', encoding='utf-8') as f:
            for line in f:
                line = line.rstrip()
                tmp = list(map(lambda x: x.split('/'), line.split()))
                datas.append(tmp)

        self.tagger.train(datas)

    def tag(self, words):
        return self.tagger.tag(words)


if __name__ == '__main__':
    tag = Tag()
    # tag.train('/Users/LeonTao/PycharmProjects/snownlp/snownlp/tag/199801.txt')
    # tag.save('tag.pickle')
    tag.load('tag.pickle')
    words = [u'这个', u'东西', u'真心', u'很', u'赞']
    for i in zip(words, tag.tag(words)):
        print('word: {}, tag: {}'.format(i[0], i[1]))
