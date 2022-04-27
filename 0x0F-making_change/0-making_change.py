#!/usr/bin/python3
"""
Determine the fewest number of coins needed to meet a given amount total
"""


def makeChange(coins, amount):
    """
    Making change
    """
    temp = []
    total = []
    if amount <= 0:
        return 0
    else:
        while amount != 0:
            if len(coins) == 0:
                return -1
            if amount % max(coins) == 0:
                temp.append((max(coins), amount//max(coins)))
                amount = 0
            elif max(coins) < amount:
                temp.append((max(coins), amount//max(coins)))
                amount = amount % max(coins)
                coins.remove(max(coins))
            else:
                coins.remove(max(coins))
    for item in temp:
        total.append(item[1])
    temp = sum(total)
    return temp
