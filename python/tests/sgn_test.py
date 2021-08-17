import sys

import pytest

from sgn import sgn


@pytest.mark.parametrize("value, expected_sign", [(0.0, 0),
                                                  (1.0, 1),
                                                  (-1.0, -1),
                                                  (500.0, 1),
                                                  (sys.float_info.max, 1),
                                                  (-sys.float_info.max, -1)])
def test_sgn_function(value, expected_sign):
    assert sgn(value) == expected_sign
