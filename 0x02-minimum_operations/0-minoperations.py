#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations
in this file: Copy All and Paste. Given a number n,
write a method that calculates the fewest number of
operations needed to result in exactly n H characters
in the file.
"""


def minOperations(n):

    """
        @n: number of H characters
        @count: minimum number of operations
        @steps: number of steps
    """
    steps = 2
    count = 0

    while n > 1:
        if n % steps == 0:
            n = n / steps
            count += steps
        else:
            steps += 1

    return count
