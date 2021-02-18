#!/usr/bin/python3
"""
    Method that determines if a given data set
    represents a valid UTF-8 encoding
"""


def validUTF8(data):
    i = 0

    for trav_data in data:
        tmp = 0b10000000

        if i == 0:
            while tmp & trav_data:
                i += 1
                tmp = tmp >> 1

            if i == 0:
                continue

            if i > 4 or i == 1:
                return False

        elif i > 0:
            if trav_data >> 6 != 2:
                return False

        i -= 1

    return not i
