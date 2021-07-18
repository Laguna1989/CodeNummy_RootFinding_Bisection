#include "sgn.hpp"
#include <gtest/gtest.h>
#include <limits>

using namespace ::testing;

class SgnTestFixture : public ::testing::TestWithParam<std::tuple<double, int>> {
};

TEST_P(SgnTestFixture, CorrectValue)
{
    double const value = std::get<0>(GetParam());
    int const expected_sign = std::get<1>(GetParam());

    EXPECT_EQ(sgn(value), expected_sign);
}

INSTANTIATE_TEST_SUITE_P(SgnTest, SgnTestFixture,
    ::testing::Values(std::make_tuple(0.0, 0), std::make_tuple(1.0, 1), std::make_tuple(-1.0, -1),
        std::make_tuple(500.0, 1), std::make_tuple(-12.0, -1), std::make_tuple(std::numeric_limits<double>::max(), 1) , std::make_tuple(std::numeric_limits<double>::lowest(), -1) ));