#!/usr/bin/env python3

##
## EPITECH PROJECT, 2021
## B-MAT-400-MAR-4-1-204ducks-franck.minassian
## File description:
## 204duck
##

import os
import sys
from math import exp
import math

average_time = float(0)
standard_deviation = float(0)
time_50 = float(0)
time_99 = float(0)
percent_1 = float(0)
percent_2 = float(0)

def print_help():
    print("USAGE\n\t./204ducks a\n\nDESCRIPTION\n\t    a       constant")

def ErrorHandling():
    global a 
    if len(sys.argv) != 2:
        print_help()
        sys.exit(84)
    if sys.argv[1] == "-h" or sys.argv[1] == "--help":
        print_help()
        sys.exit(0)
    try:
        a = float(sys.argv[1])
    except:
        print("./204ducks: Bad argument")
        sys.exit(84)
    if a < 0 or a > 2.5:
        print("./204duck: a must be between 0 and 2.5")
        sys.exit(84)

def proba(b, a, c = 0):
    if c == 0:
        proba = -a * math.exp(-b) - (4 - 3 * a) / 2 * math.exp(-2 * b) - (2 * a - 4) / 4 * math.exp(-4 * b)
    else:
        proba = a * math.exp(-b) + (4 - 3 * a) * math.exp(-2 * b) + (2 * a - 4) * math.exp(-4 * b)
    return (proba)

def get_average_time():
    average_time = float(0)
    b = float(0)

    while b < 10:
        average_time += proba(b, a, 1) * b / 1000
        b += 0.001
    return (average_time)

def get_standard_deviation(a, average_time):
    standard_dev = float(0)
    b = float(0)

    while b < 100:
        standard_dev += pow(b - average_time, 2) * proba(b, a, 1) / 1000
        b += 0.001
    return (math.sqrt(standard_dev))

def get_time_back(a, percent):
    t = 0.0

    while t < 1000:
        if proba(t / 60, a) - proba(0, a) >= percent:
            return t
        t += 0.002

def formules():
    global average_time
    global standard_deviation
    global time_50
    global time_99
    global percent_1
    global percent_2

    average_time_0 = get_average_time()
    average_time = '{0:1.0f}m {1:02.0f}s'.format(*divmod(average_time_0 * 60, 60))
    standard_deviation = round(get_standard_deviation(a, average_time_0), 3)
    time_50 = '{0:1.0f}m {1:02.0f}s'.format(*divmod(get_time_back(a, 0.5), 60))
    time_99 = '{0:1.0f}m {1:02.0f}s'.format(*divmod(get_time_back(a, 0.99), 60))
    percent_1 = round((-a * exp(-1) - (4 - 3 * a) / 2 * exp(-2 * 1) - (2 * a - 4) / 4 * exp(-4 * 1) - (-a * exp(-0) - (4 - 3 * a) / 2 * exp(-2 * 0) - (2 * a - 4) / 4 * exp(-4 * 0)))*100, 1)
    percent_2 = round((-a * exp(-2) - (4 - 3 * a) / 2 * exp(-2 * 2) - (2 * a - 4) / 4 * exp(-4 * 2) - (-a * exp(-0) - (4 - 3 * a) / 2 * exp(-2 * 0) - (2 * a - 4) / 4 * exp(-4 * 0)))*100, 1)

def Main():
    formules()
    print("Average return time: {}".format(average_time))
    print("Standard deviation: {}".format(standard_deviation))
    print("Time after which 50% of the ducks are back: {}".format(time_50))
    print("Time after which 99% of the ducks are back: {}".format(time_99))
    print("Percentage of ducks back after 1 minute: {}%".format(percent_1))
    print("Percentage of ducks back after 2 minutes: {}%".format(percent_2))

def Duck():
    ErrorHandling()
    Main()

if __name__ == '__main__':
    Duck()