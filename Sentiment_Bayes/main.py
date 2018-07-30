from sentiment import Sentiment


def load_docs(neg_file, pos_file):
    neg = open(neg_file, 'r', encoding='utf-8').readlines()
    pos = open(pos_file, 'r', encoding='utf-8').readlines()
    neg_docs = []
    pos_docs = []

    for line in neg:
        neg_docs.append(line.rstrip("\r\n"))
    for line in pos:
        pos_docs.append(line.rstrip("\r\n"))

    return neg_docs, pos_docs


if __name__ == '__main__':
    sentiment = Sentiment()
    neg_docs, pos_docs = load_docs('neg.txt', 'pos.txt')

    sentiment.train(neg_docs, pos_docs)

    text = '这个东西真心很赞'
    prob = sentiment.classify(text)

    print('prob: {}'.format(prob))
