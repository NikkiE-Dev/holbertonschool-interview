#!/usr/bin/python3
"""
rain
"""


def rain(walls):
    i = 0
    drops = 0
    collected = 0
    frt_col = 0
    back_col = 0

    if type(walls) is not list:
        return 0
    if len(walls) == 0:
        return 0
    for i in range(len(walls)):
        if walls[i] == 0:
            if i == (len(walls) - 1):
                return collected
            if frt_col > 0:
                drops += 1
        elif walls[i] > 0:
            if frt_col > 0:
                back_col = walls[i]
                if back_col >= frt_col:
                    collected += (drops * frt_col)
                else:
                    collected += (drops * back_col)
                drops = 0
                frt_col = back_col
                back_col = 0
            else:
                frt_col = walls[i]

    return collected
