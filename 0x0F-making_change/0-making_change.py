#!/usr/bin/python3
"""
Determine the fewest number of coins needed to meet a given amount total
"""


def makeChange(coins, total):
    """
    Making change
    """
    num_of_coins = []
    coin_list = []
    if total <= 0:
        return 0
    else:
        while total != 0:
            if len(coins) == 0:
                return -1
            if total % max(coins) == 0:
                num_of_coins.append((max(coins), total//max(coins)))
                total = 0
            elif max(coins) < total:
                num_of_coins.append((max(coins), total//max(coins)))
                total = total % max(coins)
                coins.remove(max(coins))
            else:
                coins.remove(max(coins))
    for item in num_of_coins:
        coin_list.append(item[1])
    num_of_coins = sum(coin_list)
    return num_of_coins

