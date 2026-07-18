"""common/log.py — shared leveled logging for the Python puzzle solutions.

Each solution calls :func:`get_logger` instead of ``print`` for diagnostics so
verbosity is controlled uniformly through the ``VERBOSE`` environment variable:

    python3 solution.py             # INFO  — results + high-level steps
    VERBOSE=3 python3 solution.py   # DEBUG — full trace
    VERBOSE=0 python3 solution.py   # ERROR only — quiet

``VERBOSE`` accepts either a numeric level (0=ERROR, 1=WARN, 2=INFO, 3=DEBUG)
or a standard level name (``DEBUG``, ``INFO``, ...). To use it from a sibling
directory:

    import os, sys
    sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", ".."))
    from common.log import get_logger
    log = get_logger(__name__)
"""

import logging
import os

_NUMERIC_TO_LEVEL = {
    "0": logging.ERROR,
    "1": logging.WARNING,
    "2": logging.INFO,
    "3": logging.DEBUG,
}


def _resolve_level() -> int:
    raw = os.environ.get("VERBOSE")
    if not raw:
        return logging.INFO
    raw = raw.strip()
    if raw in _NUMERIC_TO_LEVEL:
        return _NUMERIC_TO_LEVEL[raw]
    return getattr(logging, raw.upper(), logging.INFO)


def get_logger(name: str) -> logging.Logger:
    """Return a configured logger honouring the ``VERBOSE`` env var."""
    logger = logging.getLogger(name)
    if not logger.handlers:
        handler = logging.StreamHandler()
        handler.setFormatter(logging.Formatter("[%(levelname)s] %(message)s"))
        logger.addHandler(handler)
        logger.propagate = False
    logger.setLevel(_resolve_level())
    return logger
