
# Simple Makefile forwarding to the build directory.

.PHONY: all gen-cmake

# Suppress the output of the forwarding of commands.
${VERBOSE}.SILENT:

all:
	make -C build $@

%:
	make -C build $@

gen-cmake:
	if [[ -d build ]]; \
	then \
		rm -rf build/*; \
	else \
		mkdir build; \
	fi
	cd build; cmake ..; cd ..
