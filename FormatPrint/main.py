#! /usr/bin/env python
# -*- coding: utf-8 -*-
# Copyright © 2018 LeonTao
#
# Distributed under terms of the MIT license.

"""
3[k]
kkk

3[K2[AB]]

"""


class Solution:
    def __init__(self):
        self.res_str = ''

    def format_print(self, input_str, index, cur_str):
        if input_str[index] == ']' or index > len(input_str):
            return cur_str

        # number
        tmp_index = index
        while True:
            if input_str[tmp_index].isdigit():
                tmp_index += 1
            else:
                break
        cur_num = 0
        if index != tmp_index:
            cur_num = int(input_str[index: tmp_index])

        if input_str[tmp_index] == '[':
            self.format_print(input_str, tmp_index + 1, cur_str)
        else:
            # letter
            cur_str += input_str[tmp_index] + self.format_print(input_str, tmp_index + 1, cur_str)

        if cur_num != 0 and cur_str != '':
            for i in range(cur_num):
                self.res_str += cur_str
            cur_str = self.res_str

        return cur_str


if __name__ == "__main__":
    # input_str = input("")
    input_str = '3[K2[AB]]'
    solution = Solution()
    index = 0
    solution.format_print(input_str, 0, '')
    print(solution.res_str)
