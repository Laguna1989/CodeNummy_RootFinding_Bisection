import pytest

from calculate_mean import calculate_mean


@pytest.mark.parametrize("input_l, input_u", [(0.0, 1.0),
                                              (0.0, 10.0),
                                              (-10.0, 0.0),
                                              (500.0, 501.0),
                                              (0.0, 10.0),
                                              (-12.0, 12.0),
                                              (-12.0, -10.0),
                                              (1.0, 1.0)])
def test_calculate_mean(input_l, input_u):
    expected_m = (input_l + input_u) / 2.0
    assert expected_m == pytest.approx(calculate_mean(input_l, input_u))
