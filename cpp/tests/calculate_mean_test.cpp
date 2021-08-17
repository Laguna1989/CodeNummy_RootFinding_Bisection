#include "bisection.hpp"
#include "calculate_mean.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

class BisectionCalculateMeanTestFixture
    : public ::testing::TestWithParam<std::tuple<double, double>> {
};

TEST_P(BisectionCalculateMeanTestFixture, CalculateMean)
{
    double const L = std::get<0>(GetParam());
    double const U = std::get<1>(GetParam());

    double const expected_M = (L + U) / 2.0;

    EXPECT_DOUBLE_EQ(calculate_mean(L, U), expected_M);
}

INSTANTIATE_TEST_SUITE_P(BisectionCalculateMeanTest, BisectionCalculateMeanTestFixture,
    ::testing::Values(std::make_tuple(0.0, 1.0), std::make_tuple(0.0, 10.0),
        std::make_tuple(-10.0, 0.0), std::make_tuple(500.0, 501.0), std::make_tuple(-12.0, 12.0),
        std::make_tuple(-12.0, -10.0)));
