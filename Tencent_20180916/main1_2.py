# coding: utf-8

k = int(input(""))
A = input("")
B = input("")

sub_str_A = set()

i, j = 0, k
len_A = len(A)
len_B = len(B)

# A长度为k的子串
for i in range(0, len_A - k):
    sub_str_A.add(A[i: i + k])

print(sub_str_A)

res = 0
for sub_str in sub_str_A:
    tmp_B = B
    while True:
        try:
            index_in_B = tmp_B.index(sub_str)
            res += 1
            tmp_B = tmp_B[index_in_B + 1:]
        except Exception as e:
            break
print(res)
