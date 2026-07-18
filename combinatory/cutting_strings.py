import itertools
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


def getSplits(myciphers):
    comb=[]    
    for split in [p for p in itertools.product([0,1], repeat=4)]:            
        tsplit=[]
        tsplit.append(myciphers[0])
        for c,s in zip(myciphers[1:],split):      
            if s == 1:
                tsplit.append("-")
            tsplit.append(c)

        comb.append("".join(tsplit))
    return comb

# Test Case 1
myciphers = "12345"
log.debug("computing splits for %s", myciphers)
log.info("%s -> %s", myciphers, getSplits(myciphers))

# Test Case 2
myciphers = "ABCD"
log.debug("computing splits for %s", myciphers)
log.info("%s -> %s", myciphers, getSplits(myciphers))
