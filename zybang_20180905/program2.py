
input_str = input("")

chinese_dict = {
    '-': '负',
    '.': '点',
    '+': '正',
    '0': '零',
    '1': '一',
    '2': '二',
    '3': '三',
    '4': '四',
    '5': '五',
    '6': '六',
    '7': '七',
    '8': '八',
    '9': '九'
}

part1_dict = {
    1: '',
    2: '十',
    3: '百',
    4: '千',
    5: '万',
    6: '十万',
    7: '百万',
    8: '千万',
    9: '亿',
    10: '十亿',
    11: '百亿',
    12: '千亿',
}

# 符号位
sign_str = ''
if input_str[0] == '-':
    sign_str = chinese_dict['-']
elif input_str[0] == '+':
    sign_str = chinese_dict['+']

# else:
#   try:
#       int(input_str[0])
#   except Exception as e:
#       print('err')
#       exit(0)

# 整数位
start_index = 0
if sign_str == '':
    # 没有符号位
    start_index = 0
else:
    start_index = 1

input_str_len = len(input_str)
size = 0
is_part2 = False
while True:
    if start_index >= input_str_len:
        break

    if input_str[start_index] == '.':
        is_part2 = True
        break
    else:
        size += 1
    start_index += 1

part1_str = input_str[start_index - size: start_index]

try:
    part1 = int(part1_str)
except Exception as e:
    print('err')
    exit(0)

# 小数点
if is_part2:

    # 小数位
    part2_str = input_str[start_index + 1: len(input_str)]

    try:
        part2 = int(part2_str)
    except Exception as e:
        print('err')
        exit(0)

res_str = ''
# 输出符号位
if sign_str != '':
    res_str += sign_str

# 输出整数部分
part1_len = len(part1_str)

for i in range(part1_len):
    cur_index = part1_len - i
    if (int(part1_str[i]) > 0):
        res_str += chinese_dict[part1_str[i]] + part1_dict[cur_index]
    else:
        if (i != part1_len - 1):
            res_str += chinese_dict[part1_str[i]]

if is_part2:
    res_str += chinese_dict['.']

    # 输出小数部分
    for i in range(len(part2_str)):
        res_str += chinese_dict[part2_str[i]]

print (res_str)