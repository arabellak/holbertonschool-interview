#!/usr/bin/python3

"""
canUnlockAll - Determines if all boxes can be opened.
boxes: list of lists.
Return: True if all boxes can be opened
        False if not.
"""


def canUnlockAll(boxes):
    """canUnlockAll - Determines if all boxes can be opened."""

    boxList = [0]
    boxUnlock = [0] * len(boxes)
    boxUnlock[0] = [1]

    if len(boxes) == 0:
        return True

    if not isinstance(boxes, list):
        return False

    while boxList:
        box = boxList.pop()
        for trav in boxes[box]:
            if trav > 0 and trav < len(boxes) and boxUnlock[trav] == 0:
                boxUnlock[trav] = 1
                boxList.append(trav)

    return all(boxUnlock)
