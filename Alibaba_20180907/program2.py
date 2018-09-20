import re

# <[播]放|来>[一|几]<首|曲|个>@{singer}的<歌[曲]|[流行]音乐>
'''
<[播]放|来>[一|几]<首|曲|个>@{singer}的<歌[曲]|[流行]音乐>
来几首@{singer}的流行歌曲
'''
nlu = input("")
query = input("")

new_nlu = '('
for ch in nlu:
    if ch == '<':
        continue
    if ch == '>':
        continue
    elif ch == '[':
        new_nlu += '('
    elif ch == ']':
        new_nlu += ')'
        new_nlu += '?'

    elif ch == '|':
        new_nlu += '|'

    else:
        new_nlu += ch

new_nlu += ')'
print(nlu)
print(new_nlu)


new_nlu_re = re.compile(new_nlu)
print(new_nlu_re.match(query))