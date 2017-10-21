
.PHONY: clean test all

all:
	cd src; make

test:
	cd test; make

clean:
	rm -f build/*
