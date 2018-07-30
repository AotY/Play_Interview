'''
分词入口文件
'''
from cbgm import CharacterBasedGenerativeModel


class Seg:
    def __init__(self):
        self.segger = CharacterBasedGenerativeModel()

    def save(self, fname):
        self.segger.save(fname)

    def load(self, fname):
        self.segger = self.segger.load(fname)

    def train(self, fname):
        datas = []
        with open(fname, 'r', encoding='utf-8') as f:
            for line in f:
                line = line.rstrip()
                if not line:
                    continue

                tmp = map(lambda x: x.split('/'), line.split())

                datas.append(tmp)

        self.segger.train(datas)

    def seg(self, sentence):
        result = self.segger.tag(sentence)

        tmp = ''
        for c, t in result:
            if t == 'e':  # end
                yield tmp + c
                tmp = ''
            elif t == 'b':  # or t == 's':  # begin or single
                if tmp:
                    yield tmp
                else:
                    tmp = c
            elif t == 's':  # single
                tmp = c
                yield tmp
                tmp = ''
            else:  # middle
                tmp += c

        if tmp:
            yield tmp


if __name__ == '__main__':
    seg = Seg()
    # seg.train(fname='/Users/LeonTao/PycharmProjects/snownlp/snownlp/seg/data.txt')
    # seg.save(fname='model.pkle')
    seg.load(fname='seg.pickle')
    print('/'.join(seg.seg('中央和国家机关首先是政治机关，必须旗帜鲜明讲政治，坚定不移加强党的全面领导，坚持不懈推进党的政治建设。')))
