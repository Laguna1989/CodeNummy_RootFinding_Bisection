#include "bisection.hpp"
#include "sgn.hpp"

double calculate_mean(double L, double U) { return (L + U) / 2.0; }

double bisect(std::function<double(double)> const& f, double L, double U, double delta)
{
    double const M = calculate_mean(L, U);
    double const vM = f(M);
    if (abs(vM) <= delta) {
        return M;
    }

    if (sgn(f(M)) == sgn(f(L))) {
        L = M;
    } else {
        U = M;
    }

    return bisect(f, L, U, delta);
}