#!/usr/bin/env python3

def insertion_sort(a_list):
    for i in range(1, len(a_list)):
        cur_val = a_list[i]
        cur_pos = i

        while cur_pos > 0 and a_list[cur_pos - 1] > cur_val:
            a_list[cur_pos] = a_list[cur_pos - 1]
            cur_pos = cur_pos - 1
        a_list[cur_pos] = cur_val
