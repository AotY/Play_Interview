from seg import Seg

'''
1, 使用直接估计法估计HMM的参数
2，使用 viterbi 算法选择概率最大的分词序列

'''

segger = Seg()


# 澳/b 门/e 的/s 回/b 归/e 一/b 定/e 能/b 够/e 顺/b 利/e 实/b 现/e 。/s
def train(fname):
    datas = []
    i = 0
    with open(fname, 'r', encoding='utf-8') as f:
        for line in f:
            if i == 10000:
                break

            line = line.rstrip()
            if not line:
                continue

            tmp = list(map(lambda x: x.split('/'), line.split()))

            datas.append(tmp)

            i += 1

    segger.train(datas)


def seg(sentence):
    result = segger.tag(sentence)

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


def save():
    segger.save()


def load():
    segger.load()


if __name__ == '__main__':
    # train(fname='/Users/LeonTao/PycharmProjects/snownlp/snownlp/seg/data.txt')
    #
    # segger.save()


    segger.load()

    sentence = '中华民族的伟大复兴'

    words = list(seg(sentence))

    print('/'.join(words))
