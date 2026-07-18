# Build the puzzle index PDF from LaTeX.
DOC := puzzles_index

.PHONY: all clean

all: $(DOC).pdf

$(DOC).pdf: $(DOC).tex
	@# three passes: body, then table of contents + hyperref anchors settle
	pdflatex -interaction=nonstopmode -halt-on-error $(DOC).tex >/dev/null
	pdflatex -interaction=nonstopmode -halt-on-error $(DOC).tex >/dev/null
	pdflatex -interaction=nonstopmode -halt-on-error $(DOC).tex >/dev/null
	@echo "built $(DOC).pdf"

clean:
	rm -f $(DOC).aux $(DOC).log $(DOC).toc $(DOC).out
