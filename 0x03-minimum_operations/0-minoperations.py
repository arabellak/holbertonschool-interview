#!/usr/bin/python3
""" Minimum operations """


def minOperations(n):

    if type(n) is not int:
        return 0

    if n < 2:
        return 0

    trav = 2
    tmp = []
    while trav <= n:
        if n % trav == 0:
            tmp.append(trav)
            n = n / trav
            """trav = trav - 1"""
        else:
            trav = trav + 1
    return sum(tmp)
