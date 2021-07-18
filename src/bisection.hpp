#ifndef IMPLEMENTATION_HPP_GUARD
#define IMPLEMENTATION_HPP_GUARD

#include <functional>

double calculate_mean(double L, double U);

double bisect(std::function<double(double)> const& f, double L, double U, double delta);

#endif