#!/usr/bin/python3
"""
rain
"""


def rain(walls):
    i = 0
    drops = 0

    if not walls:
        return 0
    if len(walls) == 0:
        return 0
    while i <= (len(walls) - 1):
        left_wall = max(walls[:i + 1])
        right_wall = max(walls[i:])
        drops += max(min(left_wall, right_wall) - walls[i], 0)
        i += 1
    return drops
