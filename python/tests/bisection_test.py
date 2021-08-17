from math import cos
from bisection import bisect


def first_order_polynomial(x):
    return x + 1.0


def test_bisection_first_order_polynomial():
    L = -3.0
    U = 5.0
    delta = 1e-2

    x0 = bisect(first_order_polynomial, L, U, delta)
    expected_x0 = -1.0
    assert abs(x0 - expected_x0) < 1e-2
    assert abs(first_order_polynomial(x0)) < delta


def first_order_polynomial_falling(x):
    return -(x + 1.0)


def test_bisection_first_order_polynomial_falling():
    L = -3.0
    U = 5.0
    delta = 1e-2

    x0 = bisect(first_order_polynomial_falling, L, U, delta)
    expected_x0 = -1.0
    assert abs(x0 - expected_x0) < 1e-2
    assert abs(first_order_polynomial_falling(x0)) < delta


def third_order_polynomial(x):
    return (x - 2) * (x - 2) * (x - 2)


def test_bisection_third_order_polynomial():
    L = -10
    U = 10
    delta = 1e-8

    x0 = bisect(third_order_polynomial, L, U, delta)
    expected_x0 = 2.0
    assert abs(x0 - expected_x0) < 1e-2
    assert abs(third_order_polynomial(x0)) < delta


def transcendent_function(x):
    return cos(x) - x


def test_bisection_transcendent_function():
    L = -1
    U = 4
    delta = 1e-9

    x0 = bisect(transcendent_function, L, U, delta)
    expected_x0 = 0.73908513272181153
    assert abs(x0 - expected_x0) < 1e-5
    assert abs(transcendent_function(x0)) < delta


def test_bisection_with_wrong_ordered_range():
    L = 4
    U = -1
    delta = 1e-9

    x0 = bisect(transcendent_function, L, U, delta)
    expected_x0 = 0.73908513272181153
    assert abs(x0 - expected_x0) < 1e-5
    assert abs(transcendent_function(x0)) < delta
