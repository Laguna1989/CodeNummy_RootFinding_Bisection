#include "bisection.hpp"
#include "sgn.hpp"

#include <cstdlib>

double calculate_mean(double L, double U) { return (L + U) / 2.0; }

double bisect(std::function<double(double)> const& f, double L, double U, double delta)
{
    while (true) {
        auto const mean = calculate_mean(L, U);
        auto const function_value = f(mean);
        if (abs(function_value) <= delta) {
            return mean;
        }

        if (sgn(function_value) == sgn(f(L))) {
            L = mean;
        } else {
            U = mean;
        }
    }
}
