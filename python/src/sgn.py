import math


def sgn(value):
    if value == 0:
        return 0
    return math.copysign(1, value)