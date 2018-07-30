from collections import Counter
import numpy as np
# import marshal
import pickle

class Seg:
    def __init__(self):
        self.A = {}  # tag -> tag 的概率
        self.B = {}  # tag -> character 的概率
        self.pi = {}
        self.word = {}
        self.TAGS = ['b', 'm', 'e', 's']

    def save(self, fname='seg.pkl'):
        d = {}
        d['A'] = self.A
        d['B'] = self.B
        d['pi'] = self.pi
        d['word'] = self.word
        d['TAGS'] = self.TAGS

        # marshal.dump(d, open(fname, 'wb'))
        pickle.dump(d, open(fname, 'wb'))

    def load(self, fname='seg.pkl'):
        # d = marshal.load(open(fname, 'rb'))
        d = pickle.load(open(fname, 'rb'))
        self.A = d['A']
        self.B = d['B']
        self.pi = d['pi']
        self.word = d['word']
        self.TAGS = d['TAGS']

    def train(self, datas):

        for data in datas:
            for t, tmp in enumerate(data):
                character, tag = tmp

                if not self.word.get(character):
                    self.word[character] = set()
                self.word[character].add(tag)

                # B
                if not self.B.get(tag):
                    self.B[tag] = Counter()
                self.B[tag][character] += 1

                # A
                if t < (len(data) - 2):
                    next_tag = data[t + 1][-1]
                    if not self.A.get((tag, next_tag)):
                        self.A[(tag, next_tag)] = 0
                    self.A[(tag, next_tag)] += 1

                # pi
                if t == 0:
                    if not self.pi.get(tag):
                        self.pi[tag] = 0
                    self.pi[tag] += 1

        # 归一化
        for tag in self.B.keys():
            total_count = sum(self.B[tag].values())
            for character, count in self.B[tag].items():
                self.B[tag][character] = count / total_count
        #
        total_count = sum(self.A.values())
        for (tag, next_tag), count in self.A.items():
            self.A[(tag, next_tag)] = count / total_count

        #
        total_count = sum(self.pi.values())
        for tag in self.TAGS:
            count = (self.pi.get(tag) if self.pi.get(tag) else 0)
            self.pi[tag] = count / total_count


    def viterbi(self, obs, states, start_p, trans_p, emit_p):
        V = [{}]  # tabular
        path = {}

        for y in states:  # init
            V[0][y] = start_p[y] * emit_p[y].get(obs[0], 0)
            path[y] = [y]

        for t in range(1, len(obs)):
            V.append({})
            newpath = {}
            for y in states:
                (prob, state) = max(
                    [(V[t - 1][y0] * trans_p[y0].get(y, 0) * emit_p[y].get(obs[t], 0), y0)
                     for y0 in states if V[t - 1][y0] > 0])

                V[t][y] = prob
                newpath[y] = path[state] + [y]
            path = newpath

        if emit_p['M'].get(obs[-1], 0) > emit_p['S'].get(obs[-1], 0):
            (prob, state) = max([(V[len(obs) - 1][y], y) for y in ('E', 'M')])
        else:
            (prob, state) = max([(V[len(obs) - 1][y], y) for y in states])

        return (prob, path[state])

    def tag(self, sentence):

        # 1.  初始化
        V = [{}]
        path = {}

        for tag in self.TAGS:
            V[0][tag] = (self.pi.get(tag) if self.pi.get(tag) else 0) * \
                        (self.B[tag].get(sentence[0]) if self.B[tag].get(sentence[0]) else 0)
            path[tag] = [tag]

        # 2. 递推
        for t in range(1, len(sentence)):
            V.append({})
            new_path = {}
            for tag in self.TAGS:
                (prob, prob_tag) = max(
                    [(V[t - 1][last_tag] * (self.A.get((last_tag, tag)) if self.A.get((last_tag, tag)) else 0) *
                      (self.B[tag].get(sentence[t]) if self.B[tag].get(sentence[t]) else 0), last_tag)
                     for last_tag in self.TAGS if V[t - 1][last_tag] > 0])

                V[t][tag] = prob
                new_path[tag] = path[prob_tag] + [tag]
            path = new_path

        # 3. 终止
        if (self.B['m'].get(sentence[-1]) if self.B['m'].get(sentence[-1]) else 0) > (
                self.B['s'].get(sentence[-1]) if self.B['s'].get(sentence[-1]) else 0):
            (prob, prob_tag) = max([(V[len(sentence) - 1][tag], tag) for tag in ('e', 'm')])
        else:
            (prob, prob_tag) = max([(V[len(sentence) - 1][tag], tag) for tag in self.TAGS])

        # 4. 回溯
        # return (prob, path[prob_tag])
        return zip(sentence, path[prob_tag])
