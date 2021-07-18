# Overview

This is a Code Kata about numerical rootfinding via bisection.

# Theory

## Rootfinding

Rootfinding is a central problem in maths. If there is no analytic solution for an equation, e.g. `x = cos(x)`, numeric
rootfinding yields an approximated solution for the equation, by solving `0 = cos(x) - x`.

## Bisection

![Bisection visualized](https://user-images.githubusercontent.com/2394228/126057489-3b5fd6b2-f379-4970-a213-9be8e25124aa.gif)

We know that a function `f(x)` has a zero at `x0` in the range `[L;U]`. The idea of bisection is to discard the search
interval in two halves in each iteration and to discard the half that does not contain the root. The iteration cycle
will stop once a sufficient precision `delta` is reached.

1. Calculate the mean value of `L` and `U` as  `M = (L + U) / 2`
2. if `abs(f(M)) <= delta` stop the iteration and use `x0 = M`
3. Check which half of the search interval to discard
    1. If `sgn(f(M)) == sgn(f(L)`
        * set `L = M`
    2. Else
        * set `U = M`
4. continue at 1.

With `sgn(x)` being the sign function.

### Benefits

* Minimal knowledge about `f(x)` needed
* Constantly increases precision with each iteration
* Works also for functions that can not be expressed analytically.

### Limitations

* Works only for functions of one variable
* Comparably slow convergence.
* Does not work if zero is of even order
* Does not work if there is an even number of zeros in the range `[L;U]`

# Exercise

Let's start with implementing the bisection algorithm.

## 1. Calculation of mean values

The first step will be to implement the calculation of the mean of two values. A function function implementation can be
found in `src/bisection.cpp` as `calculate_mean(double L, double U)`. It is your task to write a proper implementation.
The respective tests can be found in `tests/bisection_calculate_mean_tests.cpp`.

## 2. Bisection

Now it is time for the actual bisection. replace the fake
function `double bisect(std::function<double(double)> const& f, double L, double U, double delta)`
in `src/bisection.cpp`. The tests in `tests/bisection_test.cpp` will show you if your implementation is correct.

Feel free to test the bisection with your own  

### Hint

Note that c++ does unfortunately not provide a function to calculate the sign of a value. For this you can use the
provided (and tested) template function in `src/sgn.hpp`
