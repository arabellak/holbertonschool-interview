#!/usr/bin/python3
"""
Rain
"""


def aqua(arr, n):
    """
    Help calculate how much aqua will be retained
    Arguments:
     - arr list of non-negative integers representing walls of width 1
     - n length of the list
    Returns:
     max_w How much rain will be retained
    """
    max_w = 0

    for i in range(1, n - 1):
        # First find the max element in the left
        left = arr[i]
        for j in range(i):
            left = max(left, arr[j])

        # Then find the max element in the right
        right = arr[i]
        for j in range(i + 1, n):
            right = max(right, arr[j])

        # Save the max rain
        max_w = max_w + (min(left, right) - arr[i])

    return max_w


def rain(walls):
    """
    Calculate how much rain will be retained after it rains.
    Return:
     - Integer indicating total amount of rain retained.
    """
    retained = aqua(walls, len(walls))
    return retained
