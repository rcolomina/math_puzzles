#!/usr/bin/env bash
#
# Scaffold a new puzzle already wired into the build + logging conventions.
#
# Usage:
#   scripts/new_puzzle.sh <topic> <name> [cpp|py]
#
# Examples:
#   scripts/new_puzzle.sh dynamic_programming knapsack cpp
#   scripts/new_puzzle.sh combinatory permutations py
#
# C++:  creates <topic>/<name>.cpp (logging-wired). If <topic> is new it also
#       drops a one-line Makefile inheriting common/topic.mk, after which
#       `make` at the repo root auto-discovers the whole topic — no Makefile or
#       root-Makefile edits are ever needed.
# Py:   creates <topic>/<name>.py wired to common.log.get_logger.
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"

die() { echo "error: $*" >&2; exit 1; }

[ $# -ge 2 ] || die "usage: $(basename "$0") <topic> <name> [cpp|py]"

TOPIC="$1"
NAME="$2"
LANG="${3:-cpp}"

case "$LANG" in
  cpp|c++) LANG="cpp" ;;
  py|python|python3) LANG="py" ;;
  *) die "unknown language '$LANG' (expected cpp or py)" ;;
esac

TOPIC_DIR="$REPO_ROOT/$TOPIC"
mkdir -p "$TOPIC_DIR"

if [ "$LANG" = "cpp" ]; then
  SRC="$TOPIC_DIR/$NAME.cpp"
  [ -e "$SRC" ] && die "$SRC already exists"

  cat > "$SRC" <<EOF
#include <iostream>

#include "../common/log.h"

using namespace std;

// TODO: describe the "$NAME" problem here.
int solution() {
    LOG_DEBUG("computing solution for $NAME");
    return 0;
}

int main() {
    int result = solution();
    LOG_INFO("$NAME result = " << result);
    cout << result << endl;
    return 0;
}
EOF

  if [ ! -e "$TOPIC_DIR/Makefile" ]; then
    printf '# %s\ninclude ../common/topic.mk\n' "$TOPIC" > "$TOPIC_DIR/Makefile"
    echo "created topic Makefile: $TOPIC/Makefile"
  fi

  if [ ! -e "$TOPIC_DIR/.gitignore" ]; then
    cat > "$TOPIC_DIR/.gitignore" <<'GITIGNORE'
# Build outputs — rebuilt by `make` (see ../common/topic.mk).
# Ignore everything, then keep sources and build files.
*
!.gitignore
!Makefile
!*.cpp
!*.h
GITIGNORE
    echo "created topic .gitignore: $TOPIC/.gitignore"
  fi

  echo "created $TOPIC/$NAME.cpp"
  echo "build/run:  make -C $TOPIC run       (VERBOSE=3 for debug logs)"

else
  SRC="$TOPIC_DIR/$NAME.py"
  [ -e "$SRC" ] && die "$SRC already exists"

  cat > "$SRC" <<EOF
#!/usr/bin/env python3
"""TODO: describe the "$NAME" problem here."""
import os
import sys

# Locate the repo root (nearest ancestor holding common/) so logging imports
# work regardless of how deeply this puzzle is nested.
_here = os.path.dirname(os.path.abspath(__file__))
_root = _here
while _root != "/" and not os.path.isdir(os.path.join(_root, "common")):
    _root = os.path.dirname(_root)
sys.path.insert(0, _root)
from common.log import get_logger

log = get_logger(__name__)


def solution():
    log.debug("computing solution for $NAME")
    return 0


if __name__ == "__main__":
    result = solution()
    log.info("$NAME result = %s", result)
    print(result)
EOF
  chmod +x "$SRC"
  echo "created $TOPIC/$NAME.py"
  echo "run:  VERBOSE=3 python3 $TOPIC/$NAME.py"
fi

echo "next:  add a subsection for this puzzle to docs/puzzles_index.tex"
