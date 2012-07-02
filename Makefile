
# Simple Makefile forwarding to the build directory.

all:
	make -C build $@

%:
	make -C build $@
