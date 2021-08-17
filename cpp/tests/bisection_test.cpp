#include "bisection.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(BisectionTest, FirstOrderPolynomial)
{
    auto const func = [](double x) { return x + 1; };

    double const L = -3;
    double const U = 5;
    double const delta = 1e-2;

    double x0 = bisect(func, L, U, delta);
    double expected_x0 = -1;
    ASSERT_LE(abs(x0 - expected_x0), 1e-2);
    ASSERT_LE(abs(func(x0)), delta);
}

TEST(BisectionTest, FirstOrderPolynomialFalling)
{
    auto const func = [](double x) { return -(x + 1); };

    double const L = -3;
    double const U = 5;
    double const delta = 1e-2;

    double x0 = bisect(func, L, U, delta);
    double expected_x0 = -1;
    ASSERT_LE(abs(x0 - expected_x0), 1e-2);
    ASSERT_LE(abs(func(x0)), delta);
}

TEST(BisectionTest, ThirdOrderPolynomial)
{
    auto const func = [](double x) { return (x - 2) * (x - 2) * (x - 2); };

    double const L = -10;
    double const U = 10;
    double const delta = 1e-8;

    double const x0 = bisect(func, L, U, delta);
    double expected_x0 = 2;

    ASSERT_LE(abs(x0 - expected_x0), 1e-2);
    ASSERT_LE(abs(func(x0)), delta);
}

TEST(BisectionTest, TranscendentFunction)
{
    auto const func = [](double x) { return cos(x) - x; };

    double const L = -1;
    double const U = 4;
    double const delta = 1e-9;

    double const x0 = bisect(func, L, U, delta);
    double expected_x0 = 0.73908513272181153;

    ASSERT_LE(abs(x0 - expected_x0), 1e-5);
    ASSERT_LE(abs(func(x0)), delta);
}

TEST(BisectionTest, BisectionWithWrongOrderOfRange)
{
    auto const func = [](double x) { return cos(x) - x; };

    double const L = 4;
    double const U = -1;
    double const delta = 1e-9;

    double const x0 = bisect(func, L, U, delta);
    double expected_x0 = 0.73908513272181153;

    ASSERT_LE(abs(x0 - expected_x0), 1e-5);
    ASSERT_LE(abs(func(x0)), delta);
}