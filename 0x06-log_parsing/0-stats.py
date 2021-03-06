#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""


import sys

stat = {'200': 0, '301': 0, '400': 0, '401': 0, '403': 0,
        '404': 0, '405': 0, '500': 0}

counter = 0
size = 0

try:
    for trav in sys.stdin:
        data = trav.split()
        data = data[::-1]

        if len(data) > 2:
            counter += 1
            if counter <= 10:
                size += int(data[0])
                code = data[1]

            if code in stat.keys():
                stat[code] += 1

            if counter == 10:
                print('File size: {}'.format(size))
                for statCd, v in sorted(stat.items()):
                    if v != 0:
                        print('{}: {}'.format(statCd, v))
                counter = 0
finally:
    print('File size: {}'.format(size))
    for statCd, v in sorted(stat.items()):
        if v != 0:
            print('{}: {}'.format(statCd, v))
