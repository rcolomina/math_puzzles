# Root orchestrator for the math-puzzles collection.
#
# Topic directories are auto-discovered: any subdirectory with a Makefile that
# includes common/topic.mk is picked up here automatically (docs/ is excluded).
#
#   make            compile every C++ topic
#   make run        build, then run every solution (VERBOSE=3 for debug logs)
#   make clean      remove built binaries
#   make docs       build the LaTeX index PDF (docs/)
#   make help       list targets and discovered topics
#
# Scaffold a new puzzle with:  scripts/new_puzzle.sh <topic> <name> [cpp|py]

CPP_DIRS := $(filter-out docs,$(patsubst %/Makefile,%,$(wildcard */Makefile)))

.PHONY: all build run clean docs help

all: build

build:
	@for d in $(CPP_DIRS); do \
	  echo "==> build $$d"; \
	  $(MAKE) --no-print-directory -C $$d all || exit 1; \
	done

run:
	@for d in $(CPP_DIRS); do \
	  echo "==> run $$d"; \
	  $(MAKE) --no-print-directory -C $$d run; \
	done

clean:
	@for d in $(CPP_DIRS); do \
	  $(MAKE) --no-print-directory -C $$d clean; \
	done

docs:
	@$(MAKE) --no-print-directory -C docs

help:
	@echo "math-puzzles — build orchestrator"
	@echo ""
	@echo "Targets:"
	@echo "  make build   compile every C++ topic"
	@echo "  make run     build then run every solution (set VERBOSE=3 for debug logs)"
	@echo "  make clean   remove built binaries"
	@echo "  make docs    build the LaTeX index PDF"
	@echo ""
	@echo "Discovered topics: $(CPP_DIRS)"
