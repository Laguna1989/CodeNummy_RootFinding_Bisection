import math

from calculate_mean import calculate_mean


def sign(value):
    return math.copysign(1, value)


def bisect(function, L, U, delta):
    while True:
        M = calculate_mean(L, U)
        vM = function(M)
        if abs(vM) < delta:
            return M

        if sign(vM) == sign(function(L)):
            L = M
        else:
            U = M
