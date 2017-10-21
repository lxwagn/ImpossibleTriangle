
.PHONY: clean all

all:
	cd src; make
	cd test; make

clean:
	rm -f build/*
