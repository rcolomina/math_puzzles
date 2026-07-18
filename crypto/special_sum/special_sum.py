#!/usr/bin/env python3

# Try to find out what are A,B and C
#
#   AAA
#   BBB
#  +CCC
# -----
#  BAAC
#
# Where A,B and C are distinct and positive

# The smallest solution will be (A,B,C) = (1,2,3)
# and the bigest (A,B,C = (9,8,7)

import os
import sys

# Locate the repo root (nearest ancestor holding common/) for shared logging.
_here = os.path.dirname(os.path.abspath(__file__))
_root = _here
while _root != "/" and not os.path.isdir(os.path.join(_root, "common")):
    _root = os.path.dirname(_root)
sys.path.insert(0, _root)
from common.log import get_logger

log = get_logger(__name__)

listPosSol = [[a, b, c]
              for a in range(1, 10)
              for b in range(1, 10)
              for c in range(1, 10)
              if a != b and a != c and b != c]

log.info("brute-forcing %d candidate (A,B,C) triples", len(listPosSol))

for item in listPosSol:

    a = item[0]
    b = item[1]
    c = item[2]

    log.debug("trying A=%d B=%d C=%d", a, b, c)
    if (111 * (a + b + c)) == (b * 1000 + a * 110 + c):
        log.info("solution found: (A,B,C) = (%d,%d,%d)", a, b, c)



