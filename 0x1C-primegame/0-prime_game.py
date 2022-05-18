#!/usr/bin/python3
"""
Determine who wins when selecting primes and their multiples from a list of numbers
"""


def isWinner(x, nums):
    """
    Prime Game
    """
    s1 = "Maria"
    s2 = "Ben"
    rounds = 0

    if len(nums) == 0:
        return None
    if len(nums) == 1 and nums[0] == 1:
        return None
    for num in range(x):
        rds = num if num < len(nums) - 1 else len(nums) - 1
        if calc_multisets(nums[num]) == 1:
            rounds += 1
        else:
            rounds += 1
    if rounds % 2 == 0:
        return s2
    elif rounds % 2 == 1:
        return s1
    else:
        return None

def calc_multisets(y):
    num_prime = 0
    for i in range(y + 1):
        if isPrime(i):
            num_prime += 1
    return num_prime % 2

def isPrime(a):
    if a == 1:
        return False
    for i in range(2, a):
        if a % i == 0:
            return False
    return True