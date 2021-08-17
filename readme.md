# Overview

This is a Code Nummy about numerical rootfinding via bisection.  Please check out the
other [Code Nummies](https://github.com/Laguna1989/CodeNummies_Overview).

# Theory

## Rootfinding

Rootfinding is a central problem in maths. If there is no analytic solution for an equation, e.g. `x = cos(x)`, numeric
rootfinding yields an approximated solution for the equation, by solving `0 = cos(x) - x`.

## Bisection

![Bisection visualized](https://user-images.githubusercontent.com/2394228/126060781-6cc3588b-0a6c-4068-805d-134a1da7ff3d.gif)

We know that a function `f(x)` has a zero at `x0` in the range `[L;U]`. The idea of bisection is to divide the search
interval in two halves in each iteration and to discard the half that does not contain the root. The iteration cycle
will stop once a sufficient precision `delta` is reached (how far off is the function value from 0?).

1. Calculate the mean value of `L` and `U` as  `M = (L + U) / 2`
2. Check the calculated function value is close enough to zero:
   * If `abs(f(M)) <= delta` 
        * stop the iteration and use `x0 = M`
3. Check which half of the search interval to discard
    1. If `sgn(f(M)) == sgn(f(L))`
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

The first step will be to implement the calculation of the mean of two values. A function implementation can be
found in `src/calcaulate_mean` as `calculate_mean(L, U)`. It is your task to write a proper implementation.
The respective tests can be found in `tests/calculate_mean_test`.

## 2. Bisection

Now it is time for the actual bisection. replace the fake
function `bisect(function, L, U, delta)`
in `src/bisection`. The tests in `tests/bisection_test` will show you if your implementation is correct.

Feel free to test the bisection with your own  

### Hint

Note that c++ and python do unfortunately not provide a function to calculate the sign of a value. 
For this you can use the provided (and tested) template function in `src/sgn`


# Outlook and brainteasers

 * What happens, if 
    * the range `[L;U]` does not contain any zero?
    * the range `[L;U]` contains two zeros of first order? I.e. `f(x) = x*x - 2` in the range `[-2;2]`.
    * the range contains three zeros of first order? I.e. `f(x) = (x-1) * (x-1) * (x-1) - x * x +1` in the range `[-1;4]`.
    * the range contains one zero of second order? I.e. `f(x) = x * x` in the range `[-1;1]`.