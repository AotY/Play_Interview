# coding: utf-8

k = int(input(""))
A = input("")
B = input("")

len_A = len(A)
len_B = len(B)


class Trie:
    root = {}
    END = '#'

    def insert(self, word):
        node = self.root
        for c in word:
            node = node.setdefault(c, {})
        node[self.END] = None

    def search(self, word):
        node = self.root
        for c in word:
            if c not in node:
                return False
            node = node[c]

        return self.END in node


trie = Trie()

i, j = 0, k

while j <= len_A:
    trie.insert(A[i:j])
    i += 1
    j += 1
i, j = 0, k

res = 0
while j <= len_B:
    if trie.search(B[i:j]):
        res += 1
    i += 1
    j += 1

print(res)
