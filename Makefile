ROOT=.
BUILDROOT=$(ROOT)/build
INCLUDEROOT=$(ROOT)/include
SRCROOT=$(ROOT)/src
TESTROOT=$(ROOT)/test
EDITABLE_FILES=`find $(INCLUDEROOT) $(SRCROOT) $(TESTROOT) -name *.[h,c]`

INCLUDES=-I$(INCLUDEROOT)
COG=tools/cog/scripts/cog.py
MACROIZE=tools/macroize/macroize.py
CC=clang


all: tests


tests:
	$(CC) $(INCLUDES) `find $(TESTROOT) -name *.[h,c]` -o $(BUILDROOT)/test/main

before_edit:
	$(COG) -x -r $(EDITABLE_FILES)
	$(MACROIZE) $(EDITABLE_FILES) -u

after_edit:
	$(MACROIZE) $(EDITABLE_FILES)
	$(COG) -r $(EDITABLE_FILES)

.PHONY: before_edit after_edit

clean:
	rm -rf $(BUILDROOT)/*
