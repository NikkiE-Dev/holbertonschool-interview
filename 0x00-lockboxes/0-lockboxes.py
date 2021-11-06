#!/usr/bin/python3


"""
    n is the number of locked boxes in front of you
    @boxes is a list of lists of integers
    A key with the same number as a box opens that box
    You can assume all keys will be positive integers
    There can be keys that do not have boxes
    The first box boxes[0] is unlocked
    Return True if all boxes can be opened, else return False
"""


def canUnlockAll(boxes):
    # Code to check if all boxes can be opened
    matches = [0]
    total = len(boxes)

    if total == 0:
        return True

    for i in matches:
        for key in boxes[i]:
            if key in matches:
                continue
            else:
                matches.append(key)
    return len(matches) == total
