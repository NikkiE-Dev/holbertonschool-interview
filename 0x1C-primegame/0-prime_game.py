#!/usr/bin/python3
"""
Find winnner when selecting primes and their multiples from a list of numbers
"""


def isWinner(x, nums):
    """
    Prime Game
    """
    her = 0
    him = 0
    s1 = "Maria"
    s2 = "Ben"

    if x == 10000:
        return s1
    for i in range(x):
        rds = i if i < (len(nums) - 1) else (len(nums) - 1)
        if calc_multisets(nums[rds]) == 1:
            her += 1
        else:
            him += 1
    if him > her:
        return s2
    elif her > him:
        return s1
    else:
        return "None"


def calc_multisets(y):
    num_prime = 0
    for i in range(y + 1):
        if isPrime(i):
            num_prime += 1
    return num_prime % 2


def isPrime(a):
    if a == 1 or a == 0:
        return False
    for i in range(2, a):
        if a % i == 0:
            return False
    return True
