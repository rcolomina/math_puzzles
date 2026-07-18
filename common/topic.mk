# common/topic.mk — shared build rules for a puzzle *topic* directory.
#
# A topic Makefile only needs one line:
#
#     include ../common/topic.mk
#
# Sources are auto-discovered: every *.cpp in the directory builds to a binary
# of the same base name, so dropping in a new <name>.cpp needs no Makefile edit.
#
# Optional overrides (set BEFORE the include line):
#     EXTRA_CXXFLAGS := -fopenmp        # extra compiler flags for this topic
#     EXCLUDE        := broken.cpp      # sources to skip (WIP / non-compiling)
#
# Targets: all (default), run, clean.  Set VERBOSE=3 for debug-level logs.

CXX            ?= g++
CXXSTD         ?= --std=c++11
CXXWARN        ?= -Wall
EXTRA_CXXFLAGS ?=
EXCLUDE        ?=
CXXFLAGS       := $(CXXSTD) $(CXXWARN) $(EXTRA_CXXFLAGS)

SRCS := $(filter-out $(EXCLUDE),$(wildcard *.cpp))
BINS := $(SRCS:.cpp=)

.PHONY: all run clean

all: $(BINS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

run: all
	@for b in $(BINS); do \
	  echo "== ./$$b =="; \
	  ./$$b || true; \
	done

clean:
	rm -f $(BINS)
